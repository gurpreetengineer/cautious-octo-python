#include <iostream>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int main() {
    int num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    int gcdVal = gcd(num1, num2);
    std::cout << "GCD of " << num1 << " and " << num2 << ": " << gcdVal << std::endl;

    return 0;
}
