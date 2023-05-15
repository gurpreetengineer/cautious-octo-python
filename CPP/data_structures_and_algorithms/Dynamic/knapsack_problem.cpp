#include <iostream>
#include <vector>

using namespace std;

int knapsack(int W, vector<int> wt, vector<int> val, int n) {
    // Create a table to store the results of subproblems
    int dp[n+1][W+1];

    // Initialize the table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (wt[i-1] <= j) {
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // Return the maximum value that can be obtained
    return dp[n][W];
}

int main() {
    // Example inputs
    int W = 50;
    vector<int> wt = {10, 20, 30};
    vector<int> val = {60, 100, 120};
    int n = wt.size();

    // Solve the Knapsack problem and print the result
    cout << "Maximum value that can be obtained: " << knapsack(W, wt, val, n) << endl;

    return 0;
}

/**
 * @brief knapsack program explanation
 * 
 * The Knapsack problem is a classic dynamic programming problem that involves packing 
 * a knapsack with items of different weights and values to obtain the maximum total value. 
 * 
 * 
 * In this program, we create a table dp to store the results of subproblems. 
 * We initialize the table for the base cases where the weight or value is 0, and then 
 * use a loop to fill in the remaining entries of the table. 
 * 
 * The max function is used to select the best choice between including the current item and excluding it. 
 * 
 * Finally, we return the maximum value that can be obtained by filling the knapsack with items.
 * 
 */
