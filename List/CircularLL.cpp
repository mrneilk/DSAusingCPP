#include <iostream>

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class CircularList {
private:
    Node* tail;

public:
    CircularList() : tail(nullptr) {}

    // 1. Insert into an empty list or at the beginning
    void insertFront(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }

    // 2. Insert at the end
    void insertEnd(int val) {
        insertFront(val);
        tail = tail->next; // The new node becomes the new tail
    }

    // 3. Traversal
    void display() {
        if (!tail) return;

        Node* temp = tail->next; // Start at the head
        do {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        std::cout << "(back to start)" << std::endl;
    }

    // 4. Delete a node by value
    void deleteNode(int key) {
        if (!tail) return;

        Node *curr = tail->next, *prev = tail;
        bool found = false;

        // Handle single node case
        if (curr == tail && curr->data == key) {
            delete curr;
            tail = nullptr;
            return;
        }

        // Search for the node
        do {
            if (curr->data == key) {
                prev->next = curr->next;
                if (curr == tail) tail = prev; // Update tail if last node deleted
                delete curr;
                found = true;
                break;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != tail->next);
    }
};

int main() {
    CircularList list;
    list.insertEnd(10);
    list.insertEnd(20);
    list.insertFront(5);
    
    std::cout << "Circular List: ";
    list.display();

    list.deleteNode(20);
    std::cout << "After deleting 20: ";
    list.display();

    return 0;
}
