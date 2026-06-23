#include <cstdint>
#include <cstring>
#include <immintrin.h> // For SSE/AVX SIMD intrinsics

enum class NodeType : uint8_t { Node4, Node16, Node48, Node256 };

// Base header to save space; fits easily within a cache line
struct NodeHeader {
    NodeType type;
    uint16_t num_children = 0;
    // Optional: Prefix compression metadata can go here
};

struct Node4 : public NodeHeader {
    uint8_t keys[4];
    NodeHeader* children[4];
    
    Node4() { type = NodeType::Node4; std::memset(keys, 0, 4); }
};

struct Node16 : public NodeHeader {
    uint8_t keys[16];
    NodeHeader* children[16];
    
    Node16() { type = NodeType::Node16; std::memset(keys, 0, 16); }
};

struct Node48 : public NodeHeader {
    // Maps a byte value (0-255) to an index (0-47) in the children array
    // 256 means empty/no child
    uint8_t child_index[256]; 
    NodeHeader* children[48];
    
    Node48() {
        type = NodeType::Node48;
        std::memset(child_index, 256, 256); // 256 acts as a sentinel invalid index
    }
};

struct Node256 : public NodeHeader {
    NodeHeader* children[256];
    
    Node256() {
        type = NodeType::Node256;
        std::memset(children, 0, sizeof(children));
    }
};
