#include <iostream>

void generateFibonacci(int n) {
    int prev = 0;
    int curr = 1;

    std::cout << "Fibonacci Series up to " << n << ": ";

    while (prev <= n) {
        std::cout << prev << " ";
        int next = prev + curr;
        prev = curr;
        curr = next;
    }

    std::cout << std::endl;
}

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    generateFibonacci(num);

    return 0;
}
