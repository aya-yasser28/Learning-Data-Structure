//
// Created by Aya on 2026-06-05.
//

#ifndef LEARNING_DATA_STRUCTURE_AVLTREE_H
#define LEARNING_DATA_STRUCTURE_AVLTREE_H
#include "BinarySearchTree.h"
#include "BinaryTree.h"

/*
 * because the AVL tree is a binary search tree, so we inherit from its class
 * and because it also has a different implementation for insertion and  deletion
 */
template <typename T>
class AVLTree : public BinarySearchTree<T>
{
private:
    BTNode<T>* insertIntoAVL(BTNode<T>* &node , const T& value );
    BTNode<T>* deleteFromTree(BTNode<T>*& node  ,  const T& value );
    int height(BTNode<T>*& node);
    int getBalanceFactor(BTNode<T>*& node);
    // single rotations:
    BTNode<T>* rotateLeft(BTNode<T>* &node);
    BTNode<T>* rotateRight(BTNode<T>* &node);
    // double rotations:
    /*
     * if the balance factors are positive so make a single Left Rotation
     * if the balance factors are negative so make a single Right Rotation
     * if they are opposite signs then we will implement a double rotation
     */
    // -1 means the left subtree is higher  , 0 the heights are equal , 1 means the right subtree is higher
    BTNode<T>* leftRightRotate(BTNode<T>*& node);
    BTNode<T>* rightLeftRotate(BTNode<T>*& node);
    BTNode<T>* rebalance(BTNode<T>*& node);
    BTNode<T>* minValueNode(BTNode<T>*& node);
    BTNode<T>* maxValueNode(BTNode<T>*& node);
public :
    AVLTree();
    void insert(T value);
    void removeNode(T value);
    T minValue();
    T maxValue();

};
#include "AVLTree.tpp"

#endif //LEARNING_DATA_STRUCTURE_AVLTREE_H