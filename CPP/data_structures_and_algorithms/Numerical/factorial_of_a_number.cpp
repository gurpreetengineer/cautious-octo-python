#include <iostream>

int factorial(int n) {
    int result = 1;

    for (int i = 2; i <= n; ++i) {
        result *= i;
    }

    return result;
}

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    int fact = factorial(num);
    std::cout << "Factorial of " << num << ": " << fact << std::endl;

    return 0;
}
