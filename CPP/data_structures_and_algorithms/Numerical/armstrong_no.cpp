#include <iostream>
#include <cmath>

bool isArmstrong(int n) {
    int num = n;
    int sum = 0;
    int numDigits = static_cast<int>(log10(n)) + 1;

    while (num > 0) {
        int digit = num % 10;
        sum += pow(digit, numDigits);
        num /= 10;
    }

    return (sum == n);
}

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    bool isArm = isArmstrong(num);
    std::cout << num << (isArm ? " is an Armstrong number." : " is not an Armstrong number.") << std::endl;

    return 0;
}
