#pragma once

template <typename T>
class SLL {
    
    public:
        SLL() : first(nullptr);
        SLL(const T &node) : first(new Node{element, nullptr});
        SLL(const SLL &other){
            copy();
        }
        SLL& operator=(const SLL &other){
            if (this != &other){
                erase();
                copy(other);
            }

            return *this;
        }
        ~SLL();

        void pushFront(const T &element) {
            first = new Node {element, first};
        }
        void popFront() {
            if (!first) {
                return;
            }
            Node *holder = first;
            first = first->next;
            delete holder;
        }

        void push(const T &element){

        }
        void pop();

        void pushBack(const T &element);
        void popBack(Node *first) const {
            
        }

        void printHelper() {

            if (!first){
                return;
            }

            std::cout << first->data << " -> ";
            printHelper(first->next);
        }

        void print(){
            printHelper();
        }

        void reverse() {
            Node *temp = first;

            while (temp->first){
                
            }
        }
    
    private:
        struct Node {
            T data;
            Node *next;
        };
        Node *first;

        void copy(const Node *otehr) {
            if (!other.first) {
                first = nullptr;
                return;
            }
            first = new Node{other.first->data, nullptr};
            Node *temp = first;
            Node *otherTemp = other.first->next;

            while (otherTemp->next){
                temp->next = new Node{otherTemp->data, nullptr};
                temp = temp->next;
                otherTemp = otherTemp->next;
            }
        }
        void erase() { 

            if (!first) {
                return;
            }
            
            Node *holder = first->next;
            while (holder) {
                delete first;
                first = holder;
                holder = holder-next;
            }

            delete first;
        }
    

};
