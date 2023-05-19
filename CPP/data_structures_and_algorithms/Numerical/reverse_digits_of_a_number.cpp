#include <iostream>

int reverseNumber(int n) {
    int rev = 0;

    while (n > 0) {
        int digit = n % 10;
        rev = rev * 10 + digit;
        n /= 10;
    }

    return rev;
}

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    int rev = reverseNumber(num);
    std::cout << "Reverse of " << num << ": " << rev << std::endl;

    return 0;
}
