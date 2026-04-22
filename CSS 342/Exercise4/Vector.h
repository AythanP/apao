#ifndef Vector_H
#define Vector_H

template <typename T>
class Vector {
    private: 
        int capacity;
        T* arr;
    
    public:
        Vector();
        Vector(int capacity);
        Vector(const Vector<T>& other);
        ~Vector();

        int getCapacity() const;
        T* getArray() const;
        T& getDataAt(int i) const;
        void setDataAt(int i, T v);

        T& operator[](int i);
        T& operator=(const Vector<T>& other);
};

template <typename T>
Vector<T>::Vector() {

}
template <typename T>
Vector<T>::Vector(int newCapacity) {
    capacity = newCapacity;
    arr = new T[capacity];
}
template <typename T>
Vector<T>::Vector(const Vector<T>& other) {
    if (this != &other) {
        capacity = other.capacity;
        arr = new T[capacity];
        for (int i = 0; i < capacity; i++) {
            arr[i] = other.getDataAt(i);
        }
    }
}
template <typename T>
Vector<T>::~Vector() {
    delete[] arr;
}

template <typename T>
int Vector<T>::getCapacity() const {
    return capacity;
}
template <typename T>
T* Vector<T>::getArray() const {
    return arr;
}
template <typename T>
T& Vector<T>::getDataAt(int i) const {
    return arr[i];
}
template <typename T>
void Vector<T>::setDataAt(int i, T value) {
    arr[i] = value;
}

template <typename T>
T& Vector<T>::operator[](int i) {
    return arr[i];
}
template <typename T>
T& Vector<T>::operator=(const Vector<T>& other) {
    if (this != &other) {
        capacity = other.capacity;
        arr = new T[capacity];
        for (int i = 0; i < capacity; i++) {
            arr[i] = other.getDataAt(i);
        }
    } 

    return *this;
}

#endif