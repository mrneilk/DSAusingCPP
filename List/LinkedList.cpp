#include <iostream>

// Define the structure of a single node
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // 1. Insert at the beginning
    void insertAtFront(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // 2. Insert at the end
    void insertAtBack(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // 3. Delete a node by value
    void deleteNode(int val) {
        if (!head) return;

        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != val) {
            temp = temp->next;
        }

        if (temp->next) {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
    }

    // 4. Display the list
    void display() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }

    // Destructor to prevent memory leaks
    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    list.insertAtBack(10);
    list.insertAtBack(20);
    list.insertAtFront(5);
    
    std::cout << "Current List: ";
    list.display(); // Output: 5 -> 10 -> 20 -> NULL

    list.deleteNode(10);
    std::cout << "After deleting 10: ";
    list.display(); // Output: 5 -> 20 -> NULL

    return 0;
}
