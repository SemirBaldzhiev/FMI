#include <iostream>
#include <fstream>
#include "toDottyFuncs.h"

template <typename T>
void invertBT(Node<T> *&root) {

    if (root == nullptr) {
         return;
    }

    Node<T> *temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertBT(root->left);
    invertBT(root->right);
}



template <typename T>
Node<T>* invertBT2(Node<T> *root) {

    if (root == nullptr) {
         return nullptr;
    }

    Node<T> *l = invertBT(root->left);
    Node<T> *r = invertBT(root->right);
    root->left = r;
    root->right = l;
    
    return root;
}

template <typename T>
void printLeftNodes(Node<T> *root, int level, )

int main() {

    std::ofstream ofs("toDotty.dot");
    std::ofstream ofs2("toDottyPrev.dot");

    
    Node<int>* root = new Node<int>{4, 
                    new Node<int>{2, 
                        new Node<int>{1, nullptr, nullptr}, 
                        new Node<int>{3, nullptr, nullptr}}, 
                    new Node<int>{5, nullptr, nullptr}};
    toDotty(root, ofs2);
    invertBT(root);
    toDotty(root, ofs);
    return 0;
}