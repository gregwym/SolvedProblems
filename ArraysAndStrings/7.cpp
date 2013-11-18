/*
 * Write an algorithm such that if an element in an MxN matrix is 0, its entire
 * row and column are set to 0.
 */

#include <iostream>

using namespace std;

void clearRowAndColumn(int *matrix, int dimension) {
  bool rows[dimension];
  bool columns[dimension];

  for (int i = 0; i < dimension; ++i)
  {
    rows[i] = false;
    columns[i] = false;
  }

  for (int i = 0; i < dimension; ++i)
  {
    for (int j = 0; j < dimension; ++j)
    {
      if (matrix[i * dimension + j] == 0)
      {
        rows[i] = true;
        columns[j] = true;
      }
    }
  }

  for (int i = 0; i < dimension; ++i)
  {
    for (int j = 0; j < dimension; ++j)
    {
      if (rows[i] || columns[j])
      {
        matrix[i * dimension + j] = 0;
      }
    }
  }
}

int main() {

}
