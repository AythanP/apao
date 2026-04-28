#include "Matrix.h"
#include <stdexcept>
#include <cmath>
#include <iostream>

using namespace std;

Matrix::Matrix() {
    rows = 3;
    columns = 3;
    array = new double*[rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new double[columns]();
    }
}
Matrix::Matrix(int newRows, int newColumns) {
    rows = newRows;
    columns = newColumns;
    array = new double*[rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new double[columns]();
    }
}
Matrix::Matrix(const Matrix &other) {
    if (this != &other) {
        rows = other.rows;
        columns = other.columns;
        array = new double*[rows];
        for (int i = 0; i < rows; i++) {
            array[i] = new double[columns];
            for (int j = 0; j < columns; j++) {
                array[i][j] = other.array[i][j];
            }
        }
    }
}
Matrix::~Matrix() {
    clear();
}

int Matrix::getRows() const {
    return rows;
}
int Matrix::getColumns() const {
    return columns;
}
double Matrix::getValueAt(int i, int j) const {
    if (i < 0) {
        throw std::out_of_range("Error: trying to access a negative row index for a matrix.");
    } else if (i >= rows) {
        throw std::out_of_range("Error: trying to access an out of bounds row index for a matrix.");
    } else if (j < 0) {
        throw std::out_of_range("Error: trying to access a negative column index for a matrix.");
    } else if (j >= columns) {
        throw std::out_of_range("Error: trying to access an out of bounds column index for a matrix.");
    }
    return array[i][j];
}
void Matrix::setValueAt(int i, int j, double value) {
    if (i < 0) {
        throw std::out_of_range("Error: trying to access a negative row index for a matrix.");
    } else if (i >= rows) {
        throw std::out_of_range("Error: trying to access an out of bounds row index for a matrix.");
    } else if (j < 0) {
        throw std::out_of_range("Error: trying to access a negative column index for a matrix.");
    } else if (j >= columns) {
        throw std::out_of_range("Error: trying to access an out of bounds column index for a matrix.");
    }
    array[i][j] = value;
}

// Frobenius norm: square every number in the matrix, add them all up, then take the square root
double Matrix::frobeniusNorm() const {
    double magnitude = 0.0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            magnitude += pow(array[i][j], 2);
        }
    }
    magnitude = sqrt(magnitude);
    return magnitude;
}

// Trace of a matrix: Given a matrix, A:
// a11 + a22 + ... + amn, where m is rows and n is columns, and m and n are equal to each other.
// Only works on square matrices, aka rows has to equal columns.
// Outputs a number.
double Matrix::traceOfAMatrix() const {
    if (rows != columns) {
        throw invalid_argument("Error: Could not the find trace of a non-square Matrix.");
    }
    double trace = 0;
    for (int i = 0; i < rows; i++) {
        trace += array[i][i];
    }
    return trace;
}

// Transpose of a matrix: the rows of a matrix becomes its columns, and vice versa.
// The same applies to its values. All the row values become sorted into columns, and all the column values become sorted into rows.
Matrix Matrix::transpose() const {
    Matrix transposed(columns, rows);
    for (int i = 0; i < transposed.rows; i++) {
        for (int j = 0; j < transposed.columns; j++) {
            transposed.array[i][j] = array[j][i];
        }
    }

    return transposed;
}

// Matrix Multiplication: Given a matrix, A, and a matrix, B, the output, matrix C:
// c11 = a11*b11 + a12*b21 + a13*b31 + ... + a1n*bm1
// c12 = a11*b12 + a12*b22 + a13*b32 + ... + a1n*bm2
// The number of columns in the first matrix, A, must equal the number of rows in the second matrix, B. 
// Result: a matrix, C, with the same number of rows as A and the same number of columns as B.
// The element in the ith row and jth column of C is the dot product between the ith row of A and the jth column of B.
Matrix Matrix::operator*(const Matrix& B) const {
    if (columns != B.rows) {
        throw invalid_argument("Error: The left-hand matrix's number of columns does not equal the right-hand matrix's number of rows, making matrix multiplication impossible.");
    }
    Matrix C(rows, B.columns);
    for (int i = 0; i < C.rows; i++) {
        for (int j = 0; j < C.columns; j++) {
            double elementC = 0.0;
            for (int h = 0; h < columns; h++) {
                elementC += (array[i][h] * B.array[h][j]);
            }
            C.setValueAt(i, j, elementC);
        }
    }
    return C;
}

// Matrix-Vector product: Given a matrix, A, and a vector, x:
// a11*x1 + a12*x2 + ... + a1n*xn
// a21*x1 + a22*x2 + ... + a2n*xn
// ...
// am1*x1 + am2*x2 + .. + amn*xn
// where m is rows and n is columns.
// The product is supposed to have the same number of elements as there are rows in the original matrix.
// Only works when each row in the matrix has the same number of elements as the vector.
Vector Matrix::operator*(const Vector& vector) const {
    if (columns != vector.getSize()) {
        throw invalid_argument("Error: The number of columns in the matrix is not equal to the number elements in the vector, making matrix-vector multiplication impossible.");
    }
    Vector product(rows);
    for (int i = 0; i < rows; i++) {
        double element = 0.0;
        for (int j = 0; j < columns; j++) {
            element += (array[i][j] * vector.getValueAt(j));
        }
        product.setValueAt(i, element);
    }
    return product;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        clear();
        rows = other.rows;
        columns = other.columns;
        array = new double*[rows];
        for (int i = 0; i < rows; i++) {
            array[i] = new double[columns];
            for (int j = 0; j < columns; j++) {
                array[i][j] = other.array[i][j];
            }
        }
    }
    return *this;
}

void Matrix::printInfo() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Matrix::clear() {
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
    array = nullptr;
}