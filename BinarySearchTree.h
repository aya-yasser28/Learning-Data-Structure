//
// Created by Aya on 2026-05-20.
//

#ifndef LEARNING_DATA_STRUCTURE_BINARYSEARCHTREE_H
#define LEARNING_DATA_STRUCTURE_BINARYSEARCHTREE_H
#include "BinaryTree.h"

template<typename  T>
class BinarySearchTree : public BinaryTree<T>
{
public:
    bool search(T value) const;
    void virtual  removeNode(T value);//Best case: O(log n) , Worst case: O(n)
    //search for the value and pass the node to deleteFromTree to delete the node
    void virtual deleteFromTree(BTNode<T>* node); // to delete the node
    /*
    * in delete there is 3 cases :
    * 1. deleting a leaf which is easy
    * 2. deleting a node with one child
    * 3. deleting a node with two children
    */
    void virtual insert(T value);

};
#include "BinarySearchTree.tpp"

#endif //LEARNING_DATA_STRUCTURE_BINARYSEARCHTREE_H