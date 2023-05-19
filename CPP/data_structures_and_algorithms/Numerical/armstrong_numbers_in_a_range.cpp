#include <iostream>
#include <string>
#include <cmath>

int hexadecimalToDecimal(const std::string& hexadecimal) {
    int decimal = 0;
    int power = 0;

    for (int i = hexadecimal.length() - 1; i >= 0; --i) {
        char digit = hexadecimal[i];
        if (digit >= '0' && digit <= '9') {
            decimal += static_cast<int>(digit - '0') * pow(16, power);
        } else if (digit >= 'A' && digit <= 'F') {
            decimal += static_cast<int>(digit - 'A' + 10) * pow(16, power);
        }
        ++power;
    }

    return decimal;
}

int main() {
    std::string hexadecimal;
    std::cout << "Enter a hexadecimal number: ";
    std::cin >> hexadecimal;

    int decimal = hexadecimalToDecimal(hexadecimal);
    std::cout << "Decimal equivalent: " << decimal << std::endl;

    return 0;
}
