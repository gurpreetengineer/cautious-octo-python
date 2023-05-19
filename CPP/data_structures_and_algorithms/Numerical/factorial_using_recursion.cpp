#include <iostream>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    return n * factorial(n - 1);
}

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    int result = factorial(num);
    std::cout << "Factorial of " << num << ": " << result << std::endl;

    return 0;
}
