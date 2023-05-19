#include <iostream>
#include <vector>

void rowEchelonForm(std::vector<std::vector<double>>& matrix) {
    int rows = matrix.size();
    int columns = matrix[0].size();
    int lead = 0;

    for (int r = 0; r < rows; ++r) {
        if (columns <= lead) {
            return;
        }

        int i = r;
        while (matrix[i][lead] == 0) {
            ++i;
            if (rows == i) {
                i = r;
                ++lead;
                if (columns == lead) {
                    return;
                }
            }
        }

        std::swap(matrix[i], matrix[r]);

        if (matrix[r][lead] != 0) {
            double div = matrix[r][lead];
            for (int j = 0; j < columns; ++j) {
                matrix[r][j] /= div;
            }
        }

        for (int k = 0; k < rows; ++k) {
            if (k != r) {
                double mult = matrix[k][lead];
                for (int j = 0; j < columns; ++j) {
                    matrix[k][j] -= mult * matrix[r][j];
                }
            }
        }

        ++lead;
    }
}

int main() {
    std::vector<std::vector<double>> matrix = {
        {1, 2, 1, 4},
        {2, 3, 1, 7},
        {1, 1, 0, 3}
    };

    rowEchelonForm(matrix);

    // Display the row echelon form matrix
    for (const auto& row : matrix) {
        for (double element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
