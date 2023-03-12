#include <iostream>
#include "toDottyFuncs.h"

template <typename T>
void printNodesAtLevel(Node<T> *root, int k) {

    if (root == nullptr || k < 0) {
        return;
    }

    if (k == 0) {
        std::cout << root->data << '\n';
        return;
    }

    printNodesAtLevel(root->left, k - 1);
    printNodesAtLevel(root->right, k - 1);
}


int main() {

    Node<int>* root = new Node<int>{4, 
                    new Node<int>{2, 
                        new Node<int>{1, nullptr, nullptr}, 
                        new Node<int>{3, nullptr, nullptr}}, 
                    new Node<int>{5, nullptr, nullptr}};

    printNodesAtLevel(root, 10);

    return 0;
}