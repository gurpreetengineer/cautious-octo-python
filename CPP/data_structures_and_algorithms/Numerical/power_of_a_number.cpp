#include <iostream>

double power(double base, int exponent) {
    double result = 1.0;

    if (exponent >= 0) {
        for (int i = 0; i < exponent; ++i) {
            result *= base;
        }
    } else {
        exponent = -exponent;
        for (int i = 0; i < exponent; ++i) {
            result /= base;
        }
    }

    return result;
}

int main() {
    double base;
    int exponent;
    std::cout << "Enter base and exponent: ";
    std::cin >> base >> exponent;

    double result = power(base, exponent);
    std::cout << base << " raised to the power " << exponent << ": " << result << std::endl;

    return 0;
}
