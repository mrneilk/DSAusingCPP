// This file is a c++ program with menues for operations in Arrays
#include <iostream>

using namespace std;

// Maximum capacity of the array
const int MAX = 100;

void displayMenu() {
    cout << "\n--- Array CRUD Operations ---" << endl;
    cout << "1. Insert Element" << endl;
    cout << "2. Display Array" << endl;
    cout << "3. Update Element" << endl;
    cout << "4. Delete Element" << endl;
    cout << "5. Search Element" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int arr[MAX];
    int size = 0; // Current number of elements
    int choice, value, index;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: // Create / Insert
                if (size >= MAX) {
                    cout << "Error: Array is full!" << endl;
                } else {
                    cout << "Enter value to insert: ";
                    cin >> value;
                    arr[size] = value;
                    size++;
                    cout << "Element inserted successfully." << endl;
                }
                break;

            case 2: // Read / Display
                if (size == 0) {
                    cout << "Array is empty." << endl;
                } else {
                    cout << "Current Array: ";
                    for (int i = 0; i < size; i++) {
                        cout << arr[i] << " ";
                    }
                    cout << endl;
                }
                break;

            case 3: // Update
                cout << "Enter index to update (0 to " << size - 1 << "): ";
                cin >> index;
                if (index >= 0 && index < size) {
                    cout << "Enter new value: ";
                    cin >> value;
                    arr[index] = value;
                    cout << "Element updated." << endl;
                } else {
                    cout << "Invalid index!" << endl;
                }
                break;

            case 4: // Delete
                cout << "Enter index to delete (0 to " << size - 1 << "): ";
                cin >> index;
                if (index >= 0 && index < size) {
                    // Shift elements to the left to fill the gap
                    for (int i = index; i < size - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    size--;
                    cout << "Element deleted." << endl;
                } else {
                    cout << "Invalid index!" << endl;
                }
                break;

            case 5: // Search
                cout << "Enter value to search: ";
                cin >> value;
                index = -1;
                for (int i = 0; i < size; i++) {
                    if (arr[i] == value) {
                        index = i;
                        break;
                    }
                }
                if (index != -1)
                    cout << "Element found at index " << index << endl;
                else
                    cout << "Element not found." << endl;
                break;

            case 6:
                cout << "Exiting program..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
