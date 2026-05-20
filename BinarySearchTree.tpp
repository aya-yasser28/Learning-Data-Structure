//
// Created by Aya on 2026-05-20.
//

#include "BinarySearchTree.h"
#include <iostream>
using namespace std;
template <typename T>
void BinarySearchTree<T>::deleteFromTree(BTNode<T>* node)
{
     BTNode<T>* current ;
     BTNode<T>* trialCurrent;
     BTNode<T>* temp;
     if (node == nullptr)
     {
          cout << "The node to be deleted is NULL!\n";
     }
     else if (node->left == nullptr && node->right == nullptr) // case 1: no children
     {
          temp = node;
          node = nullptr;
          delete temp;
     }
     else if (node->left == nullptr) //case 2:only has a right child
     {
          temp = node ;
          node = temp->right;
          delete temp;
     }
     else if (node->right == nullptr) //case 3: only has a left child
     {
          temp = node ;
          node= temp->left;
          delete temp;
     }
     else
     {
          current = node->left; //we want to find the predecessor which is the most right node in the left subtree
          trialCurrent = nullptr;
          while (current->right != nullptr)
          {
               trialCurrent =current;
               current=current->right;
          }
          node->info = current->info;
          if (trialCurrent == nullptr)// if the left child of the deleted node doesn't have a right child so it will not enter the loop
          {
               node->left = current->left; //here current = p->left
          }
          else
          {
               trialCurrent->right =current->left;
               //it might be nullptr,but we are sure that there is no right child to current because it is the condition that make us out the loop
          }
          delete current;
     }
}
template<typename T>
void BinarySearchTree<T>::deleteNode(T value)
{
    BTNode<T>* current;
     BTNode<T>* trailCurrent;
     if (this->root == nullptr)
     {
          cout<<"the Tree is empty!\n";
     }
     else
     {
          current = this->root;
          trailCurrent= this->root;
          bool found = false;
          while (current != nullptr && !found)
          {
               if (current->info == value)
               {
                    found = true;
               }
               trailCurrent = current;
               if (current->info > value)
               {
                    current= current->left;
               }
               else
               {
                    current = current->right;
               }
          }
          if (current == nullptr)
          {
               cout << "This value is not in the Tree!\n";
          }
          else if (found)
          {
               if (current ==  this->root)
               {
                    deleteFromTree(this->root);
               }
               else if (trailCurrent->info > value)
               {
                    deleteFromTree(trailCurrent->left);
               }
               else
               {
                    deleteFromTree(trailCurrent->right);
               }
          }
     }

}

template <typename T>
void BinarySearchTree<T>::insert(T value)
{
     BTNode<T>* newNode = new BTNode<T>;
     newNode->info = value;
     newNode->left = nullptr;
     newNode->right = nullptr;
     if (this->root == nullptr)
     {
          this->root = newNode;
     }
     else
     {
          BTNode<T>* current = this->root;
          BTNode<T>* trialCurrent;
          while (current != nullptr)
          {
               trialCurrent = current; //it store the valid value that should insert in it
               if (current->info == value)
               {
                    cout <<"This item already in the tree\n";
               }
               else if (current->info > value)
               {
                    current = current->left;
               }
               else
               {
                    current = current->right;
               }
          }
          if (trialCurrent->info > value)
          {
               trialCurrent->left =newNode;
          }
          else
          {
               trialCurrent->right = newNode;
          }

     }
}

template <typename T>
bool BinarySearchTree<T>::search(T value) const
{
     bool found = false;
     BTNode<T>* current;
     if (this->root == nullptr)
     {
         cout <<"Tree is Empty!\n";
     }
     else
     {
          while (current != nullptr && !found)
          {
               current = this->root;
               if (current->info == value)
               {
                    found = true;
               }
               else if ( current-> info > value)
               {
                    current = current->left;
               }
               else
               {
                    current = current->right;
               }

          }
     }
    return found ;

}
