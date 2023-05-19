#include <iostream>
#include <vector>

void swapColumns(std::vector<std::vector<int>>& matrix, int col1, int col2) {
    for (int i = 0; i < matrix.size(); ++i) {
        std::swap(matrix[i][col1], matrix[i][col2]);
    }
}

void scaleColumn(std::vector<std::vector<int>>& matrix, int column, int scalar) {
    for (int i = 0; i < matrix.size(); ++i) {
        matrix[i][column] *= scalar;
    }
}

void addColumns(std::vector<std::vector<int>>& matrix, int sourceColumn, int targetColumn) {
    for (int i = 0; i < matrix.size(); ++i) {
        matrix[i][targetColumn] += matrix[i][sourceColumn];
    }
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    swapColumns(matrix, 0, 2);
    scaleColumn(matrix, 1, 2);
    addColumns(matrix, 0, 1);

    // Display the modified matrix
    for (const auto& row : matrix) {
        for (int element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
