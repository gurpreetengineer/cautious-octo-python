#include <iostream>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int lcm(int a, int b) {
    int gcdVal = gcd(a, b);
    return (a * b) / gcdVal;
}

int main() {
    int num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    int lcmVal = lcm(num1, num2);
    std::cout << "LCM of " << num1 << " and " << num2 << ": " << lcmVal << std::endl;

    return 0;
}
