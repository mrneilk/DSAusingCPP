// Full Implementation of Kadane's Algorithm
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

struct SubarrayResult {
    int max_sum;
    int start_index;
    int end_index;
};

// Returns the maximum subarray sum along with its start and end indices.
SubarrayResult kadane(const std::vector<int>& nums) {
    if (nums.empty()) {
        return {0, -1, -1};
    }

    int max_so_far = nums[0];
    int current_max = nums[0];

    int best_start = 0;
    int best_end = 0;
    int temp_start = 0;

    for (size_t i = 1; i < nums.size(); ++i) {
        // If current element is greater than extending the previous sum,
        // start a new subarray at index i.
        if (nums[i] > current_max + nums[i]) {
            current_max = nums[i];
            temp_start = static_cast<int>(i);
        } else {
            current_max += nums[i];
        }

        // Update global max and record best start/end boundaries
        if (current_max > max_so_far) {
            max_so_far = current_max;
            best_start = temp_start;
            best_end = static_cast<int>(i);
        }
    }

    return {max_so_far, best_start, best_end};
}

void printSubarrayInfo(const std::vector<int>& nums) {
    SubarrayResult result = kadane(nums);

    std::cout << "Array: [ ";
    for (int val : nums) {
        std::cout << val << " ";
    }
    std::cout << "]\n";

    std::cout << "Maximum Subarray Sum : " << result.max_sum << "\n";
    std::cout << "Subarray Range       : Index " << result.start_index 
              << " to " << result.end_index << "\n";

    std::cout << "Subarray Elements    : [ ";
    for (int i = result.start_index; i <= result.end_index; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << "]\n";
    std::cout << "---------------------------------------------\n";
}

int main() {
    // Standard mixed positive/negative case
    std::vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    printSubarrayInfo(nums1);

    // All negative numbers case
    std::vector<int> nums2 = {-8, -3, -6, -2, -5, -4};
    printSubarrayInfo(nums2);

    // All positive numbers case
    std::vector<int> nums3 = {1, 2, 3, 4, 5};
    printSubarrayInfo(nums3);

    return 0;
}
