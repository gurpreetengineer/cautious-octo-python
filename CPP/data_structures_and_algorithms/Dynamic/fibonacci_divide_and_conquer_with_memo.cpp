#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> memo;

int fibonacci(int n) {
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }
    
    int result;
    
    if (n == 0) {
        result = 0;
    } else if (n == 1) {
        result = 1;
    } else {
        int a = fibonacci(n - 1);
        int b = fibonacci(n - 2);
        result = a + b;
    }
    
    memo[n] = result;
    return result;
}

int main() {
    int n = 10;
    int fib = fibonacci(n);
    
    cout << "The " << n << "th Fibonacci number is: " << fib << endl;
    
    return 0;
}

/**
 * @brief fibonacci with divide and conquer using memoization
 * In this program, the fibonacci function uses memoization to cache the results of previously computed Fibonacci numbers. 
 * When the function is called with a value of n, 
 * it first checks if the result for that value of n has already been computed and stored in the memo map. 
 * If it has, it returns that result directly. 
 * Otherwise, it uses the Divide and Conquer approach to compute the result recursively, 
 * by calling itself with n-1 and n-2, and then combining the results. 
 * Finally, it stores the computed result in the memo map before returning it.
 * 
 * Using memoization in this way avoids recomputing the same Fibonacci numbers multiple times, 
 * resulting in a significant speedup compared to a naive recursive implementation of the Fibonacci sequence.
 * 
 */
