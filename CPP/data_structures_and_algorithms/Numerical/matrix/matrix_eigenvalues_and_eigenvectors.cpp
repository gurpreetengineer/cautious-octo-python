#include <iostream>
#include <vector>
#include <cmath>

struct Eigenpair {
    double eigenvalue;
    std::vector<double> eigenvector;
};

std::vector<Eigenpair> findEigenpairs(const std::vector<std::vector<double>>& matrix) {
    int n = matrix.size();
    std::vector<Eigenpair> eigenpairs;

    std::vector<std::vector<double>> identity(n, std::vector<double>(n, 0));
    for (int i = 0; i < n; ++i) {
        identity[i][i] = 1;
    }

    std::vector<std::vector<double>> tempMatrix = matrix;
    for (int k = 0; k < n; ++k) {
        double maxElement = tempMatrix[k][k];
        int maxIndex = k;

        for (int i = k + 1; i < n; ++i) {
            if (std::abs(tempMatrix[i][k]) > std::abs(maxElement)) {
                maxElement = tempMatrix[i][k];
                maxIndex = i;
            }
        }

        if (maxIndex != k) {
            std::swap(tempMatrix[k], tempMatrix[maxIndex]);
            std::swap(identity[k], identity[maxIndex]);
        }

        for (int i = k + 1; i < n; ++i) {
            double factor = tempMatrix[i][k] / tempMatrix[k][k];
            for (int j = k; j < n; ++j) {
                tempMatrix[i][j] -= factor * tempMatrix[k][j];
            }
            for (int j = 0; j < n; ++j) {
                identity[i][j] -= factor * identity[k][j];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        Eigenpair eigenpair;
        eigenpair.eigenvalue = tempMatrix[i][i];
        eigenpair.eigenvector = identity[i];
        eigenpairs.push_back(eigenpair);
    }

    return eigenpairs;
}

int main() {
    std::vector<std::vector<double>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::vector<Eigenpair> eigenpairs = findEigenpairs(matrix);

    // Display the eigenvalues and eigenvectors
    for (const auto& eigenpair : eigenpairs) {
        std::cout << "Eigenvalue: " << eigenpair.eigenvalue << std::endl;
        std::cout << "Eigenvector: ";
        for (double element : eigenpair.eigenvector) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
