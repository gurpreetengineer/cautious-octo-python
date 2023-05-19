#include <iostream>

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

void generateFibonacciSeries(int count) {
    std::cout << "Fibonacci series up to " << count << ": ";

    for (int i = 0; i < count; ++i) {
        std::cout << fibonacci(i) << " ";
    }

    std::cout << std::endl;
}

int main() {
    int count;
    std::cout << "Enter the count: ";
    std::cin >> count;

    generateFibonacciSeries(count);

    return 0;
}
