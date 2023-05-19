#include <iostream>
#include <vector>

void primeFactorization(int n) {
    std::cout << "Prime factorization of " << n << ": ";

    for (int i = 2; i <= n; ++i) {
        while (n % i == 0) {
            std::cout << i << " ";
            n /= i;
        }
    }

    std::cout << std::endl;
}

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    primeFactorization(num);

    return 0;
}
