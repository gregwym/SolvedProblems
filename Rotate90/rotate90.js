/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).
*/

/**
 * @param {number[][]} matrix, [y][x]
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    var n = matrix.length - 1;
    var squares = Math.floor( matrix.length / 2.0 );
    var i, j, tmp;
    for(i = 0; i < squares; i++) {
        for(j = 0; j < (matrix.length - i * 2 - 1); j++) {
            console.log(i, j, n);
            tmp = matrix[i][i + j]; // store top left, increase x
            matrix[i][i + j] = matrix[n - i - j][i]; // copy bottom left, decrease y
            matrix[n - i - j][i] = matrix[n - i][n - i - j]; // copy bottom right, decrease x
            matrix[n - i][n - i - j] = matrix[i + j][n - i]; // copy top right, increase y
            matrix[i + j][n - i] = tmp; // copy top left
        }
    }
};
