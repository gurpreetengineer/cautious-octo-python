#include <iostream>
#include <cmath>

int binaryToDecimal(int binary) {
    int decimal = 0;
    int base = 0;

    while (binary > 0) {
        int digit = binary % 10;
        decimal += digit * pow(2, base);
        binary /= 10;
        ++base;
    }

    return decimal;
}

int main() {
    int binary;
    std::cout << "Enter a binary number: ";
    std::cin >> binary;

    int decimal = binaryToDecimal(binary);
    std::cout << "Decimal equivalent: " << decimal << std::endl;

    return 0;
}
