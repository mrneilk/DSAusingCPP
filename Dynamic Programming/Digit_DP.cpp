// From Gemini
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

long long memo[20][2][180]; // pos, isLess, current_sum (max 9*18)
string R_str;

/**
 * @param pos     Current digit position we are filling
 * @param isLess  Tight constraint flag (true if we can use any digit 0-9)
 * @param sum     The running sum of digits
 */
long long solve(int pos, bool isLess, int sum, int target_sum) {
    // Base Case: We've filled all positions
    if (pos == R_str.length()) {
        return (sum == target_sum);
    }

    // Memoization lookup
    if (memo[pos][isLess][sum] != -1) {
        return memo[pos][isLess][sum];
    }

    long long count = 0;
    // Determine the upper limit for the current digit
    int limit = isLess ? 9 : (R_str[pos] - '0');

    for (int d = 0; d <= limit; d++) {
        // New constraint: if we pick a digit < limit, all subsequent digits are 'free'
        bool nextIsLess = isLess || (d < limit);
        
        // Only recurse if the sum doesn't exceed our target
        if (sum + d <= target_sum) {
            count += solve(pos + 1, nextIsLess, sum + d, target_sum);
        }
    }

    return memo[pos][isLess][sum] = count;
}

long long getCount(long long n, int target) {
    if (n < 0) return 0;
    R_str = to_string(n);
    memset(memo, -1, sizeof(memo));
    return solve(0, false, 0, target);
}

int main() {
    long long L = 10, R = 500;
    int target = 5;

    // Standard prefix trick: Count(R) - Count(L-1)
    long long result = getCount(R, target) - getCount(L - 1, target);

    cout << "Numbers between " << L << " and " << R 
         << " with digit sum " << target << ": " << result << endl;
    return 0;
}
