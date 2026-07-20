#include <iostream>
#include <stdexcept>

class Queue {
private:
    // A single node in the linked list
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* frontNode; // Points to the front of the queue (where we dequeue)
    Node* rearNode;  // Points to the back of the queue (where we enqueue)
    int queueSize;   // Tracks the number of elements

public:
    Queue() : frontNode(nullptr), rearNode(nullptr), queueSize(0) {}

    // Clean up memory when the queue is destroyed
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Insert an element at the back of the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        queueSize++;
    }

    // Remove the element from the front of the queue
    void dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue Underflow: Cannot dequeue from an empty queue.");
        }
        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        
        // If the queue is now empty, reset rearNode as well
        if (frontNode == nullptr) {
            rearNode = nullptr;
        }
        queueSize--;
    }

    // Get the front element without removing it
    int peek() const {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty: No front element.");
        }
        return frontNode->data;
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return frontNode == nullptr;
    }

    // Get the current number of elements
    int size() const {
        return queueSize;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Front element: " << q.peek() << std::endl; // Outputs 10
    std::cout << "Queue size: " << q.size() << std::endl;   // Outputs 3

    q.dequeue();
    std::cout << "Front element after dequeue: " << q.peek() << std::endl; // Outputs 20

    return 0;
}
