#include <stdio.h>

// Function to get maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function implementing the 0/1 Knapsack problem using Dynamic Programming
int knapsack(int W, int wt[], int val[], int n) {
    int dp[n+1][W+1];

    // Build table dp[][] in bottom up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i-1] <= w)
                dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][W];
}

int main() {
    int n, W;

    // Input: number of items and maximum capacity
    printf("Enter the number of items: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Number of items must be positive.\n");
        return 1;
    }

    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &W);
    if (W < 0) {
        printf("Maximum capacity cannot be negative.\n");
        return 1;
    }

    int wt[n], val[n];

    // Input: weight and value for each item
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value of item %d: ", i+1);
        scanf("%d %d", &wt[i], &val[i]);
        if (wt[i] < 0 || val[i] < 0) {
            printf("Weight and value must be non-negative.\n");
            return 1;
        }
    }

    // Calculate maximum profit (total value)
    int maxValue = knapsack(W, wt, val, n);
    printf("The maximum value that can be obtained is: %d\n", maxValue);

    return 0;
}
