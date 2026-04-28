#ifndef Matrix_H
#define Matrix_H

#include "Vector.h"

class Matrix {
    private:
        int rows;
        int columns;
        double** array;
    public:
        Matrix();
        Matrix(int newRows, int newColumns);
        Matrix(const Matrix& other);
        ~Matrix();

        int getRows() const;
        int getColumns() const;
        double getValueAt(int i, int j) const;
        void setValueAt(int i, int j, double value);

        double frobeniusNorm() const;
        double traceOfAMatrix() const;
        Matrix transpose() const;
        
        Matrix operator*(const Matrix& B) const;
        Vector operator*(const Vector& vector) const;
        Matrix& operator=(const Matrix& other);

        void printInfo() const;
        void clear();
};

#endif