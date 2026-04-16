#include <iostream>
#include <vector>

class SegmentTree {
    std::vector<int> tree;
    int n;

    void build(const std::vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start]; // Leaf node
            return;
        }
        int mid = (start + end) / 2;
        build(arr, 2 * node + 1, start, mid);
        build(arr, 2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0; // Out of range
        if (l <= start && end <= r) return tree[node]; // Completely inside

        int mid = (start + end) / 2;
        return query(2 * node + 1, start, mid, l, r) + 
               query(2 * node + 2, mid + 1, end, l, r);
    }

public:
    SegmentTree(const std::vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    int getSum(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

int main() {
    std::vector<int> data = {1, 3, 5, 7, 9, 11};
    SegmentTree st(data);

    std::cout << "Sum of range [1, 3]: " << st.getSum(1, 3) << std::endl; // 3+5+7 = 15
    return 0;
}
