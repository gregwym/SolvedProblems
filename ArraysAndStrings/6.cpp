/*
 * Given an image represented by an NxN matrix, where each pixel in the image
 * is 4 bytes, write a method to rotate the image by 90 degrees. Can you do
 * this in place?
 */

#include <iostream>

using namespace std;

inline int indexFor(int x, int y, int dimension) {
  return y * dimension + x;
}

inline int rotate90Index(int i, int dimension) {
  int x = i % dimension;
  int y = i / dimension;
  return indexFor(dimension - y - 1, x, dimension);
}

void rotate90(int *img, int dimension) {
  for (int i = 0; i < dimension / 2; ++i)
  {
    for (int j = i; j < dimension - i - 1; ++j)
    {
      int from = indexFor(j, i, dimension);
      int pixel = img[from];
      for (int k = 0; k < 4; ++k)
      {
        int to = rotate90Index(from, dimension);
        int temp = img[to];
        img[to] = pixel;
        from = to;
        pixel = temp;
      }
    }
  }
}

int main() {
  int dimension = 4;
  int img[dimension * dimension];
  for (int i = 0; i < dimension; ++i)
  {
    for (int j = 0; j < dimension; ++j)
    {
      img[indexFor(j, i, dimension)] = i;
    }
  }

  rotate90(img, dimension);
  for (int i = 0; i < dimension; ++i)
  {
    for (int j = 0; j < dimension; ++j)
    {
      cout << img[indexFor(j, i, dimension)];
    }
    cout << endl;
  }
  return 0;
}
