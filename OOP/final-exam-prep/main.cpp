#include <iostream>

class Vector {
    public:
        Vector(const double* elems, int size);
        Vector(const Vector& other);
        Vector& operator=(const Vector& other);
        ~Vector();

        double operator[](int index) const;  
        Vector& operator+=(const Vector& rhs);
        Vector& operator-=(const Vector& rhs);
        Vector& operator*=(double num);
        Vector& operator/=(double num);
        double operator%(const Vector& rhs);

    private:
        double* elements;
        int size;

        void resize(int newSize);
};

void Vector::resize(int newSize) {
    size = newSize;
    double* newElements = new double[newSize];
    int i;
    for (i = 0; i < size; ++i) {
        newElements[i] = elements[i];
    }

    for (;i < newSize; ++i) {
        newElements[i] = 0;
    }

    delete elements;
    elements = newElements;
}

Vector::Vector(const double elems[], int size) {
    
    elements = new double[size];

    for (int i = 0; i < size; ++i) {
        elements[i] = elems[i];
    }
}

Vector::Vector(const Vector& other) {
    elements = new double[other.size];
    size = other.size;

    for (int i = 0;i < size; ++i) {
        elements[i] = other.elements[i];
    }
}

Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        delete[] elements;
        size = other.size;
        elements = new double[size];
        for (int i = 0; i < size; ++i) {
            elements[i] = other.elements[i];
        }
    } 

    return *this;
}


Vector::~Vector() {
    delete[] elements;
}



double Vector::operator[](int index) const {
    if (index >= 0 && index < size) {
        return elements[index];
    }

    return 0;
}

Vector& Vector::operator+=(const Vector& rhs) {
    
    if (size > rhs.size) {
        const_cast<Vector&>(rhs).resize(size);
    }
    else if (rhs.size > size) {
        this->resize(rhs.size);
    }

    for (int i = 0; i < size; ++i) {
        elements[i] += rhs.elements[i];
    }

    return *this;
}

Vector& Vector::operator-=(const Vector& rhs) {
    
    if (size > rhs.size) {
        const_cast<Vector&>(rhs).resize(size);
    }
    else if (rhs.size > size) {
        this->resize(rhs.size);
    }

    for (int i = 0; i < size; ++i) {
        elements[i] -= rhs.elements[i];
    }

    return *this;
}

Vector& Vector::operator*=(double num) {
    for (int i = 0; i < size; ++i) {
        elements[i] *= num;
    }

    return *this;
}

Vector& Vector::operator/=(double num) {
    for (int i = 0; i < size; ++i) {
        elements[i] /= num;
    }

    return *this;
}

const Vector operator+(const Vector& lhs, const Vector& rhs) {
    Vector res = lhs;
    res += rhs;
    return res;
}

const Vector operator-(const Vector& lhs, const Vector& rhs) {
    Vector res = lhs;
    res -= rhs;
    return res;
}

const Vector operator*(const Vector& lhs, double num) {
    Vector res = lhs;
    res *= num;
    return res;
}

const Vector operator/(const Vector& lhs, double num) {
    Vector res = lhs;
    res /= num;
    return res;
}

double Vector::operator%(const Vector& rhs) {
   
    if (size > rhs.size) {
        const_cast<Vector&>(rhs).resize(size);
    }
    else if (rhs.size > size) {
        this->resize(rhs.size);
    }
    
    double res = 0;

    for (int i = 0; i < size; ++i) {
        res += elements[i] * rhs.elements[i];
    }

    return res;
}



int main() {

    double elems1[] = {1, 2, 3, 4, 9};
    double elems2[] = {5, 6, 7, 8};


    Vector v1(elems1, 5);
    Vector v2(elems2, 4);


    double dotProd = v1 % v2;
    std::cout << dotProd << "\n";

    return 0;
}