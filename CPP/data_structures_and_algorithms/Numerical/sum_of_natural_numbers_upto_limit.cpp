#include <iostream>

int sumOfNaturalNumbers(int n) {
    return (n * (n + 1)) / 2;
}

int main() {
    int limit;
    std::cout << "Enter a limit: ";
    std::cin >> limit;

    int sum = sumOfNaturalNumbers(limit);
    std::cout << "Sum of natural numbers up to " << limit << ": " << sum << std::endl;

    return 0;
}
