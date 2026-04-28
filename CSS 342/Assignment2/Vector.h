#ifndef Vector_H
#define Vector_H

class Vector {
    private: 
        int size;
        double* array;
    public:
        Vector();
        Vector(int newSize);
        Vector(const Vector& other);
        ~Vector();

        int getSize() const;
        double getValueAt(const int& i) const;
        void setValueAt(const int& i, double& value);

        double euclideanNorm() const;
        Vector& operator=(const Vector& other);
        double operator*(const Vector& other) const;

        void printInfo() const;
        void clear();
};

#endif