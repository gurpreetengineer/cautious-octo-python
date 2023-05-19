#include <iostream>
#include <vector>

// Function to calculate the rank of a matrix
int matrixRank(const std::vector<std::vector<double>>& matrix) {
    int rank = 0;
    
    // Implement matrix rank calculation algorithm here
    
    return rank;
}

int main() {
    int rows, columns;
    std::cout << "Enter the number of rows and columns of the matrix: ";
    std::cin >> rows >> columns;

    std::vector<std::vector<double>> matrix(rows, std::vector<double>(columns));

    std::cout << "Enter the elements of the matrix:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    int rank = matrixRank(matrix);

    std::cout << "Rank of the matrix: " << rank << std::endl;

    return 0;
}
