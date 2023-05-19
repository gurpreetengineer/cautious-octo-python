#include <iostream>
#include <vector>

bool isSymmetric(const std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int columns = matrix[0].size();

    // Check if the matrix is symmetric
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {2, 4, 5},
        {3, 5, 6}
    };

    bool isSymmetricMatrix = isSymmetric(matrix);

    if (isSymmetricMatrix) {
        std::cout << "The matrix is symmetric." << std::endl;
    } else {
        std::cout << "The matrix is not symmetric." << std::endl;
    }

    return 0;
}
