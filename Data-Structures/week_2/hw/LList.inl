#include "LList.h"
#include <stdio.h>
#include <assert.h>
#include <stdexcept>
#include <exception>

template <typename T>
LList<T>::LList() : first(nullptr) {}

// task 12.2
template <typename T>
LList<T>::LList(int x, int y) {

    if (x > y) {
        throw std::invalid_argument("X should be less than Y\n");
    }
    first = nullptr;
    for (int i = x; i <= y; i++) {
        pushBack(i);
    }
}

template <typename T>
LList<T>::LList(const LList<T> &other) {
    copy(other.first);
}

template <typename T>
LList<T>& LList<T>::operator=(const LList<T> &other) {

    if (this != &other) {
        clear();
        copy(other.first);
    }

    return *this;
}

template <typename T>
LList<T>::~LList() {
    clear();
}

template <typename T>
T& LList<T>::operator[](size_t i) {
    
    LList<T>::Node* crr = first;
    for (size_t count = 0; count < i; ++count) {  
        assert(crr != nullptr);
        crr=crr->next;
    }

    return crr->data;
}

template <typename T>
T LList<T>::operator[](size_t i) const {
    LList<T>::Node* crr = first;
    for (size_t count = 0; count < i; ++count) {  
        assert(crr != nullptr);
        crr=crr->next;
    }

    return crr->data;
}


template <typename T>
size_t LList<T>::size() const {

    LList<T>::Node *crr = first;
    size_t len = 0;
    while (crr != nullptr) {
        ++len;
        crr = crr->next;
    }   

    return len;
}


// task 12.1
template <typename T>
int LList<T>::count(int x) const {

    LList<T>::Node *curr = first;
    int cnt = 0;
    while (curr != nullptr) {
        if (curr->data == x) {
            ++cnt;
        }

        curr = curr->next;
    }

    return cnt;
} 

// task 12.3
template <typename T>
void LList<T>::pushBack(const T &elem) {
    
    LList<T>::Node *newNode = new LList<T>::Node {elem, nullptr};

    if (first == nullptr) {
        first = newNode;
        return;
    }

    LList<T>::Node *curr = first;

    while (curr->next != nullptr) {
        curr = curr->next;
    }

    curr->next = newNode;
}

// task 12.4
template <typename T>
LList<T>& LList<T>::operator+=(const T &elem) {
    
    pushBack(elem);
    return *this;
}

template <typename T>
void LList<T>::clear() {
    LList<T>::Node* save = first;
    while (first != nullptr) {
        save=first->next;
        delete first;
        first=save;
    }
}

// task 12.7    
template <typename T>
void LList<T>::append(const LList<T> &other) {

    LList<T>::Node *curr = other.first;
    while (curr != nullptr) {
        pushBack(curr->data);
        curr = curr->next;
    }
}

template <typename T>
void LList<T>::copy(const LList<T>::Node *otherFirst) {
    if (otherFirst == nullptr) {
        return;
    }

    LList<T>::Node* lastCreated = nullptr;
    while (otherFirst != nullptr) {
        LList<T>::Node* newNode = new LList<T>::Node {otherFirst->data,nullptr};
        if (lastCreated != nullptr) {
            lastCreated->next = newNode;
        } else {
            first = newNode;
        }
        
        lastCreated = newNode;
        otherFirst = otherFirst->next;
    }
}


