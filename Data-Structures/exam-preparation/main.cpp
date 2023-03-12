#include <iostream>

struct Node {
    int data;
    Node* next;
};


// task 1


void split(Node *head, Node *&left, Node *&right) {

    if (head == nullptr) {
        return;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
    }

    left = head;
    right = slow->next;
    slow->next = nullptr;
}


Node *mergeSorted(Node *&left, Node *&right) {
    if (left == nullptr){
        return right;
    }

    if (right == nullptr) {
        return left;
    }

    if (left->data <= right->data) {
        return new Node {left->data, mergeSorted(left->next, right)};
    }
    else{
        return new Node {right->data, mergeSorted(left, right->next)};
    }
}

void mergeSort(Node *&head) {
   
    Node *left = nullptr;
    Node *right = nullptr;

    if (head == nullptr || head->next == nullptr) {
        return;
    }

    split(head, left, right);

    mergeSort(left);
    mergeSort(right);

    head = mergeSorted(left, right);
}

void printList(Node *head) {
    Node *curr = head;

    while (curr != nullptr) {
        std::cout << curr->data << "->";
        curr = curr->next;
    }

    std::cout << "nullptr\n";
}


// fib

Node* makeFib(int n) {
    int a = 0, b = 1, c;
    if( n <= 0)
        return nullptr;

    Node *head = new Node {1, nullptr};
    Node *saveHead = head;

    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        head->next = new Node{c, nullptr};
        a = b;
        b = c;
        head = head->next;
    }

    return saveHead;
}



Node *makeFibRecHelper(int n, int prev, int curr) {
    if (n == 0) {
        return nullptr;
    }

    return new Node{prev, makeFibRecHelper(--n, curr, prev+curr) };
}

Node *makeFibRec(int n) {
    if (n <= 0){
        return nullptr;
    }
    return makeFibRecHelper(n, 1, 1);
}

void fillgaps(Node *head) {

    if (head == nullptr  || head->next == nullptr) {
        return;
    }

    Node *prev = head;
    Node *curr = head->next;

    while (curr != nullptr) {

        if (curr->data - prev->data > 1) {
            prev->next = new Node {prev->data + 1, prev->next};
            prev = prev->next;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
}

void clear(Node *head) {
    
    if (head == nullptr) {
        return;
    }
    
    Node *curr = head;

    while (head != nullptr) {
        curr = head->next;
        delete head;
        head = curr;
    }
}

//1 2 3 4
//4 3 2 1

Node *reverse(Node *&head) {

    Node *prev = nullptr;
    Node *curr = head;
    Node *next = nullptr;

    while (curr != nullptr) {
        
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    head = prev;

    return head;

}

Node *copyList(Node *head) {

    if (head == nullptr) {
        return nullptr;
    }

    return new Node {head->data, copyList(head->next)};
}

void mirror(Node *&head) {

    Node *curr = head;

    while (curr->next != nullptr) {
        curr = curr->next;
    }

    Node *copyHead = copyList(head);
    curr->next = reverse(copyHead);
}

int main() {

    //Node *l1 = new Node{4, new Node{7, new Node {10, new Node {45, nullptr}}}};
    // mergeSort(l1);
    // printList(l1);

    Node *res = makeFibRec(4);
    printList(res);

    mirror(res);
    printList(res);

    // fillgaps(l1);
    // printList(l1);
    clear(res);
    return 0;
}