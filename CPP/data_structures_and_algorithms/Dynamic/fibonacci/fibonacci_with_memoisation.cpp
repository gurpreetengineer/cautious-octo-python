#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the nth Fibonacci number
int fibonacci(int n, vector<int>& memo) {
    // Check if the nth Fibonacci number has already been calculated
    if (memo[n] != -1) {
        return memo[n];
    }
    
    // Calculate the nth Fibonacci number
    int result;
    if (n == 0 || n == 1) {
        result = n;
    } else {
        result = fibonacci(n-1, memo) + fibonacci(n-2, memo);
    }
    
    // Store the result in the memoization table
    memo[n] = result;
    
    return result;
}

int main() {
    int n = 10;
    
    // Initialize the memoization table with -1
    vector<int> memo(n+1, -1);
    
    // Calculate the nth Fibonacci number using memoization
    int fib = fibonacci(n, memo);
    
    cout << "The " << n << "th Fibonacci number is " << fib << endl;
    
    return 0;
}

/**
 * @brief Fibonacci progamme with memoisation
 * In this program, we use memoization to calculate the nth Fibonacci number efficiently. 
 * We use a vector called memo to store the results of previous function calls, so 
 * that we don't have to recalculate the same values again. 
 * We initialize the vector with -1 to indicate that the values have not yet been calculated.
 * 
 * The fibonacci function takes two arguments: 
 * n is the number we want to calculate the Fibonacci sequence for, and 
 * memo is the memoization table. 
 * 
 * We first check if the value of memo[n] is not -1; if it is not -1, then 
 * we return the precalculated value stored in memo[n]. 
 * If memo[n] is -1, then we calculate the nth Fibonacci number recursively by calling 
 * the fibonacci function with arguments (n-1, memo) and (n-2, memo). 
 * We store the result in memo[n] and return the result.
 * 
 * Finally, in the main function, we initialize the memoization table with -1, and 
 * call the fibonacci function to calculate the nth Fibonacci number using memoization. 
 * We then print out the result.
 * 
 * This program is efficient because it uses memoization to avoid recalculating the same values multiple times. 
 * By storing the results of previous function calls in the memoization table, 
 * we can avoid redundant calculations and reduce the time complexity of the algorithm.
 * 
 */
