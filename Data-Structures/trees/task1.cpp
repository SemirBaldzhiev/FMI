#include "toDottyFuncs.h"
#include <iostream>
#include <fstream>
#include <vector>

template <typename T>
void toArray(Node<T> *root, std::vector<Node<T>*> &v) {
 
    if (root == nullptr) {
        return;
    }

    toArray(root->left, v);
    v.push_back(root);
    toArray(root->right, v);
}   

template <typename T>
Node<T> *toBalancedBSTHelper(std::vector<Node<T>*> &nodes, int start, int end) {

    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;
    Node<T> *root = nodes[mid];

    root->left = toBalancedBSTHelper(nodes, start, mid - 1);
    root->right = toBalancedBSTHelper(nodes, mid + 1, end);

    return root;
}

template <typename T>
Node<T>* toBalancedBST(Node<T> *root) {
    std::vector<Node<T>*> nodes;
    toArray(root, nodes);

    return toBalancedBSTHelper(nodes, 0, nodes.size() - 1);
}

int main() {

    std::ofstream ofs("toDotty.dot");

    Node<int>* root = new Node<int>{4, 
                    new Node<int>{2, 
                        new Node<int>{1, nullptr, nullptr}, 
                        new Node<int>{3, nullptr, nullptr}}, 
                    new Node<int>{5, nullptr, nullptr}};
    
    root = toBalancedBST(root);
    toDotty(root, ofs);

    return 0;
}

