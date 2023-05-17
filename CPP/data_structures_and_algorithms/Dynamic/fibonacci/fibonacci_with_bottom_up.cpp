#include <iostream>
#include <vector>

using namespace std;

int fib(int n) {
    vector<int> memo(n + 1);
    memo[0] = 0;
    memo[1] = 1;
    for (int i = 2; i <= n; i++) {
        memo[i] = memo[i - 1] + memo[i - 2];
    }
    return memo[n];
}

int main() {
    int n = 10;
    cout << "The " << n << "th Fibonacci number is " << fib(n) << endl;
    return 0;
}

/**
 * @brief Fibonacci with bottom-up approach
 * In this program, we create a vector called memo to store the values of the Fibonacci sequence. 
 * We start by initializing the first two values of the sequence (memo[0] and memo[1]) and 
 * then use a loop to calculate the rest of the values of the sequence. 
 * The memo vector stores the intermediate results so that we can reuse them later and avoid redundant calculations.
 * 
 * By using bottom-up dynamic programming, we avoid the overhead of recursive function calls and 
 * reduce the time complexity of calculating the Fibonacci sequence from exponential to linear.
 * 
 */
