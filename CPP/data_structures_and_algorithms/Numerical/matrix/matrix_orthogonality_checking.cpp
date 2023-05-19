#include <iostream>
#include <vector>

bool isOrthogonal(const std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int columns = matrix[0].size();

    // Check if each pair of columns is orthogonal
    for (int i = 0; i < columns; ++i) {
        for (int j = i + 1; j < columns; ++j) {
            int dotProduct = 0;
            for (int k = 0; k < rows; ++k) {
                dotProduct += matrix[k][i] * matrix[k][j];
            }
            if (dotProduct != 0) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    bool isOrthogonalMatrix = isOrthogonal(matrix);

    if (isOrthogonalMatrix) {
        std::cout << "The matrix is orthogonal." << std::endl;
    } else {
        std::cout << "The matrix is not orthogonal." << std::endl;
    }

    return 0;
}
