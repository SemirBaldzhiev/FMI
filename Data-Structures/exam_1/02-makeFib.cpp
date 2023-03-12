#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include <iostream>
template <typename T>
struct box {T data; box *next;};

/*Поставете тук реализация на функцията makeFib*/

template <typename T>
void makeFib(box<T> *head) {

    if (head == nullptr || head->next == nullptr) {
        return;
    }

    box<T> *prev = head;
    box<T> *curr = head->next;


    while (curr != nullptr) {
        
        if (curr->next != nullptr) {
            if (curr->next->data != prev->data + curr->data) {
                if (curr->next != nullptr) {
                    box<T> *toDelete = curr->next;
                    curr->next = curr->next->next;
                    delete toDelete;
                }            
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        } 
        else {
            break;
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

TEST_CASE("makeFib basic")
{
    box<int> *l1 = new box<int>{1,
                         new box<int>{1,
                             new box<int>{2,
                                 new box<int>{2,
                                      new box<int>{2,
                                          new box<int>{3,
                                              new box<int>{5,
                                                  new box<int>{9,nullptr}}}}}}}};
    makeFib(l1);
    int expected[] = {1,1,2,3,5};
    for (int x: expected)
    {
        CHECK(x==l1->data);
        l1=l1->next;
    }

}

TEST_CASE("makeFib edges")
{
    box<int> *l2 = new box<int>{1,nullptr};
    CHECK_NOTHROW(makeFib(l2));
    CHECK(l2->data == 1);

    box<int> *l3 = new box<int>{1,new box<int>{2,nullptr}};
    CHECK_NOTHROW(makeFib(l3));
    CHECK(l3->next->data == 2);

    CHECK_NOTHROW(makeFib<int>(nullptr));
}

//0 1 3 5 1 2
//0 1 5 1 2
//0 1 1 2
//

int main()
{

    //doctest::Context().run();
    box<int> *l1 = new box<int> {0, new box<int> {1, new box<int> {3, new box<int> {5, new box<int> {1, new box<int> {2, nullptr}}}}}};
    box<int> *l2 = new box<int> {0, new box<int> {1,nullptr}};
    box<int> *l3 = new box<int> {0, new box<int> {1, new box<int> {1, new box<int> {2, new box<int> {3, new box<int> {6, nullptr}}}}}};

    makeFib(l1);
    printList(l1);

    makeFib(l2);
    printList(l2);

    makeFib(l3);
    printList(l3);

    clear(l1);
    clear(l2);
    clear(l3);
    return 0;
}

