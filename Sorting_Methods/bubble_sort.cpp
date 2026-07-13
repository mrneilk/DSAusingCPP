
#include <iostream>
#include <vector>

// Function to perform Bubble Sort
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    
    // Loop through the entire array
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        
        // Last i elements are already in place, so we don't need to check them
        for (int j = 0; j < n - i - 1; j++) {
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                // Swap if they are in the wrong order
                std::swap(arr[j], arr[j + 1]);
                swapped = true; 
            }
        }
        
        // Optimization: If no two elements were swapped in the inner loop, break
        if (!swapped) {
            break;
        }
    }
}

// Helper function to print the array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> data = {64, 34, 25, 12, 22, 11, 90};
    
    std::cout << "Original array: ";
    printArray(data);
    
    bubbleSort(data);
    
    std::cout << "Sorted array:   ";
    printArray(data);
    
    return 0;
}
