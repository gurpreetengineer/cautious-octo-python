#include <iostream>

int sumOfDigits(int n) {
    int sum = 0;

    while (n > 0) {
        int digit = n % 10;
        sum += digit;
        n /= 10;
    }

    return sum;
}

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    int sum = sumOfDigits(num);
    std::cout << "Sum of digits of " << num << ": " << sum << std::endl;

    return 0;
}
