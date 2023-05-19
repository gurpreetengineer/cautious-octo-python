#include <iostream>
#include <vector>

// Function to check if two matrices are equal
bool matrixEquality(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2) {
    int rows1 = matrix1.size();
    int columns1 = matrix1[0].size();
    int rows2 = matrix2.size();
    int columns2 = matrix2[0].size();

    if (rows1 != rows2 || columns1 != columns2) {
        return false;
    }

    // Check element-wise equality of the matrices
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < columns1; ++j) {
            if (matrix1[i][j] != matrix2[i][j]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int rows1, columns1;
    std::cout << "Enter the number of rows and columns of the first matrix: ";
    std::cin >> rows1 >> columns1;

    std::vector<std::vector<double>> matrix1(rows1, std::vector<double>(columns1));

    std::cout << "Enter the elements of the first matrix:" << std::endl;
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < columns1; ++j) {
            std::cin >> matrix1[i][j];
        }
    }

    int rows2, columns2;
    std::cout << "Enter the number of rows and columns of the second matrix: ";
    std::cin >> rows2 >> columns2;

    std::vector<std::vector<double>> matrix2(rows2, std::vector<double>(columns2));

    std::cout << "Enter the elements of the second matrix:" << std::endl;
    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < columns2; ++j) {
            std::cin >> matrix2[i][j];
        }
    }

    bool isEqual = matrixEquality(matrix1, matrix2);

    if (isEqual) {
        std::cout << "Matrices are equal." << std::endl;
    } else {
        std::cout << "Matrices are not equal." << std::endl;
    }

    return 0;
}
