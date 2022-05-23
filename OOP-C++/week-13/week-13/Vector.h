#ifndef VECTOR_H
#define VECTOR_H

template<typename Type>  
class Vector {

public:
	Vector() = default;
	Vector(const Vector<Type>& other);
	Vector& operator=(const Vector<Type>& other);
	~Vector();

	void pushBack(const Type& elem);

private:
	size_t capacity{};
	Type* storage{ new Type[capacity] };
	size_t size{};

	void copy(const Vector<Type>& other);
	void clear();
	void resize();
};

#include "Vector.inl"

#endif // !VECTOR_H
