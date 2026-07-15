#include <vector>
#include <iostream>

template <typename T>
void insertionSort(std::vector<T>& arr) {
    const size_t n = arr.size();
    if (n <= 1) return;

    for (size_t i = 1; i < n; ++i) {
        T key = arr[i];
        int j = static_cast<int>(i) - 1;

        // Move elements of arr[0..i-1] that are greater than the key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main() {
    std::vector<int> data = {12, 11, 13, 5, 6};
    
    insertionSort(data);

    for (int val : data) {
        std::cout << val << " ";
    }
    std::cout << "\n"; // Output: 5 6 11 12 13
    return 0;
}
