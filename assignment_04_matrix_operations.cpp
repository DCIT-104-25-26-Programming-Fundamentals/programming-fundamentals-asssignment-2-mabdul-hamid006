// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Reads values into a matrix from user input
void readMatrix(int mat[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

// Displays a matrix neatly using setw() for alignment
void displayMatrix(int mat[10][10], int rows, int cols, string label) {
    cout << label << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

// PART A: Computes the transpose of a matrix
void transposeMatrix(int mat[10][10], int rows, int cols, int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

// PART B: Adds two matrices element-wise
void addMatrices(int a[10][10], int b[10][10], int rows, int cols, int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// PART C: Multiplies matrix A (rowsA x colsA) by matrix B (colsA x colsB)
void multiplyMatrices(int a[10][10], int b[10][10], int rowsA, int colsA, int colsB, int result[10][10]) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            int sum = 0;
            for (int k = 0; k < colsA; k++) {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
}

int main() {
    int rows, cols;

    // -------------------------------------------------------------------
    // PART A - Transpose
    // -------------------------------------------------------------------
    cout << "=== PART A: Transpose a Matrix ===" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int matrixA[10][10];
    readMatrix(matrixA, rows, cols);

    int transposed[10][10];
    transposeMatrix(matrixA, rows, cols, transposed);

    cout << endl;
    displayMatrix(matrixA, rows, cols, "Original Matrix:");
    cout << endl;
    displayMatrix(transposed, cols, rows, "Transposed Matrix:");

    // -------------------------------------------------------------------
    // PART B - Addition
    // -------------------------------------------------------------------
    cout << endl << "=== PART B: Add Two Matrices ===" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int matB1[10][10], matB2[10][10], sumResult[10][10];

    cout << "Enter values for Matrix 1:" << endl;
    readMatrix(matB1, rows, cols);
    cout << "Enter values for Matrix 2:" << endl;
    readMatrix(matB2, rows, cols);

    addMatrices(matB1, matB2, rows, cols, sumResult);

    cout << endl;
    displayMatrix(matB1, rows, cols, "Matrix 1:");
    cout << endl;
    displayMatrix(matB2, rows, cols, "Matrix 2:");
    cout << endl;
    displayMatrix(sumResult, rows, cols, "Sum:");

    // -------------------------------------------------------------------
    // PART C - Multiplication
    // -------------------------------------------------------------------
    int rowsA, colsA, rowsB, colsB;

    cout << endl << "=== PART C: Multiply Two Matrices ===" << endl;
    cout << "Enter rows for Matrix A: ";
    cin >> rowsA;
    cout << "Enter columns for Matrix A: ";
    cin >> colsA;
    cout << "Enter rows for Matrix B: ";
    cin >> rowsB;
    cout << "Enter columns for Matrix B: ";
    cin >> colsB;

    if (colsA != rowsB) {
        cout << "Error: Columns of A must equal rows of B for multiplication." << endl;
        return 0;
    }

    int matC1[10][10], matC2[10][10], productResult[10][10];

    cout << "Enter values for Matrix A:" << endl;
    readMatrix(matC1, rowsA, colsA);
    cout << "Enter values for Matrix B:" << endl;
    readMatrix(matC2, rowsB, colsB);

    multiplyMatrices(matC1, matC2, rowsA, colsA, colsB, productResult);

    cout << endl;
    displayMatrix(matC1, rowsA, colsA, "Matrix A:");
    cout << endl;
    displayMatrix(matC2, rowsB, colsB, "Matrix B:");
    cout << endl;
    displayMatrix(productResult, rowsA, colsB, "Product (A x B):");

    return 0;
}