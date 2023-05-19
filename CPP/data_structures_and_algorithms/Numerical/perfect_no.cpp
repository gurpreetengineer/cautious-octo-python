#include <iostream>

bool isPerfectNumber(int n) {
    int sum = 0;

    for (int i = 1; i <= n / 2; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }

    return (sum == n);
}

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    bool isPerfect = isPerfectNumber(num);
    std::cout << num << (isPerfect ? " is a perfect number." : " is not a perfect number.") << std::endl;

    return 0;
}
