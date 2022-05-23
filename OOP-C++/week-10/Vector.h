//
// Created by User on 5/19/2022.
//

#ifndef WEEK_10_VECTOR_H
#define WEEK_10_VECTOR_H

class Vector {
public:
    Vector();
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    ~Vector();

    void add(const int elem);
    int& operator[](int index);
    const int& operator[](int index) const;
    const Vector operator+(const Vector& lhs, const Vector& rhs);
    Vector& operator+=(const Vector& other);

private:
    int* elements;

};

#endif //WEEK_10_VECTOR_H
