#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    // DP table
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build table bottom-up
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            if (i == 0 || w == 0)
                dp[i][w] = 0;

            else if (wt[i - 1] <= w)
                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]], // include item
                    dp[i - 1][w]                          // exclude item
                );

            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;

    // Input number of items
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> wt(n), val(n);

    // Input weights and values
    cout << "Enter weight and value for each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " (weight value): ";
        cin >> wt[i] >> val[i];
    }

    // Input knapsack capacity
    cout << "Enter knapsack capacity: ";
    cin >> W;

    cout << "Maximum value = " << knapsack(W, wt, val, n);

    return 0;
}