#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>

template <typename T>
struct box {T data; box *next;};

/*Поставете тук реализация на функцията fillGaps*/
template <typename T>
void fillGaps(box<T> *head) {

    if (head == nullptr || head->next == nullptr) {
        return;
    }

    box <T> *prev = head;
    box<T> *curr = head->next;

    while (curr != nullptr) {
        if (curr->data - prev->data > 1) {
            prev->next = new box<T>{prev->data + 1, prev->next};
            prev = prev->next;
        }
        else{
            prev = curr;
            curr = curr->next;    
        }
        
    }
}

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
void clear(box<T> *&head) {

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

TEST_CASE("fillGaps basic")
{
    box<int> *l1 = new box<int>{1,
                         new box<int>{3,
                             new box<int>{5,nullptr}}};

    fillGaps(l1);
    for (int i = 1; i <= 5; ++i)
    {
        CHECK(l1->data == i);
        l1 = l1->next;
    }
}

TEST_CASE("fillGaps edges")
{

    box<int> *l2 = new box<int>{1,nullptr};
    fillGaps(l2);
    CHECK(l2->next == nullptr);

    CHECK_NOTHROW(fillGaps<int>(nullptr));
}

int main()
{

    //doctest::Context().run();
    // box<int> *l1 = new box<int> {1, new box<int> {3, new box<int> {4, new box<int> {8, nullptr}}}};
    // fillGaps(l1);
    // printList(l1);

    // clear(l1);

    return 0;
}

