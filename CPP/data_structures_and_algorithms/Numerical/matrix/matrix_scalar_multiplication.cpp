#include <iostream>
#include <vector>

// Function to perform scalar multiplication on a matrix
std::vector<std::vector<double>> matrixScalarMultiplication(const std::vector<std::vector<double>>& matrix, double scalar) {
    int rows = matrix.size();
    int columns = matrix[0].size();

    std::vector<std::vector<double>> result(rows, std::vector<double>(columns));

    // Perform scalar multiplication on each element of the matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            result[i][j] = matrix[i][j] * scalar;
        }
    }

    return result;
}

// Function to display a matrix
void displayMatrix(const std::vector<std::vector<double>>& matrix) {
    int rows = matrix.size();
    int columns = matrix[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int rows, columns;
    std::cout << "Enter the number of rows and columns of the matrix: ";
    std::cin >> rows >> columns;

    std::vector<std::vector<double>> matrix(rows, std::vector<double>(columns));

    std::cout << "Enter the elements of the matrix:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    double scalar;
    std::cout << "Enter the scalar value: ";
    std::cin >> scalar;

    std::vector<std::vector<double>> result = matrixScalarMultiplication(matrix, scalar);

    std::cout << "Resultant matrix:" << std::endl;
    displayMatrix(result);

    return 0;
}
