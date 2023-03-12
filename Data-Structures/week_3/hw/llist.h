#pragma once

template <typename T>
class ListIterator;

template <typename T>
class LList
{
    public:

        using value_type = T;
        using iterator = ListIterator<T>;

        LList();
        LList(const LList<T>&);

        void push(const T&);
        void print() const;

        T& operator[] (size_t i);
        T operator[] (size_t i) const;

        ListIterator<T> begin() const;
        ListIterator<T> end() const;

        LList<T>& operator= (const LList<T>&);

        size_t size() const;

        ~LList();

        void clear();

        struct box
        {
            T data;
            box* next;
        };

    private:

        box* first = nullptr;

        void copy(box*);
        
        box* copy2(box*);

};

template <typename T>
class ListIterator
{
    
    public:
    //TBD::refactor this!!!!!!!!
    ListIterator(typename LList<T>::box *first);

    T& operator*();
    ListIterator<T>& operator++();
    bool operator!=(const ListIterator<T>&) const;
    
    private:
    typename LList<T>::box *current;
};


template <typename Container>
typename Container::value_type sum (const Container &l)
{
    typename Container::value_type sum = 0;
    for (typename Container::iterator i = l.begin(); 
         i != l.end(); 
         ++i)
    {   
        sum += *i;
    }

    return sum;
}

template <typename Container>
void map(Container &l, int (*f)(int x)) {

    for (typename Container::iterator i = l.begin(); 
         i != l.end(); 
         ++i)
    {   
        *i = f(*i);
    }

}

template <typename Container>
bool duplicates(const Container &l) {

    
    for (typename Container::iterator i = l.begin(); // 1 2 3 4 5 6 7
         i != l.end(); 
         ++i)
    {   
        for (typename Container::iterator j = l.begin(); 
         j != l.end(); 
         ++j)
        {   
            if (i != j && *i == *j) {
                return true;
            }
        } 
    }

    return false;    
}


template <typename Container>
bool is_sorted(const Container &l) {

    for (typename Container::iterator i = l.begin(); // 1 2 3 4 5 6 7 - y
         i != l.end();                               // 9 3 1 8 2 10 45 - n
         ++i)
    {   
        for (typename Container::iterator j = i + 1; 
         j != l.end() - 1; 
         ++j)
        {   
            if (*i >= *j) {
                return false;
            }
        } 
    }
}
