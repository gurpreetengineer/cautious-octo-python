#include <iostream>

void generatePythagoreanTriplets(int limit) {
    std::cout << "Pythagorean triplets up to " << limit << ": ";

    for (int a = 1; a <= limit; ++a) {
        for (int b = a + 1; b <= limit; ++b) {
            int cSquare = a * a + b * b;
            int c = static_cast<int>(sqrt(cSquare));

            if (c * c == cSquare && c <= limit) {
                std::cout << "(" << a << ", " << b << ", " << c << ") ";
            }
        }
    }

    std::cout << std::endl;
}

int main() {
    int limit;
    std::cout << "Enter a limit: ";
    std::cin >> limit;

    generatePythagoreanTriplets(limit);

    return 0;
}
