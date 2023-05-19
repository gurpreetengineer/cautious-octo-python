#include <iostream>
#include <vector>

int determinant(const std::vector<std::vector<int>> &matrix)
{
  int n = matrix.size();

  if (n == 1)
  {
    return matrix[0][0];
  }
  else if (n == 2)
  {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
  }
  else
  {
    int det = 0;
    for (int j = 0; j < n; ++j)
    {
      std::vector<std::vector<int>> submatrix(n - 1, std::vector<int>(n - 1));

      for (int i = 1; i < n; ++i)
      {
        int k = 0;
        for (int l = 0; l < n; ++l)
        {
          if (l != j)
          {
            submatrix[i - 1][k++] = matrix[i][l];
          }
        }
      }

      det += (j % 2 == 0 ? 1 : -1) * matrix[0][j] * determinant(submatrix);
    }

    return det;
  }
}

int main()
{
  int n;
  std::cout << "Enter the size of the square matrix: ";
  std::cin >> n;

  std::vector<std::vector<int>> matrix(n, std::vector<int>(n));

  std::cout << "Enter the elements of the matrix:" << std::endl;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      std::cin >> matrix[i][j];
    }
  }

  int det = determinant(matrix);

  std::cout << "Determinant of the matrix: " << det << std::endl;

  return 0;
}
