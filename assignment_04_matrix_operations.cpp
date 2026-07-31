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

#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 10;

// Helper function to print a matrix neatly formatted in a grid
void printMatrix(const int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

// Function to read values into a matrix from the user
void readMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "  Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

// PART A — Transpose Matrix A (rows x cols) into result (cols x rows)
void transposeMatrix(const int src[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[j][i] = src[i][j];
        }
    }
}

// PART B — Add Matrices A and B (rows x cols) into result (rows x cols)
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// PART C — Multiply Matrix A (M x N) and Matrix B (N x P) into result (M x P)
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int M, int N, int P) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < P; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[MAX_SIZE][MAX_SIZE];
    int B[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    cout << "=== PART A: MATRIX TRANSPOSE ===" << endl;
    int rA, cA;
    cout << "Enter number of rows: ";
    cin >> rA;
    cout << "Enter number of columns: ";
    cin >> cA;

    if (rA > 0 && rA <= MAX_SIZE && cA > 0 && cA <= MAX_SIZE) {
        cout << "Enter elements for Matrix A:" << endl;
        readMatrix(A, rA, cA);

        cout << "\nOriginal Matrix A:" << endl;
        printMatrix(A, rA, cA);

        transposeMatrix(A, result, rA, cA);
        cout << "\nTransposed Matrix:" << endl;
        printMatrix(result, cA, rA);
    } else {
        cout << "Error: Invalid dimensions!" << endl;
        return 1;
    }

    cout << "\n=== PART B: MATRIX ADDITION ===" << endl;
    cout << "Reading Matrix B (same dimensions " << rA << "x" << cA << "):" << endl;
    readMatrix(B, rA, cA);

    cout << "\nMatrix B:" << endl;
    printMatrix(B, rA, cA);

    addMatrices(A, B, result, rA, cA);
    cout << "\nSum (A + B):" << endl;
    printMatrix(result, rA, cA);

    cout << "\n=== PART C: MATRIX MULTIPLICATION ===" << endl;
    int rB, cB;
    cout << "Enter rows for Matrix B: ";
    cin >> rB;
    cout << "Enter columns for Matrix B: ";
    cin >> cB;

    if (cA != rB) {
        cout << "Error: Multiplication impossible! Columns of A (" << cA 
             << ") must equal rows of B (" << rB << ")." << endl;
    } else if (rB > 0 && rB <= MAX_SIZE && cB > 0 && cB <= MAX_SIZE) {
        cout << "Enter elements for Matrix B:" << endl;
        readMatrix(B, rB, cB);

        cout << "\nMatrix A (" << rA << "x" << cA << "):" << endl;
        printMatrix(A, rA, cA);

        cout << "\nMatrix B (" << rB << "x" << cB << "):" << endl;
        printMatrix(B, rB, cB);

        multiplyMatrices(A, B, result, rA, cA, cB);
        cout << "\nProduct (A x B) (" << rA << "x" << cB << "):" << endl;
        printMatrix(result, rA, cB);
    }

    return 0;
}