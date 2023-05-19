#include <iostream>
#include <vector>

// Function to calculate the trace of a matrix
double matrixTrace(const std::vector<std::vector<double>>& matrix) {
    int n = matrix.size();
    double trace = 0.0;

    // Calculate the trace of the matrix
    for (int i = 0; i < n; ++i) {
        trace += matrix[i][i];
    }

    return trace;
}

int main() {
    int n;
    std::cout << "Enter the size of the square matrix: ";
    std::cin >> n;

    std::vector<std::vector<double>> matrix(n, std::vector<double>(n));

    std::cout << "Enter the elements of the matrix:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    double trace = matrixTrace(matrix);

    std::cout << "Trace of the matrix: " << trace << std::endl;

    return 0;
}
