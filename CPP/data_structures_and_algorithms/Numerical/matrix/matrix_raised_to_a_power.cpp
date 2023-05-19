#include <iostream>
#include <vector>

std::vector<std::vector<int>> matrixMultiply(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    int rows1 = matrix1.size();
    int columns1 = matrix1[0].size();
    int rows2 = matrix2.size();
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

std::vector<std::vector<int>> matrixPower(const std::vector<std::vector<int>>& matrix, int power) {
    std::vector<std::vector<int>> result = matrix;
    for (int i = 1; i < power; ++i) {
        result = matrixMultiply(result, matrix);
    }
    return result;
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 2},
        {3, 4}
    };

    int power = 3;
    std::vector<std::vector<int>> result = matrixPower(matrix, power);

    // Display the result
    for (const auto& row : result) {
        for (int element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
