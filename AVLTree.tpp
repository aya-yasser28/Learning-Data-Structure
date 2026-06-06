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
void AVLTree<T>::rotateLeft(BTNode<T>* &node)
{
    BTNode<T>* p;
    if (node == nullptr)
    {
        cerr << "Error: node is NULL!\n";
    }
    else if (node->right == nullptr) // as we rotate the right subtree to the let so if it is null then no rotation
    {
        cerr << "No right subtree to rotate!\n";
    }
    else
    {
        p = node->right;
        node->right = p->left;  // the left subtree  of the new root is the right subtree to the node after rotation
        p->left = node ;
        node = p;
    }
}
template <typename T>
void AVLTree<T>::rotateRight(BTNode<T>*& node)
{
    BTNode<T>* p ;
    if (node  ==  nullptr)
    {
        cerr <<"Error: node is NULL! \n";
    }
    else if (node->left == nullptr)
    {
        cerr<<"No left subtree to rotate! \n";
    }
    else
    {
        p = node->left;
        node->left = p->right;
        p->right = node ;
        node = p;
    }
}

template <typename T>
void AVLTree<T>::balanceFromLeft(BTNode<T>*& node)
{
    BTNode<T>* p;
    BTNode<T>* w;
    p =  node->left; //pointer to the left subtree of the node
    switch (p->balanceFactor)
    {
    case -1:
        // they are both negative  so implement single right rotation and update the balance factors
        node->balanceFactor = 0;
        p->balanceFactor = 0;
        rotateRight(node);
        break;
    case 0:
        //if the root is unbalanced so it is impossible to the child's balance factor to be 0
        cerr<<"Error: Con not balance from Left! \n";
        break;
    case 1:
        // opposite signs so we implement double rotation  first left single rotation  at p  and the right single rotation at the node
        w = p->right; // pointer to the right of the p node which is the left subtree of the node
        switch (w->balanceFactor)
        {
        case -1 : // the left subtree of w is higher
            node->balanceFactor = 1 ;
            p->balanceFactor =0;
            break;
        case 0 : // they are equal
            node->balanceFactor=0;
            p->balanceFactor = 0;
            break;
        case 1: // the right subtree is higher
            node->balanceFactor=0;
            p->balanceFactor= -1;
        default:
            break;
        }
        w->balanceFactor = 0;
        rotateLeft(p);
        node->left = p;
        rotateRight(node);
    default:
        break;
    }
}
template <typename T>
void AVLTree<T>::balanceFromRight(BTNode<T>*& node)
{

    BTNode<T>* p;
    BTNode<T>* w;
    p= node->right;
    switch (p->balanceFactor)
    {
    case -1 :
        // double rotation node->balanceFactor = 1 and its child->balanceFactor  = -1
        w= p->left;
        switch (w->balanceFactor)
        {
        case -1:
            node->balanceFactor = 0;
            p->balanceFactor = 1;
            break;
        case 0:
            node->balanceFactor=0;
            p->balanceFactor = 0;
            break;
        case 1:
            node->balanceFactor = -1;
            p->balanceFactor = 0;
            break;
        default:
            break;
        }
        w->balanceFactor = 0;
        rotateRight(p);
        node->right = p ;
        rotateLeft(node);
        break;
    case 0 :
        cerr << "Error : Can not balance from right! \n";
        break;
    case 1:
        node->balanceFactor = 0 ;
        p->balanceFactor = 0;
        rotateLeft(node);
    default:
        break;
    }

}

template <typename T>
void AVLTree<T>::insertIntoAVL(BTNode<T>* &node, BTNode<T>* newNode, bool& isTaller)
{
    if (node == nullptr)
    {
     node = newNode;
     isTaller = true;
    }
    else if (node->info ==  newNode->info)
    {
        cerr<<"No duplicates are allowed! \n";
    }
    else if (node->info > newNode->info)
    {
        insertIntoAVL(node->left , newNode , isTaller);
        // after insertion and the height of the left subtree is increased
        if (isTaller)
        {
            switch (node->balanceFactor)
            {
            case -1 :
                balanceFromLeft(node);
                isTaller = false; // we have balanced the tree
                break;
            case 0 :
                node->balanceFactor = -1;
                isTaller =true;
                break;
            case 1:
                node->balanceFactor = 0;
                isTaller = false;
                break;
            default:
                break;
            } // end switch
        } // end if isTaller
    } // end else if
    else  // node->info < newNode->info
    {
       insertIntoAVL(node->right , newNode , isTaller);
        if (isTaller)
        {
            switch (node->balanceFactor)
            {
            case -1:
                node->balanceFactor = 0;
                isTaller = false;
                break;
            case 0 :
                node->balanceFactor = 1;
                isTaller = true;
                break;
            case 1:
                balanceFromRight(node);
                isTaller = false;
                break;
            default:
                break;
            }// end switch
        } // end if isTaller
    } // end else
} // end insertIntoAVL

template <typename T>
void AVLTree<T>::insert(T value)
{
    bool isTaller = false;
    BTNode<T>* newNode;
    newNode = new BTNode<T>;
    newNode->info = value;
    newNode->balanceFactor = 0;
    newNode->left= nullptr;
    newNode->right = nullptr;
    insertIntoAVL(this->root  , newNode , isTaller);
}

template <typename T>
void AVLTree<T>::balanceFromLeftDeletion(BTNode<T>*& node , bool& isShorter)
{
    BTNode<T>* p;
    BTNode<T>* w;
    switch (node->balanceFactor)
    {
    case -1:
        node->balanceFactor = 0 ;
        break;
    case 0 :
        node->balanceFactor = 1 ;
        isShorter = false;
        break;
    case 1:
        p = node->right;
        switch (p->balanceFactor)
        {
        case -1 :
            w = p->left;
            switch (w->balanceFactor)
            {
            case -1:
                node->balanceFactor= 0 ;
                p->balanceFactor = 1;
                break;
            case 0 :
                node->balanceFactor = 0 ;
                p->balanceFactor = 0 ;
                break;
            case 1:
                node->balanceFactor = -1;
                p->balanceFactor = 0;
                break;
            default:
                break;
            }
            w->balanceFactor = 0;
            rotateRight(p);
            node->right = p;
            rotateLeft(node);
            break;
        case 0 :
            rotateLeft(node);
            node->balanceFactor = -1 ;
            p->balanceFactor=1 ;
            isShorter = false ;
            break;
        case 1:
            rotateLeft(node);
            node->balanceFactor = 0 ;
            p->balanceFactor = 0;
            break;
        default:
            break;
        }
    default:
        break;
    }
}
template <typename T>
void AVLTree<T>::balanceFromRightDeletion(BTNode<T>*& node , bool& isShorter)
{
    BTNode<T>* p;
    BTNode<T>* w;

    switch (node->balanceFactor)
    {
    case 1:
        node->balanceFactor = 0 ;
        break;
    case 0 :
        node->balanceFactor = -1 ;
        isShorter = false;
        break ;
    case -1:
        p = node->left;
        switch (p->balanceFactor)
        {
        case -1:
            rotateRight(node);
            node->balanceFactor = 0 ;
            p->balanceFactor = 0 ;
            break;
        case 0 :
            rotateRight(node);
            node->balanceFactor= 1;
            p->balanceFactor= -1;
            isShorter = false;
            break;
        case 1:
            w = p->right;
            switch (w->balanceFactor)
            {
            case -1:
                node->balanceFactor = 1;
                p->balanceFactor = 0;
                break;
            case 0 :
                node->balanceFactor = 0;
                p ->balanceFactor = 0;
                break;
            case 1:
                node->balanceFactor =0 ;
                p->balanceFactor = -1;
                break;
            default:
                break;
            }
            w->balanceFactor = 0 ;
            rotateLeft(p);
            node->left = p ;
            rotateRight(node);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}


template <typename T>
void AVLTree<T>::removeNode(T value)
{
    bool isShorter = false;
    deleteFromTree(this->root , value , isShorter);
}
template <typename T>
void AVLTree<T>::deleteFromTree(BTNode<T>* & node , T value, bool& isShorter)
{
    if (node == nullptr)
    {
        cerr<<"Item not found\n";
        isShorter = false;
        return;
    }
    if (node->info > value)
    {
        deleteFromTree(node->left , value , isShorter);
        if (isShorter)
        {
            balanceFromRightDeletion(node , isShorter);
        }
    }
    else if (node->info < value)
    {
        deleteFromTree(node->right , value , isShorter);
        if (isShorter)
        {
            balanceFromLeftDeletion(node , isShorter);
        }
    }
    else
    {
        deleteNode(node , isShorter);
    }
}
template <typename T>
void AVLTree<T>::deleteNode(BTNode<T>*& node, bool& isShorter)
{
    BTNode<T>* temp ;
    if (node->left == nullptr && node->right == nullptr) // the node to be deleted is a leaf
    {
        delete node;
        node = nullptr;
        isShorter= true;
    }
    else if (node->left == nullptr) // the node has no left child
    {
        temp = node ;
        node = node->right;
        delete temp;
        isShorter = true;
    }
    else if (node->right ==  nullptr)// the node has no right child
    {
        temp = node ;
        node = node->left;
        delete temp ;
        isShorter = true;
    }
    else
    {
        BTNode<T>* current = node->left;
        while (current->right != nullptr)
        {
            current = current->right;
        }
        node->info = current->info ;
        deleteFromTree(node->left , current->info , isShorter);
        if (isShorter)
        {
            balanceFromRightDeletion(node , isShorter);
        }
    }
}

