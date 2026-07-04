#include <iostream>
#include <algorithm>

using namespace std;

// An AVL tree node
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        key = val;
        left = nullptr;
        right = nullptr;
        height = 1; // New node is initially added at leaf level
    }
};

// Utility function to get the height of the tree
int getHeight(Node* node) {
    if (node == nullptr) return 0;
    return node->height;
}

// Utility function to get the Balance Factor of a node
int getBalanceFactor(Node* node) {
    if (node == nullptr) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Right Rotate utility (used for LL imbalance)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    // Return new root
    return x;
}

// Left Rotate utility (used for RR imbalance)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // Return new root
    return y;
}

// Recursive function to insert a key and balance the tree
Node* insert(Node* node, int key) {
    // 1. Perform the normal BST insertion
    if (node == nullptr) {
        return new Node(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        return node; // Duplicate keys are not allowed in this BST implementation
    }

    // 2. Update height of this ancestor node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // 3. Get the balance factor to check if it became unbalanced
    int balance = getBalanceFactor(node);

    // If unbalanced, then there are 4 cases:

    // Case 1: Left-Left (LL Case)
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    // Case 2: Right-Right (RR Case)
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    // Case 3: Left-Right (LR Case)
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Case 4: Right-Left (RL Case)
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the (unchanged) node pointer
    return node;
}

// Print the tree in-order (Should always display sorted output)
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " (H:" << root->height << ") ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    /* Constructing tree given in the above figure */
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Inorder traversal of the constructed AVL tree is: \n";
    inorder(root);
    cout << endl;
    cout << "Height of the tree is: " << getHeight(root) << endl; // Display the height of the root node
    cout << endl;

    return 0;
}
