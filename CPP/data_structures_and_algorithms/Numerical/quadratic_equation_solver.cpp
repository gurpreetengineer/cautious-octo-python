#include <iostream>
#include <cmath>

void solveQuadraticEquation(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        std::cout << "Roots are real and different." << std::endl;
        std::cout << "Root 1 = " << root1 << std::endl;
        std::cout << "Root 2 = " << root2 << std::endl;
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        std::cout << "Roots are real and same." << std::endl;
        std::cout << "Root = " << root << std::endl;
    } else {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        std::cout << "Roots are complex and different." << std::endl;
        std::cout << "Root 1 = " << realPart << " + " << imaginaryPart << "i" << std::endl;
        std::cout << "Root 2 = " << realPart << " - " << imaginaryPart << "i" << std::endl;
    }
}

int main() {
    double a, b, c;
    std::cout << "Enter coefficients (a, b, c) of the quadratic equation: ";
    std::cin >> a >> b >> c;

    solveQuadraticEquation(a, b, c);

    return 0;
}
