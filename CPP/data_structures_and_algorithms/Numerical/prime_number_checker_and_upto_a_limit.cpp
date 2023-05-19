#include <iostream>
#include <vector>

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

void findPrimes(int limit) {
    std::cout << "Prime Numbers up to " << limit << ": ";

    for (int i = 2; i <= limit; ++i) {
        if (isPrime(i)) {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;
}

int main() {
    int limit;
    std::cout << "Enter a limit: ";
    std::cin >> limit;

    findPrimes(limit);

    return 0;
}
