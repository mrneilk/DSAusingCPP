#include <iostream>
#include <vector>
#include <stdexcept> // For throwing errors

// Segment Tree implementation for range sum queries
class SegmentTree {
    std::vector<int> tree;
    int n;
// Function to build the segment tree
    void build(const std::vector<int>& arr, int node, int start, int end) {
        // need to add a check if the input is exceed the size of the tree/or array
        // Updated in the entry fuction to check if the input is valid or not
        if (start == end) {
            tree[node] = arr[start]; // Leaf node
            return;
        }
        // Internal node will have the sum of both of its children
        // Whats happening here?
        // We are calculating the mid point of the current segment and recursively building the left and right subtrees.
        int mid = (start + end) / 2;
        build(arr, 2 * node + 1, start, mid);
        build(arr, 2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
// Function to query the sum in the range [l, r]
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0; // Out of range
        if (l <= start && end <= r) return tree[node]; // Completely inside

        int mid = (start + end) / 2;
        return query(2 * node + 1, start, mid, l, r) + 
               query(2 * node + 2, mid + 1, end, l, r);
    }

public:
// Constructor to build the segment tree from the input array
    SegmentTree(const std::vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }
// Function to get the sum of a range [l, r]
    int getSum(int l, int r) {
        // 1. Check if range is logically sound (start <= end)
        // 2. Check if indices are within the actual array bounds [0, n-1]
        if (l < 0 || r >= n || l > r) {
            std::cerr << "Invalid Range: [" << l << ", " << r << "]. ";
            return -1; // Or throw an exception
        }
        return query(0, 0, n - 1, l, r);
    }
};

int main() {
    // Example usage
    std::vector<int> data = {1, 3, 5, 7, 9, 11};
    // Build the segment tree
    SegmentTree st(data);

    std::cout << "Sum of range [1, 3]: " << st.getSum(1, 3) << std::endl; // 3+5+7 = 15
    return 0;
}
