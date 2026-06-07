//
// Created by Aya on 2026-06-05.
//
#pragma once
#include "AVLTree.h"

template <typename T>
AVLTree<T>::AVLTree()
{
    this->root =  nullptr;
}

template <typename T>
int AVLTree<T>::getBalanceFactor(BTNode<T>*& node)
{
    if (node == nullptr)
    {
        return 0;
    }
   return height(node->left) - height(node->right);
}
template <typename T>
int AVLTree<T>::height(BTNode<T>*& node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->height;
}

template <typename T>
BTNode<T>* AVLTree<T>::maxValueNode(BTNode<T>*& node)
{
     BTNode<T>* current  = node;
    while (current->right != nullptr)
    {
        current = current->right;
    }
    return current;
}

template <typename T>
BTNode<T>* AVLTree<T>::minValueNode(BTNode<T>*& node)
{
    BTNode<T>* current  = node;
    while (current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}


template <typename T>
BTNode<T>* AVLTree<T>::rotateLeft(BTNode<T>* &node)
{
    BTNode<T>* current = node->right;
    BTNode<T>* temp = current->left;
    current->left = node;
    node->right = temp;
    node->height = 1+ max(height(node->left) , height(node->right));
    current->height = 1+ max(height(current->left) , height(current->right));
    return current;
}
template <typename T>
BTNode<T>* AVLTree<T>::rotateRight(BTNode<T>*& node)
{
   BTNode<T>* current = node->left;
    BTNode<T>* temp = current->right;
    current->right= node;
    node->left= temp;
    node->height = 1+ max(height(node->left) , height(node->right));
    current->height = 1+ max(height(current->left) , height(current->right));
    return current;
}

template <typename T>
BTNode<T>* AVLTree<T>::leftRightRotate(BTNode<T>*& node)
{
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}
template <typename T>
BTNode<T>* AVLTree<T>::rightLeftRotate(BTNode<T>*& node)
{
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

template <typename T>
BTNode<T>* AVLTree<T>::rebalance(BTNode<T>*& node)
{
    int balance = getBalanceFactor(node);
    if (balance > 1 )
    {
        if (getBalanceFactor(node->left) < 0)
        {
             return leftRightRotate(node);
        }
        if (getBalanceFactor(node->left) >= 0)
        {
            return  rotateRight(node);
        }
    }
    else if (balance < -1)
    {
        if (getBalanceFactor(node->right) > 0)
        {
            return rightLeftRotate(node);
        }
        if (getBalanceFactor(node->right) <= 0)
        {
           return  rotateLeft(node);
        }
    }
    return  node;
}

template <typename T>
BTNode<T>* AVLTree<T>::insertIntoAVL(BTNode<T>* &node, const T& value)
{
    if (node == nullptr)
    {
         node = new BTNode<T>;
        node->left = nullptr;
        node->right = nullptr;
        node->height = 1;
        node->info = value;
    }
    else if (value < node->info)
    {
        node->left = insertIntoAVL(node->left , value);
    }
    else if (value > node->info)
    {
        node->right = insertIntoAVL(node->right , value);
    }
    node->height = 1+ (max(height(node->left) , height(node->right)));

    return rebalance(node);
}

template <typename T>
void AVLTree<T>::insert(T value)
{
    this->root = insertIntoAVL(this->root  , value );
}



template <typename T>
void AVLTree<T>::removeNode(T value)
{
    this->root=deleteFromTree(this->root , value );
}
template <typename T>
BTNode<T>* AVLTree<T>::deleteFromTree(BTNode<T>* & node , const T& value)
{
    BTNode<T>* temp;
   if (node == nullptr)
   {
       return node;
   }
    if (value < node->info)
    {
        node->left = deleteFromTree(node->left , value);
    }
    else if (value > node->info)
    {
        node->right = deleteFromTree(node->right , value);
    }
    else
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            delete node ;
            return nullptr;
        }
        if (node->left == nullptr)
        {
            temp = node->right;
            delete node;
            return temp;
        }
        if ( node->right == nullptr)
        {
            temp = node->left;
            delete node;
            return temp;
        }

        temp = minValueNode(node->right);
        node->info = temp->info;
        node->right = deleteFromTree(node->right , temp->info);
    }
    if (node == nullptr)
    {
        return  node;
    }

    node->height = 1+max(height(node->left) , height(node->right));
    return rebalance(node);
}

template <typename T>
T AVLTree<T>::maxValue()
{
    return maxValueNode(this->root)->info;
}
template <typename T>
T AVLTree<T>::minValue()
{
    return minValueNode(this->root)->info;
}

