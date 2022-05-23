#ifndef VECTOR_INL
#define VECTOR_INL

#include "Vector.h"

template<typename Type>
Vector<Type>::Vector(const Vector<Type>& other) {
	copy(other);
}

template<typename Type>
Vector<Type>& Vector<Type>::operator=(const Vector<Type>& other) {
	if (this != &other) {
		clear();
		copy(other);
	}
}

template<typename Type>
Vector<Type>::~Vector() {
	clear();
}

template<typename Type>
void Vector<Type>::pushBack(const Type& elem) {
	if (size == capacity) {
		resize();
	}

	storage[size] = elem;
	++size;
}

template<typename Type>
void Vector<Type>::copy(const Vector<Type>& other) {
	capacity = other.capacity;
	storage = new Type[other.capacity];
	size = other.size;
}

template<typename Type>
void Vector<Type>::clear() {
	delete[] storage;
}

template<typename Type>
void Vector<Type>::resize() {
	Type* newStorage = new Type[capacity * 2];

	for (int i = 0; i < size; ++i) {
		newStorage[i] = storage[i];
	}

	delete[] storage;
	storage = newStorage;
}

#endif // !VECTOR_INL