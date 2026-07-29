// Menu driven stack program
#include <iostream>

#define MAX 5 // Maximum size of the stack

class Stack {
    int top;
    int arr[MAX];

public:
    Stack() { 
        top = -1; // Initialize stack as empty
    }

    // Add an element to the top of the stack
    bool push(int x) {
        if (top >= (MAX - 1)) {
            std::cout << "Stack Overflow! Cannot push " << x << ".\n";
            return false;
        } else {
            arr[++top] = x;
            std::cout << x << " pushed into stack.\n";
            return true;
        }
    }

    // Remove and return the top element
    int pop() {
        if (top < 0) {
            std::cout << "Stack Underflow! The stack is empty.\n";
            return 0;
        } else {
            int x = arr[top--];
            return x;
        }
    }

    // Return the top element without removing it
    int peek() {
        if (top < 0) {
            std::cout << "Stack is empty.\n";
            return 0;
        } else {
            return arr[top];
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return (top < 0);
    }

    // Display all elements in the stack
    void display() {
        if (top < 0) {
            std::cout << "Stack is empty.\n";
            return;
        }
        std::cout << "Stack elements (Top to Bottom):\n";
        for (int i = top; i >= 0; i--) {
            std::cout << "| " << arr[i] << " |\n";
        }
        std::cout << "-----\n";
    }
};

int main() {
    Stack s;
    int choice, val;

    std::cout << "=== Stack Implementation (Max Size: " << MAX << ") ===\n";

    do {
        std::cout << "\n--- MENU ---\n";
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Peek (Top element)\n";
        std::cout << "4. Check if Empty\n";
        std::cout << "5. Display Stack\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice (1-6): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to push: ";
                std::cin >> val;
                s.push(val);
                break;
            case 2:
                val = s.pop();
                if (val != 0) {
                    std::cout << "Popped value: " << val << "\n";
                }
                break;
            case 3:
                val = s.peek();
                if (val != 0) {
                    std::cout << "Top element is: " << val << "\n";
                }
                break;
            case 4:
                if (s.isEmpty()) {
                    std::cout << "Yes, the stack is empty.\n";
                } else {
                    std::cout << "No, the stack has elements.\n";
                }
                break;
            case 5:
                s.display();
                break;
            case 6:
                std::cout << "Exiting program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice! Please select a valid option.\n";
        }
    } while (choice != 6);

    return 0;
}
