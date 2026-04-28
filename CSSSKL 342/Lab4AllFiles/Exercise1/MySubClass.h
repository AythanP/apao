#ifndef MySubClass_H
#define MySubClass_H

#include "MyClass.h"

class MySubClass : public MyClass {
    private: 
        int subClassData;
    public:
        MySubClass();
        MySubClass(const MySubClass& other);

        int getSubClassData() const;
        void setSubClassData(const int newSubClassData);

        MySubClass& operator=(const MySubClass& other);
};

#endif