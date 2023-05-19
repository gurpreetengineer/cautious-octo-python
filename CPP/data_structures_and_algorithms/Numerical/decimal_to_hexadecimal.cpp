#include <iostream>
#include <string>
#include <algorithm>

std::string decimalToHexadecimal(int decimal) {
    std::string hexadecimal;

    while (decimal > 0) {
        int digit = decimal % 16;
        if (digit < 10) {
            hexadecimal += static_cast<char>(digit + '0');
        } else {
            hexadecimal += static_cast<char>(digit - 10 + 'A');
        }
        decimal /= 16;
    }

    std::reverse(hexadecimal.begin(), hexadecimal.end());

    return hexadecimal;
}

int main() {
    int decimal;
    std::cout << "Enter a decimal number: ";
    std::cin >> decimal;

    std::string hexadecimal = decimalToHexadecimal(decimal);
    std::cout << "Hexadecimal equivalent: " << hexadecimal << std::endl;

    return 0;
}
