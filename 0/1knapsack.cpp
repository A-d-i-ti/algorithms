#include <iostream>
#include <vector>
using namespace std;

// Function to solve 0-1 Knapsack Problem
int knapsack(int W, vector<int> wt, vector<int> val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]],  // Include item
                               dp[i - 1][w]);                          // Exclude item
            else
                dp[i][w] = dp[i - 1][w];  // Cannot include item
        }
    }

    return dp[n][W];  // Maximum value that can be put in the knapsack
}

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;
    int n = values.size();

    int maxValue = knapsack(capacity, weights, values, n);
    cout << "Maximum value in knapsack = " << maxValue << endl;

    return 0;
}
