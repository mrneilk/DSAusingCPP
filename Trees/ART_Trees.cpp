#include <iostream>
#include <cstdint>
#include <cstring>
#include <immintrin.h> // For SSE/SIMD

enum class NodeType : uint8_t { Node4, Node16 };

// Base Node Header
struct Node {
    NodeType type;
    uint16_t count;

    Node(NodeType t) : type(t), count(0) {}
};

// Node that holds up to 4 children
struct Node4 : public Node {
    uint8_t keys[4];
    Node* children[4];

    Node4() : Node(NodeType::Node4) {
        std::memset(keys, 0, sizeof(keys));
        std::memset(children, 0, sizeof(children));
    }
};

// Node that holds up to 16 children (SIMD optimized)
struct Node16 : public Node {
    uint8_t keys[16];
    Node* children[16];

    Node16() : Node(NodeType::Node16) {
        std::memset(keys, 0, sizeof(keys));
        std::memset(children, 0, sizeof(children));
    }
};

// --- Helper: Search in Node16 using SIMD ---
Node* searchNode16(Node16* n, uint8_t key) {
    __m128i all_keys = _mm_loadu_si128((__m128i*)n->keys);
    __m128i target = _mm_set1_epi8(key);
    int mask = _mm_movemask_epi8(_mm_cmpeq_epi8(all_keys, target));

    // Mask bits correspond to matching keys
    if (mask & ((1 << n->count) - 1)) {
        int index = __builtin_ctz(mask);
        return n->children[index];
    }
    return nullptr;
}

// --- The Transition: Node4 to Node16 ---
Node* upgradeToNode16(Node4* oldNode, uint8_t newKey, Node* newChild) {
    Node16* newNode = new Node16();
    
    // Copy existing data
    for (int i = 0; i < oldNode->count; i++) {
        newNode->keys[i] = oldNode->keys[i];
        newNode->children[i] = oldNode->children[i];
    }
    newNode->count = oldNode->count;

    // Add the new element
    newNode->keys[newNode->count] = newKey;
    newNode->children[newNode->count] = newChild;
    newNode->count++;

    delete oldNode; // In production, use a custom pool allocator
    return newNode;
}

int main() {
    // Start with a Node4
    Node4* root = new Node4();
    root->keys[0] = 'a'; root->count++;
    root->keys[1] = 'b'; root->count++;
    root->keys[2] = 'c'; root->count++;
    root->keys[3] = 'd'; root->count++;

    std::cout << "Node4 full. Current count: " << (int)root->count << std::endl;

    // Trigger upgrade on 5th insert
    Node* newRoot = upgradeToNode16(root, 'e', nullptr);

    if (newRoot->type == NodeType::Node16) {
        std::cout << "Successfully upgraded to Node16! New count: " << (int)newRoot->count << std::endl;
    }

    return 0;
}
