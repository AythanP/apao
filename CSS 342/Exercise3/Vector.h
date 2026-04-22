#ifndef Vector2d_H
#define Vector2d_H

class Vector2d {
    double x;
    double y;
    
    public:
        Vector2d();
        Vector2d(double otherX, double otherY);
        Vector2d(const Vector2d& other);
        ~Vector2d();

        inline double getX() const {return x;}
        inline double getY()const {return y;}
        inline void setX(const double &newX){x = newX;}
        inline void setY(const double &newY) {y = newY;}

        Vector2d& operator=(const Vector2d& other);

        // addition: a1 + b1, a2 + b2
        Vector2d operator+(const Vector2d& b) const;

        // scalar multiplication: k * a1, k * a2
        Vector2d operator*(const double scalar) const;

        // dot product: a1 * b1 + a2 * b2
        double operator*(const Vector2d& b) const;

        void printInfo();
};

#endif