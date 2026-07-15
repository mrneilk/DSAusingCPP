#include <vector>
#include <iostream>

// The template function allows the insertion sort to work with any data type that supports comparison operators.
template <typename T>   // Function to perform insertion sort on a vector of type T
void insertionSort(std::vector<T>& arr) {
    const size_t n = arr.size();
    if (n <= 1) return;

    for (size_t i = 1; i < n; ++i) {
        T key = arr[i];
        // Move elements of arr[0..i-1] that are greater than key
        int j = static_cast<int>(i) - 1;    // Static Cast to int to avoid unsigned underflow

        // Move elements of arr[0..i-1] that are greater than the key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
        // Print the array after each insertion
        for (int val : arr) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    std::vector<int> data = {12, 11, 13, 5, 6};
    // Print the original array
    for (int val : data) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    insertionSort(data);

    // for (int val : data) {
    //     std::cout << val << " ";
    // }
    std::cout << "\n"; // Output: 5 6 11 12 13
    return 0;
}
