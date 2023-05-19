#include <iostream>
#include <vector>

bool isSkewSymmetric(const std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int columns = matrix[0].size();

    // Check if the matrix is skew-symmetric
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (matrix[i][j] != -matrix[j][i]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {0, -2, 3},
        {2, 0, -4},
        {-3, 4, 0}
    };

    bool isSkewSymmetricMatrix = isSkewSymmetric(matrix);

    if (isSkewSymmetricMatrix) {
        std::cout << "The matrix is skew-symmetric." << std::endl;
    } else {
        std::cout << "The matrix is not skew-symmetric." << std::endl;
    }

    return 0;
}
