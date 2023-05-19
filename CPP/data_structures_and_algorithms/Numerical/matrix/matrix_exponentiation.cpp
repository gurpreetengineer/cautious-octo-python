#include <iostream>
#include <vector>

std::vector<std::vector<double>> matrixMultiply(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2) {
    int rows1 = matrix1.size();
    int columns1 = matrix1[0].size();
    int rows2 = matrix2.size();
    int columns2 = matrix2[0].size();

    std::vector<std::vector<double>> result(rows1, std::vector<double>(columns2, 0));

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < columns2; ++j) {
            for (int k = 0; k < columns1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

std::vector<std::vector<double>> matrixExponential(const std::vector<std::vector<double>>& matrix, int power) {
    std::vector<std::vector<double>> result = matrix;
    std::vector<std::vector<double>> identity = matrix;
    int rows = matrix.size();
    int columns = matrix[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            identity[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }

    for (int i = 1; i < power; ++i) {
        result = matrixMultiply(result, matrix);
        for (int j = 0; j < rows; ++j) {
            for (int k = 0; k < columns; ++k) {
                result[j][k] += identity[j][k];
            }
        }
    }

    return result;
}

int main() {
    std::vector<std::vector<double>> matrix = {
        {1, 2},
        {3, 4}
    };

    int power = 2;
    std::vector<std::vector<double>> result = matrixExponential(matrix, power);

    // Display the result
    for (const auto& row : result) {
        for (double element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
