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
    void insertIntoAVL(BTNode<T>* &node ,BTNode<T>* newNode , bool& isTaller);
    void deleteFromTree(BTNode<T>*& node  , T value , bool& isShorter);
    void deleteNode(BTNode<T>* & node , bool& isShorter);
    // single rotations:
    void rotateLeft(BTNode<T>* &node);
    void rotateRight(BTNode<T>* &node);
    // double rotations:
    /*
     * if the balance factors are positive so make a single Left Rotation
     * if the balance factors are negative so make a single Right Rotation
     * if they are opposite signs then we will implement a double rotation
     */
    // -1 means the left subtree is higher  , 0 the heights are equal , 1 means the right subtree is higher
    void balanceFromLeft(BTNode<T>* & node); //this function will be called if the node's balance factor is -1

    void balanceFromRight(BTNode<T>* & node); // this function will be called if the node's balance factor is 1
   void balanceFromLeftDeletion(BTNode<T>*& node , bool& isShorter);
    void balanceFromRightDeletion(BTNode<T>*& node , bool&isShorter);
public :
    AVLTree();
    void insert(T value);
    void removeNode(T value);


};
#include "AVLTree.tpp"

#endif //LEARNING_DATA_STRUCTURE_AVLTREE_H