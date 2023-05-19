#include <iostream>

bool isPalindrome(int n) {
    int num = n;
    int rev = 0;

    while (num > 0) {
        int digit = num % 10;
        rev = rev * 10 + digit;
        num /= 10;
    }

    return (rev == n);
}

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    bool isPal = isPalindrome(num);
    std::cout << num << (isPal ? " is a palindrome." : " is not a palindrome.") << std::endl;

    return 0;
}
