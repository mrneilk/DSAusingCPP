#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// The degree M determines the fan-out
const int M = 4; 

struct Node {
    bool isLeaf;
    vector<int> keys;
    vector<Node*> pointers; // For internal: points to Nodes. For leaf: points to data/next leaf.
    Node* next; // Linked list pointer for leaf nodes

    Node(bool leaf) : isLeaf(leaf), next(nullptr) {}
};

class BPlusTree {
    Node* root;

public:
    BPlusTree() { root = new Node(true); }

    // Core Search: O(log M N)
    Node* search(int key) {
        Node* cursor = root;
        while (!cursor->isLeaf) {
            for (int i = 0; i < cursor->keys.size(); i++) {
                if (key < cursor->keys[i]) {
                    cursor = cursor->pointers[i];
                    break;
                }
                if (i == cursor->keys.size() - 1) {
                    cursor = cursor->pointers[i + 1];
                    break;
                }
            }
        }
        return cursor;
    }

    void insert(int key) {
        Node* leaf = search(key);
        
        // Simplified Insertion Logic:
        leaf->keys.push_back(key);
        sort(leaf->keys.begin(), leaf->keys.end());

        if (leaf->keys.size() >= M) {
            // In a full implementation, you would trigger 
            // splitChild(leaf) here to maintain balance.
            handleSplit(leaf);
        }
    }

private:
    void handleSplit(Node* oldNode) {
        // 1. Create a new sibling node
        // 2. Distribute keys between oldNode and newNode
        // 3. If oldNode was root, create a new root
        // 4. Else, insert the middle key into the parent
    }
};
