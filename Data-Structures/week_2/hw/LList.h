#ifndef __LLIST_H__
#define __LLIST_H__


template <typename T>
class LList {

    public:
        LList();
        LList(int x, int y);
        LList(const LList<T> &other);
        LList<T>& operator=(const LList<T> &other);
        ~LList(); 

        T& operator[](size_t i);
        T operator[](size_t i) const;

        size_t size() const;
        int count(int x) const;

        void pushBack(const T &elem);
        LList<T>& operator+=(const T &elem);
        void append(const LList<T> &other);

    private:

        struct Node {
            T data;
            Node *next;
        };

        Node *first;  

        void copy(const LList<T>::Node *otherFirst);
        void clear();
};

#include "LList.inl"

#endif