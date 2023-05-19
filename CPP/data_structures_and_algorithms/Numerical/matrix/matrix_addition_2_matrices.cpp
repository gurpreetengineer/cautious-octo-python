#include <iostream>
#include <vector>

std::vector<std::vector<int>> matrixAddition(const std::vector<std::vector<int>>& matrix1,
                                             const std::vector<std::vector<int>>& matrix2) {
    int rows = matrix1.size();
    int columns = matrix1[0].size();

    std::vector<std::vector<int>> result(rows, std::vector<int>(columns, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
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
    int rows, columns;
    std::cout << "Enter the number of rows and columns for the matrices: ";
    std::cin >> rows >> columns;

    std::vector<std::vector<int>> matrix1(rows, std::vector<int>(columns));
    std::vector<std::vector<int>> matrix2(rows, std::vector<int>(columns));

    std::cout << "Enter elements of matrix1:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cin >> matrix1[i][j];
        }
    }

    std::cout << "Enter elements of matrix2:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cin >> matrix2[i][j];
        }
    }

    std::vector<std::vector<int>> result = matrixAddition(matrix1, matrix2);

    std::cout << "Resultant matrix:" << std::endl;
    displayMatrix(result);

    return 0;
}
