#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

class MaxHeap {
private:
    std::vector<int> heap;

    // Helper functions to get indices
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i) + 1; }
    int rightChild(int i) { return (2 * i) + 2; }

    // Moves the element at index i up to its correct position
    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            std::swap(heap[parent(i)], heap[i]);
            i = parent(i); // Move up to the parent's index
        }
    }

    // Moves the element at index i down to its correct position
    void heapifyDown(int i) {
        int maxIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);

        // Check if left child is larger than current max
        if (left < heap.size() && heap[left] > heap[maxIndex]) {
            maxIndex = left;
        }

        // Check if right child is larger than current max
        if (right < heap.size() && heap[right] > heap[maxIndex]) {
            maxIndex = right;
        }

        // If the largest element is not the parent, swap and continue down
        if (i != maxIndex) {
            std::swap(heap[i], heap[maxIndex]);
            heapifyDown(maxIndex);
        }
    }

public:
    // Insert a new element into the heap
    void insert(int key) {
        heap.push_back(key);      // Insert at the end
        heapifyUp(heap.size() - 1); // Restore heap property
    }

    // Extract the maximum element (the root)
    int extractMax() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty!");
        }

        int maxVal = heap[0];
        
        // Move the last element to the root and remove the last element
        heap[0] = heap.back();
        heap.pop_back();

        // Restore heap property from the root down
        if (!heap.empty()) {
            heapifyDown(0);
        }

        return maxVal;
    }

    // Get the maximum element without removing it
    int getMax() const {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty!");
        }
        return heap[0];
    }

    // Returns the current size of the heap
    size_t size() const {
        return heap.size();
    }

    // Utility function to print the heap array
    void printHeap() const {
        for (int val : heap) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    MaxHeap maxHeap;

    // Testing Insertion
    std::cout << "Inserting: 40, 20, 30, 10, 50\n";
    maxHeap.insert(40);
    maxHeap.insert(20);
    maxHeap.insert(30);
    maxHeap.insert(10);
    maxHeap.insert(50);

    std::cout << "Current Heap Array: ";
    maxHeap.printHeap(); // Root (50) should be at index 0

    std::cout << "Maximum element: " << maxHeap.getMax() << "\n\n";

    // Testing Extraction
    std::cout << "Extracted Max: " << maxHeap.extractMax() << "\n";
    std::cout << "Heap Array after extraction: ";
    maxHeap.printHeap();

    std::cout << "Extracted Max: " << maxHeap.extractMax() << "\n";
    std::cout << "Heap Array after extraction: ";
    maxHeap.printHeap();

    return 0;
}
