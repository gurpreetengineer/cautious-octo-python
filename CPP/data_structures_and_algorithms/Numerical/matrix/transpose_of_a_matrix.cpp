#include <iostream>
#include <vector>

std::vector<std::vector<int>> transposeMatrix(const std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int columns = matrix[0].size();

    std::vector<std::vector<int>> transposedMatrix(columns, std::vector<int>(rows, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }

    return transposedMatrix;
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
    std::cout << "Enter the number of rows and columns for the matrix: ";
    std::cin >> rows >> columns;

    std::vector<std::vector<int>> matrix(rows, std::vector<int>(columns));

    std::cout << "Enter elements of the matrix:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::vector<std::vector<int>> transposedMatrix = transposeMatrix(matrix);

    std::cout << "Transposed matrix:" << std::endl;
    displayMatrix(transposedMatrix);

    return 0;
}
