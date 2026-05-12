#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n = 4;
int dist[10][10] = {
    {0, 20, 10, 12},
    {20, 0, 15, 11},
    {10, 15, 0, 17},
    {12, 11, 17, 0}
};

// memo[mask][pos] -> min weight to visit remaining cities
// mask: bitmask of visited cities
// pos: current city index
int memo[1 << 10][10];

int tsp(int mask, int pos) {
    // Base case: If all cities are visited, return to start (city 0)
    if (mask == (1 << n) - 1) {
        return dist[pos][0];
    }

    if (memo[mask][pos] != -1) return memo[mask][pos];

    int ans = 1e9; // Infinity

    for (int city = 0; city < n; city++) {
        // If the city has not been visited yet
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }

    return memo[mask][pos] = ans;
}

int main() {
    memset(memo, -1, sizeof(memo));
    cout << "Shortest Path Distance: " << tsp(1, 0) << endl;
    return 0;
}
