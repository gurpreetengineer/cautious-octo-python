#include <iostream>
#include <vector>

std::vector<int> decimalToBinary(int decimal) {
    std::vector<int> binary;

    while (decimal > 0) {
        int digit = decimal % 2;
        binary.insert(binary.begin(), digit);
        decimal /= 2;
    }

    return binary;
}

int main() {
    int decimal;
    std::cout << "Enter a decimal number: ";
    std::cin >> decimal;

    std::vector<int> binary = decimalToBinary(decimal);
    std::cout << "Binary equivalent: ";

    for (int digit : binary) {
        std::cout << digit;
    }

    std::cout << std::endl;

    return 0;
}
