#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int n) {
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int n = 10;
    cout << "Fibonacci number at position " << n << " is: " << fibonacci(n) << endl;
    return 0;
}

/**
 * @brief fibonacci programme with tabulation explanation
 * In this program, we use tabulation to store the values of the Fibonacci sequence in a vector called dp. 
 * We initialize the first two elements of the vector to 0 and 1, respectively, and 
 * then use a loop to fill in the rest of the vector by summing the previous two elements. 
 * 
 * Finally, we return the nth element of the vector, which corresponds to the nth number in the Fibonacci sequence.
 * 
 * Tabulation is a powerful technique for solving dynamic programming problems efficiently, as 
 * it avoids the overhead of function calls and recursion that can be associated with other dynamic programming approaches.
 * 
 */
