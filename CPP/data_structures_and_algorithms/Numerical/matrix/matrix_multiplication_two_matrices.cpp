#include <iostream>
#include <vector>

std::vector<std::vector<int>> matrixMultiplication(const std::vector<std::vector<int>>& matrix1,
                                                   const std::vector<std::vector<int>>& matrix2) {
    int rows1 = matrix1.size();
    int columns1 = matrix1[0].size();
    int columns2 = matrix2[0].size();

    std::vector<std::vector<int>> result(rows1, std::vector<int>(columns2, 0));

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < columns2; ++j) {
            for (int k = 0; k < columns1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

void displayMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int rows1, columns1, rows2, columns2;
    std::cout << "Enter the number of rows and columns for matrix1: ";
    std::cin >> rows1 >> columns1;

    std::cout << "Enter the number of rows and columns for matrix2: ";
    std::cin >> rows2 >> columns2;

    if (columns1 != rows2) {
        std::cout << "Matrix multiplication not possible." << std::endl;
        return 0;
    }

    std::vector<std::vector<int>> matrix1(rows1, std::vector<int>(columns1));
    std::vector<std::vector<int>> matrix2(rows2, std::vector<int>(columns2));

    std::cout << "Enter elements of matrix1:" << std::endl;
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < columns1; ++j) {
            std::cin >> matrix1[i][j];
        }
    }

    std::cout << "Enter elements of matrix2:" << std::endl;
    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < columns2; ++j) {
            std::cin >> matrix2[i][j];
        }
    }

    std::vector<std::vector<int>> result = matrixMultiplication(matrix1, matrix2);

    std::cout << "Resultant matrix:" << std::endl;
    displayMatrix(result);

    return 0;
}
