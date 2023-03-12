#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include <iostream>

template <typename T>
struct box {T data; box *next;};

/*Поставете тук реализация на функцията reverseList*/

template <typename T>
void reverseList(box<T> *&head, int n) {
    
    if (head == nullptr) {
        return;
    }

    if (n <= 0) {
        return;
    } 

    box<T> *curr = head; 
    box<T> *prev = nullptr;
    box<T> *next = nullptr;
    box<T> *saveCurr = curr;

    for (int i = 0; i < n && saveCurr != nullptr; ++i) {
        saveCurr = saveCurr->next;
        next = curr->next;
        curr->next = prev;
        
        prev = curr;
        curr = next;

    }

    box<T> *saveHead = head;

    head = prev;
    saveHead->next = saveCurr;
}

//1 2 3 4 5
//3 2 1 4 5

template <typename T>
void printList(box<T> *head) {
    box<T> *curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << "->";
        curr = curr->next;
    }

    std::cout << "nullptr\n";
}

template <typename T>
void clear(box<T> *head) {

    if (head == nullptr) {
        return;
    }
    box<T> *curr = head;
    

    while (head != nullptr) {
        curr = head->next;
        delete head;
        head = curr;
    }
}

TEST_CASE("Reverse basic")
{
    box<int> *l1 = new box<int>{1,
                         new box<int>{2,
                             new box<int>{3,
                                 new box<int>{4,
                                      new box<int>{5,
                                          new box<int>{6,
                                              new box<int>{7,
                                                  new box<int>{8,nullptr}}}}}}}};
    reverseList(l1,4);
    int expected[] = {4,3,2,1,5,6,7,8};
    for (int x: expected)
    {
        CHECK(x==l1->data);
        l1=l1->next;
    }

}

TEST_CASE("Reverse edges")
{
    box<int> *l1 = new box<int>{1, new box<int>{2,nullptr}};
    reverseList(l1,10);
    CHECK(l1->data == 2);
    CHECK(l1->next->data == 1);

    box<int> *null_ptr = nullptr;

    CHECK_NOTHROW(reverseList(l1->next,10));
    CHECK_NOTHROW(reverseList<int>(null_ptr,10));
}

int main()
{

    doctest::Context().run();
    // box<int> *l1 = new box<int> {1, new box<int> {2, new box<int> {3, new box<int> {4, new box<int> {5, nullptr}}}}};

    // reverseList(l1, 3);
    // printList(l1);
    // clear(l1);
    return 0;
}

