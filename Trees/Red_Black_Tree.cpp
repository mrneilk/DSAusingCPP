#include <iostream>

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node* root;

    // Helper functions for rotations
    void rotateLeft(Node*& x) {
        Node* y = x->right;
        x->right = y->left;

        if (y->left != nullptr)
            y->left->parent = x;

        y->parent = x->parent;

        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    void rotateRight(Node*& x) {
        Node* y = x->left;
        x->left = y->right;

        if (y->right != nullptr)
            y->right->parent = x;

        y->parent = x->parent;

        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->right = x;
        x->parent = y;
    }

    // Fixes violations caused by insertion
    void fixViolation(Node*& curr) {
        Node* parent = nullptr;
        Node* grandparent = nullptr;

        while ((curr != root) && (curr->color != BLACK) && (curr->parent->color == RED)) {
            parent = curr->parent;
            grandparent = curr->parent->parent;

            // Case A: Parent of curr is Left child of Grandparent
            if (parent == grandparent->left) {
                Node* uncle = grandparent->right;

                // Case 1: Uncle is also RED (Only Recoloring needed)
                if (uncle != nullptr && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    curr = grandparent;
                } else {
                    // Case 2: curr is Right child of its parent (Left-Right Case)
                    if (curr == parent->right) {
                        rotateLeft(parent);
                        curr = parent;
                        parent = curr->parent;
                    }
                    // Case 3: curr is Left child of its parent (Left-Left Case)
                    rotateRight(grandparent);
                    std::swap(parent->color, grandparent->color);
                    curr = parent;
                }
            }
            // Case B: Parent of curr is Right child of Grandparent
            else {
                Node* uncle = grandparent->left;

                // Case 1: Uncle is also RED
                if ((uncle != nullptr) && (uncle->color == RED)) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    curr = grandparent;
                } else {
                    // Case 2: curr is Left child of its parent (Right-Left Case)
                    if (curr == parent->left) {
                        rotateRight(parent);
                        curr = parent;
                        parent = curr->parent;
                    }
                    // Case 3: curr is Right child of its parent (Right-Right Case)
                    rotateLeft(grandparent);
                    std::swap(parent->color, grandparent->color);
                    curr = parent;
                }
            }
        }
        root->color = BLACK; // Property 2: Root must be black
    }

    void inorderTraversal(Node* root) {
        if (root == nullptr) return;
        inorderTraversal(root->left);
        std::cout << root->data << " (" << (root->color == RED ? "R" : "B") << ") ";
        inorderTraversal(root->right);
    }

public:
    RedBlackTree() : root(nullptr) {}

    void insert(const int& data) {
        Node* curr = new Node(data);
        if (root == nullptr) {
            curr->color = BLACK;
            root = curr;
            return;
        }

        // Standard BST Insertion
        Node* parent = nullptr;
        Node* temp = root;
        while (temp != nullptr) {
            parent = temp;
            if (curr->data < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }

        curr->parent = parent;
        if (curr->data < parent->data)
            parent->left = curr;
        else
            parent->right = curr;

        // Fix potential Red-Black Tree rule breakages
        fixViolation(curr);
    }

    void display() {
        inorderTraversal(root);
        std::cout << "\n";
    }
};

int main() {
    RedBlackTree tree;

    tree.insert(7);
    tree.insert(3);
    tree.insert(18);
    tree.insert(10);
    tree.insert(22);
    tree.insert(8);
    tree.insert(11);

    std::cout << "Inorder Traversal of Created Tree:\n";
    tree.display();

    return 0;
}
