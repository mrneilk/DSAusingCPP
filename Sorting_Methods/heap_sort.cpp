#include <iostream>
#include <vector>
#include <algorithm>

// Restores the Max-Heap property for a subtree rooted at index 'i'
// 'n' is the current effective size of the heap
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2; // Right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If the largest element is not the root, swap and continue heapifying down
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to perform Heap Sort
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Step 1: Build the Max-Heap
    // Start from the last non-leaf node (n/2 - 1) and work up to the root (0)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Step 2: Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move the current root (maximum element) to the end of the array
        std::swap(arr[0], arr[i]);

        // Call heapify on the reduced heap to restore order at the root
        heapify(arr, i, 0);
    }
}

// Helper function to print the vector
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> data = {12, 11, 13, 5, 6, 7};
    
    std::cout << "Original array: ";
    printArray(data);

    heapSort(data);

    std::cout << "Sorted array:   ";
    printArray(data);

    return 0;
}
