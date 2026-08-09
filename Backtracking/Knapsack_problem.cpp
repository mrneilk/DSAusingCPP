// Knapsack Problem

//main function updated 8 AUg 2026
#include <iostream>
#include <vector>
#include <algorithm>

int knapsack01(int W, const std::vector<int>& weights, const std::vector<int>& values, int n) {
    // dp[i][w] stores max value for first i items with capacity w
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                // Choice: Include the item vs Exclude the item
                dp[i][w] = std::max(values[i - 1] + dp[i - 1][w - weights[i - 1]], 
                                    dp[i - 1][w]);
            } else {
                // Cannot include item (exceeds current capacity w)
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}
int main() {
    // Sample test case
    std::vector<int> values = {60, 100, 120};
    std::vector<int> weights = {10, 20, 30};
    int W = 50; // Knapsack capacity
    int n = values.size();

    int maxValue = knapsack01(W, weights, values, n);

    std::cout << "Maximum value in Knapsack = " << maxValue << std::endl;

    return 0;
}
