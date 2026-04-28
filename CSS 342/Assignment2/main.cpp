#include <iostream>
#include <limits>
#include <random>
#include "Vector.h"
#include "Matrix.h"

using namespace std;

int getInputSize(string inputMessage);
void setVectorValues(Vector& vector);
void setMatrixValues(Matrix& matrix);
double getVectorCosineSimilarity(const Vector& vector1, const Vector& vector2);

static const string getVectorSize = "Enter a positive integer greater than zero to determine the size of a vector: ";
static const string getMatrixRows = "Enter a positive integer greater than zero to determine the number of rows for a matrix: ";
static const string getMatrixColumns = "Enter a positive integer greater than zero to determine the number of columns for a matrix: ";
static random_device rd;
static default_random_engine generator(rd());
static uniform_real_distribution<double> distribution(-100, 100);

int main(int argc, char *argv[]) {
    Vector vector1(getInputSize(getVectorSize));
    setVectorValues(vector1);
    Vector vector2;
    setVectorValues(vector2);
    Vector vector3(getInputSize(getVectorSize));
    setVectorValues(vector3);

    cout << "Vector1 contents: ";
    vector1.printInfo();
    cout << "Creating a vector using the default constructor." << endl;
    cout << "Vector2 contents: ";
    vector2.printInfo();
    cout << "Vector3 contents: ";
    vector3.printInfo();

    double vector1EuclidianNorm = vector1.euclideanNorm();
    cout << "Vector1's Euclidian norm: " << vector1EuclidianNorm << endl;
    double vector2EuclidianNorm = vector2.euclideanNorm();
    cout << "Vector2's Euclidian norm: " << vector2EuclidianNorm << endl;
    double vector3EuclidianNorm = vector3.euclideanNorm();
    cout << "Vector3's Euclidian norm: " << vector3EuclidianNorm << endl;
    
    try {
        double innerProduct = vector1 * vector3;
        cout << "Vector1's and Vector3's inner product: " << innerProduct << endl;
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    try {
        double cosineSimilarity = getVectorCosineSimilarity(vector3, vector1);
        cout << "Vector3's and Vector1's cosine similarity: " << cosineSimilarity << endl;
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    try {
        cout << "Element 5 in Vector1: " << endl;
        double element5 = vector1.getValueAt(4);
        cout << element5 << endl;
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    // memory check
    vector2 = vector3;
    Vector vector4 = vector1;

    Matrix matrix1;
    setMatrixValues(matrix1);
    Matrix matrix2(getInputSize(getMatrixRows), getInputSize(getMatrixColumns));
    setMatrixValues(matrix2);
    Matrix matrix3(getInputSize(getMatrixRows), getInputSize(getMatrixColumns));
    setMatrixValues(matrix3);

    cout << "Creating a matrix using the default constructor." << endl;
    cout << "Matrix1 contents: " << endl;
    matrix1.printInfo();
    cout << "Matrix2 contents: " << endl;
    matrix2.printInfo();
    cout << "Matrix3 contents: " << endl;
    matrix3.printInfo();

    double matrix2FrobeniusNorm = matrix2.frobeniusNorm();
    cout << "Matrix2's Frobenius norm: " << matrix2FrobeniusNorm << endl;
    double matrix3FrobeniusNorm = matrix3.frobeniusNorm();
    cout << "Matrix3's Frobenius norm: " << matrix3FrobeniusNorm << endl;

    try {
        Matrix matrix4 = matrix2 * matrix3;
        cout << "Matrix4, which is the product of Matrix2 and Matrix3: " << endl;;
        for (int i = 0; i < matrix4.getRows(); i++) {
            for (int j = 0; j < matrix4.getColumns(); j++) {
                double element = matrix4.getValueAt(i, j);
                cout << element << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    try {
        cout << "Vector4, which is the product of Matrix3 mulitplied by Vector2: " << endl;
        Vector vector4 = matrix3 * vector2;
        for (int i = 0; i < vector4.getSize(); i++) {
            double element = vector4.getValueAt(i);
            cout << element << " ";
        }
        cout << endl;
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    try {
        cout << "Vector5, which is the product of Matrix2 mulitplied by Vector3: " << endl;
        Vector vector5 = matrix2 * vector3;
        for (int i = 0; i < vector5.getSize(); i++) {
            double element = vector5.getValueAt(i);
            cout << element << " ";
        }
        cout << endl;
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    try {
        cout << "Trace of Matrix3: " << endl;
        double trace = matrix3.traceOfAMatrix();
        cout << trace << endl;
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    Matrix matrix5;
    matrix5 = matrix2.transpose();
    cout << "The transpose of Matrix2: " << endl;
    matrix5.printInfo();

    return 0;
}

// function to prompt user for input
// neither a vector nor a matrix can have any of its dimensions be less than 1
int getInputSize(string inputMessage) {
    int size = 0;
    do {
        cout << inputMessage << endl;
        cin >> size;
        if (size < 1) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again." << endl;
        }
    }
    while(cin.fail() || size < 1);

    return size;
}

// function to fill in a vector
void setVectorValues(Vector& vector) {
    for (int i = 0; i < vector.getSize(); i++) {
        double value = distribution(generator);
        vector.setValueAt(i, value);
    }
}

// function to fill in a matrix
void setMatrixValues(Matrix& matrix) {
    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getColumns(); j++) {
            double value = distribution(generator);
            matrix.setValueAt(i, j, value);
        }
    }
}

// function to find the cosine similarity of two vectors
double getVectorCosineSimilarity(const Vector& vector1, const Vector& vector2) {
    if (vector1.euclideanNorm() == 0) {
        throw invalid_argument("Error: the left-hand vector's Euclidian norm is zero, and division by zero is not allowed.");
    } else if (vector2.euclideanNorm() == 0) {
        throw invalid_argument("Error: the right-hand vector Euclidian norm is zero, and division by zero is not allowed.");
    }
    return (vector1 * vector2) / (vector1.euclideanNorm() * vector2.euclideanNorm());
}