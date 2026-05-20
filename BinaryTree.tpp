//
// Created by Aya on 2026-05-20.
//

#include "BinaryTree.h"

#include <algorithm>
#include<iostream>
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




