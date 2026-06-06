//
// Created by Aya on 2026-05-20.
//
#pragma once


#include "BinaryTree.h"

#include <algorithm>
#include<iostream>
#include <queue>
using namespace std;

//======================public methods =================================
template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& other)
{
    if (other.root == nullptr)
    {
        root = nullptr;
    }
    else
    {
        copyTree(root , other.root);
    }
}
template <typename T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}
template <typename T>
const BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& BT)
{
    if (this != BT)
    {
       if (root != nullptr)
       {
           destroyTree(root);
       }
        if (BT.root == nullptr)
        {
            root =  nullptr;
        }
        else
        {
            copyTree(root , BT.root);

        }
    }
    return *this;
}

template <typename T>
bool BinaryTree<T>::isEmpty() const
{
    return (root == nullptr);
}

template <typename T>
int BinaryTree<T>::heightOfTheTree() const
{
 return height(root);
}


template <typename T>
int BinaryTree<T>::numberOfNodes() const
{
   return countNode(root);
}


template <typename T>
int BinaryTree<T>::numberOfLeaves() const
{
    return countLeaves(root);
}



template <typename T>
void BinaryTree<T>::printInOrder() const
{
     inorder(root);
}

template <typename T>
void BinaryTree<T>::printPostOrder() const
{
   postOrder(root);
}

template <typename T>
void BinaryTree<T>::printPreOrder() const
{
   preorder(root);
}

template <typename T>
void BinaryTree<T>::print()
{
    breadthFirstTraversal();
}

template <typename T>
void BinaryTree<T>::destroy()
{
   destroyTree(root);
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
    destroyTree(root);
}

//============================private methods=============================================
template <typename T>
int BinaryTree<T>::countLeaves(BTNode<T>* node) const
{
    if (node == nullptr)
    {
        return 0;
    }
    if (node->left == nullptr && node->right == nullptr)
    {
        return 1;
    }
    return countLeaves(node->left)+countLeaves(node->right);
}

template <typename T>
int BinaryTree<T>::countNode(BTNode<T>* node) const
{
    if (node == nullptr)
    {
        return 0;
    }
    return 1+ countNode(node->left)+countNode(node->right);
}
template <typename T>
void BinaryTree<T>::destroyTree(BTNode<T>*& node)
{
    if (node != nullptr)
    {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
        node = nullptr;
    }
}
template <typename T>
int BinaryTree<T>::height(BTNode<T>* node) const
{
    if (node == nullptr)
    {
        return 0;
    }
    return 1+ max(height(node->left) , height(node->right));
}
template <typename T>
void BinaryTree<T>::inorder(BTNode<T>* node) const
{
    if (node != nullptr)
    {
        inorder(node->left);
        cout << node->info << " ";
        inorder(node->right);
    }
}
template <typename T>
void BinaryTree<T>::postOrder(BTNode<T>* node) const
{
    if (node != nullptr)
    {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->info << " ";
    }
}
template <typename T>
void BinaryTree<T>::preorder(BTNode<T>* node) const
{
    if (node != nullptr)
    {
        preorder(node->right);
        cout << node->info << " ";
        preorder(node->left);
    }
}
template <typename T>
void BinaryTree<T>::breadthFirstTraversal() const
{
    queue<BTNode<T> *> BTQueue;
    BTNode<T>* p = root;
    if (p !=  nullptr) //ensure the tree is not empty
    {
        BTQueue.push(p); // push the root  (the initial data to begin the printing)
        while (!BTQueue.empty())
        {
            p = BTQueue.front(); //store the value to be deleted to print it after deleting
            BTQueue.pop();
            cout << p->info << " " ;
            /* why this order of the previous steps is very important is very important ?
             *  we want to update the pointer p to be able to visit all nodes and based on th queue principle "FIFO"
             *  we store the first value in the queue then delete it then print and check the right and the left of the deleted element in the queue
             *  push new values and we sure the level order is accurate because of the queue
             */
            if (p->left !=  nullptr)
            {
                BTQueue.push(p->left);
            }
            if (p->right != nullptr)
            {
                BTQueue.push(p->right);
            }
        }
        cout << endl;
    }
}

template <typename T>
void BinaryTree<T>::copyTree(BTNode<T>*& copiedTreeNode, BTNode<T>*& otherTreeRoot)
{
    if (otherTreeRoot == nullptr )
    {
        copiedTreeNode = nullptr;
    }
    else
    {
        copiedTreeNode = new BTNode<T>;
        copiedTreeNode->info = otherTreeRoot->info;
        copyTree(copiedTreeNode->left , otherTreeRoot->left);
        copyTree(copiedTreeNode->right , otherTreeRoot->right);
    }
}


// BINARYTREE_TPP
