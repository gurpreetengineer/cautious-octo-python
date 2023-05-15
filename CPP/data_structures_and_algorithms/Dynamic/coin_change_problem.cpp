#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    // Initialize the dp array with INT_MAX values
    vector<int> dp(amount + 1, INT_MAX);
    // Set the base case: dp[0] = 0 (minimum number of coins needed to make 0 amount is 0)
    dp[0] = 0;
    
    // Compute the minimum number of coins needed for each amount from 1 to amount
    for (int i = 1; i <= amount; i++) {
        // Try using each coin to make the current amount
        for (int j = 0; j < coins.size(); j++) {
            // If the coin is less than or equal to the current amount
            if (coins[j] <= i) {
                // Compute the minimum number of coins needed for the remaining amount (i - coins[j])
                int subproblem = dp[i - coins[j]];
                // If the subproblem solution is valid (not INT_MAX) and is less than the current minimum
                if (subproblem != INT_MAX && subproblem + 1 < dp[i]) {
                    // Update the current minimum
                    dp[i] = subproblem + 1;
                }
            }
        }
    }
    
    // Return the minimum number of coins needed for the given amount
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    
    int minCoins = coinChange(coins, amount);
    
    cout << "Minimum number of coins needed to make " << amount << " cents: " << minCoins << endl;
    
    return 0;
}


/**
 * @brief Coin change problem's solution using dynamic programming
 * The Coin Change problem is a classic dynamic programming problem that 
 * involves finding the minimum number of coins needed to make a certain amount of change.
 * 
 * In this program, we use a dynamic programming approach to solve the Coin Change problem. 
 * We create a dp array to store the minimum number of coins needed for each amount from 0 to the given amount. 
 * We set the base case (dp[0] = 0) and compute the minimum number of coins 
 * needed for each remaining amount by trying each coin denomination. 
 * 
 * We use the minimum number of coins needed for the remaining amount (i - coins[j]) and 
 * add 1 (for the current coin) to get the minimum number of coins needed for the current amount (i). 
 * We update the dp array with the current minimum if it is less than the current value in the dp array. 
 * 
 * Finally, we return the value in the dp array for the given amount.
 * 
 */
