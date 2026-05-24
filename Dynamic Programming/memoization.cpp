#include <iostream>
#include <unordered_map>
#include <chrono>

// 1. Slow approach: Standard Recursion without memoization
long long fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

// 2. Fast approach: Recursion WITH Memoization
// We pass the map by reference (&) so all recursive calls share the same cache
long long fibMemo(int n, std::unordered_map<int, long long>& memo) {
    // Check if we have already calculated this value
    if (memo.find(n) != memo.end()) {
        return memo[n]; // Return the cached result
    }
    
    // Base cases
    if (n <= 1) return n;
    
    // Calculate and save the result into the memo map before returning
    memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
    return memo[n];
}

int main() {
    int n = 40; // Fibonacci number to calculate
    
    std::cout << "Calculating Fibonacci(" << n << ")..." << std::endl;

    // --- TIMING WITHOUT MEMOIZATION ---
    auto start1 = std::chrono::high_resolution_clock::now();
    long long result1 = fib(n);
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed1 = end1 - start1;
    
    std::cout << "\n[Without Memoization]" << std::endl;
    std::cout << "Result: " << result1 << std::endl;
    std::cout << "Time taken: " << elapsed1.count() << " seconds" << std::endl;

    // --- TIMING WITH MEMOIZATION ---
    std::unordered_map<int, long long> memo; // Our cache
    
    auto start2 = std::chrono::high_resolution_clock::now();
    long long result2 = fibMemo(n, memo);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed2 = end2 - start2;

    std::cout << "\n[With Memoization]" << std::endl;
    std::cout << "Result: " << result2 << std::endl;
    std::cout << "Time taken: " << elapsed2.count() << " seconds" << std::endl;

    return 0;
}
