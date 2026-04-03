#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Node Structure
struct Node {
    bool isLeaf;
    vector<int> keys;
    vector<Node*> children; // For internal nodes
    vector<string> values;  // For leaf nodes (simulating data)
    Node* next;             // For leaf node linking

    Node(bool leaf) : isLeaf(leaf), next(nullptr) {}   
};

class BPlusTree {
    Node* root;
    int order;

public:
    BPlusTree(int _order) : order(_order) {
        root = new Node(true);
    }

    // 1. READ Operation
    string read(int key) {
        Node* curr = root;
        while (!curr->isLeaf) {
            curr = curr->children[upper_bound(curr->keys.begin(), curr->keys.end(), key) - curr->keys.begin()];
        }

        for (int i = 0; i < curr->keys.size(); i++) {
            if (curr->keys[i] == key) return curr->values[i];
        }
        return "Not Found";
    }

    // 2. UPDATE Operation
    bool update(int key, string newValue) {
        Node* curr = root;
        while (!curr->isLeaf) {
            curr = curr->children[upper_bound(curr->keys.begin(), curr->keys.end(), key) - curr->keys.begin()];
        }

        for (int i = 0; i < curr->keys.size(); i++) {
            if (curr->keys[i] == key) {
                curr->values[i] = newValue;
                return true;
            }
        }
        return false;
    }

    // 3. WRITE (INSERT) Operation - Simplified
    void insert(int key, string value) {
        Node* curr = root;
        
        // Find the leaf node
        while (!curr->isLeaf) {
            int idx = upper_bound(curr->keys.begin(), curr->keys.end(), key) - curr->keys.begin();
            curr = curr->children[idx];
        }

        // Insert into leaf
        auto it = lower_bound(curr->keys.begin(), curr->keys.end(), key);
        int idx = distance(curr->keys.begin(), it);
        
        curr->keys.insert(it, key);
        curr->values.insert(curr->values.begin() + idx, value);

        // Logic for splitting would go here if curr->keys.size() == order
        if (curr->keys.size() == order) {
            // Note: Full split logic involves creating a new node and updating parent
            cout << "Node full! (Split logic required for full implementation)" << endl;
        }
    }
};

int main() {
    BPlusTree tree(3);

    // Write
    tree.insert(10, "Database_Record_A");
    tree.insert(20, "Database_Record_B");

    // Read
    cout << "Key 10: " << tree.read(10) << endl;
    cout << "Key 20: " << tree.read(20) << endl;

    // Update
    tree.update(10, "Updated_Record_A");
    cout << "Key 10 (after update): " << tree.read(10) << endl;
    cout << "Key 20: "<< tree.read(20) << endl;

    return 0;
}