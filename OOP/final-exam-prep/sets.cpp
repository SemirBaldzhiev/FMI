#include <iostream>


class IntSet {

    public:
    virtual ~IntSet() {}
    virtual bool member(int x) const = 0;
    virtual int get(int index) const = 0;
    virtual bool operator<(const IntSet* set) = 0;
    virtual bool operator*(const IntSet* set) = 0;
};

class IntRange : public IntSet {
    public:
        IntRange(int start, int end) {
            this->start = start;
            this->end = end;
        }
        ~IntRange() {}

        bool member(int x) const {
            if (x >= start && x <= end) {
                return true;
            }

            return false;
        }
        int get(int index) const {   //[13..20] - 44
            int res =  start + index; // 13,14,15,16,17,18,19,20
            if (member(res)) {
                return res;
            }
            else {
                throw "Invalid index\n";
            }
        }  

        bool operator<(const IntSet* set) {
            for (int i = start; i <= end; ++i) {
                if (!set->member(i)) {
                    std::cout << i << '\n';
                    return false;
                }
            }
            std::cout << "here1" << '\n';
            return true;
        } 

        bool operator*(const IntSet* set) {
            for (int i = start; i <= end; ++i) {
                if (set->member(i)){
                    return true;
                }
            }

            return false;
        }
    private:
        int start;
        int end;
};


class ArraySet : public IntSet {
    public:
        ArraySet(int n){
            maxSize = n;
            elements = new int[maxSize];
            size = 0;
        }

        ~ArraySet() {}

        bool member(int x) const {
            for (int i = 0; i < size; ++i) {
                if (elements[i] == x) {
                    return true;
                }
            }

            return false;
        }

        int get(int index) const {
            if (index < 0 || index >= size) {
                throw "Invalid index\n";
            }
            return elements[index];
        }

        bool insert(int x) {
            if (size == maxSize) {
                return false;
            }
            elements[size] = x;
            ++size;
            return true;
        }

        bool remove(int x) {
            if (!member(x)) {
                return false;
            }
            int i;
            for (i = 0; i < size; ++i) {
                if (x == elements[i]) {
                    break;
                }
            }

            int last = elements[size - 1];
            elements[size - 1] = elements[i];
            elements[i] = last;
            --size;
            return true;
        }

        bool operator<(const IntSet* set) {
            for (int i = 0; i < size; ++i) {
                if (!set->member(elements[i])) {
                    std::cout << elements[i] << "\n";
                    return false;
                }
            }
            std::cout << "here2" << '\n';

            return true;
        }

        bool operator*(const IntSet* set) {
            for (int i = 0; i < size; ++i) {
                if (set->member(elements[i])) {
                    return true;
                }
            }

            return false;
        }

    private:
        int maxSize;
        int size;
        int* elements;

};

int main() {
    
    IntSet* rangeSet = new IntRange(10,50);
    IntSet* arraySet = new ArraySet(5);


    ArraySet* as = dynamic_cast<ArraySet*>(arraySet);

    as->insert(20);
    as->insert(23);
    as->insert(26);
    as->insert(28);
    as->insert(44);

    std::cout << std::boolalpha << rangeSet->member(5) << '\n';
    std::cout << std::boolalpha << rangeSet->member(23) << '\n';
    std::cout << std::boolalpha << arraySet->member(5) << '\n';
    std::cout << std::boolalpha << arraySet->member(20) << '\n';
    std::cout << std::boolalpha << (arraySet->operator<(rangeSet)) << '\n';
    std::cout << std::boolalpha << (arraySet->operator*(rangeSet)) << '\n';

    return 0;
}

