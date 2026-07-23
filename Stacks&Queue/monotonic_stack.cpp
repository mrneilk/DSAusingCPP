
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
