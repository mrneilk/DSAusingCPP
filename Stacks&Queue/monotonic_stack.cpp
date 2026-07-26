// Here is the implementation for finding the Next Greater Element for every item in an array using a Monotonic Decreasing Stack.

//test run
#include <iostream>
#include <vector>
#include <stack>

std::vector<int> nextGreaterElement(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> result(n, -1);
    std::stack<int> st; // Stores indices

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            int prev_idx = st.top();
            st.pop();
            result[prev_idx] = nums[i];
        }
        st.push(i);
    }
    return result;
}
// main created seperatly
int main() {
    std::vector<int> nums = {4, 5, 2, 10, 8};
    std::vector<int> result = nextGreaterElement(nums);

    std::cout << "Next Greater Elements: ";
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
