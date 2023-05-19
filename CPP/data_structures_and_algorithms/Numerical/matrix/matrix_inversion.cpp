#include <iostream>
#include <vector>

// Function to calculate the inverse of a matrix
std::vector<std::vector<double>> matrixInverse(const std::vector<std::vector<double>>& matrix) {
    int n = matrix.size();
    std::vector<std::vector<double>> inverse(n, std::vector<double>(n));

    // Implement matrix inversion algorithm here

    return inverse;
}

// Function to display a matrix
void displayMatrix(const std::vector<std::vector<double>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Enter the size of the square matrix: ";
    std::cin >> n;

    std::vector<std::vector<double>> matrix(n, std::vector<double>(n));

    std::cout << "Enter the elements of the matrix:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::vector<std::vector<double>> inverse = matrixInverse(matrix);

    std::cout << "Inverse of the matrix:" << std::endl;
    displayMatrix(inverse);

    return 0;
}
