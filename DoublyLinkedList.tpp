//
// Created by Aya on 2026-06-06.
//
#pragma once
#include <assert.h>
#include <iostream>
using namespace std;
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    size =  0;
    first =nullptr;
    last = nullptr;
}
template <typename T>
void DoublyLinkedList<T>::copyList(const DoublyLinkedList<T>& otherList)
{
    NodeType<T> *current , *newNode;
    if (first != nullptr)
    {
        destroyList();
    }
    if (otherList.first ==nullptr)
    {
        first = nullptr;
        last = nullptr;
        size = 0;
    }
    else
    {
        current = otherList.first;
        size = otherList.size;
        first = new  NodeType<T>;
        first->info = current->info;
        first->next =  nullptr;
        first->prev = nullptr;
        last = first;
        current = current->next;
        while (current != nullptr)
        {
            newNode = new NodeType<T>;
            newNode->info = current->info;
            newNode->prev = current;
            newNode->next = nullptr;
            last = newNode;
            current = current->link;
        }
    }

}
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other)
{
    first = nullptr;
    copyList(other);
}
template <typename T>
const DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other)
{
     copyList(other);
    return *this;
}
template <typename T>
T DoublyLinkedList<T>::back() const
{
    assert(last != nullptr);
    return last->info;
}


template <typename T>
T DoublyLinkedList<T>::front() const
{
    assert(first != nullptr);
    return first->info;
}
template <typename T>
bool DoublyLinkedList<T>::isEmpty() const
{
    return first == nullptr;
}
template <typename T>
int DoublyLinkedList<T>::length() const
{
    return size ;
}
template <typename T>
void DoublyLinkedList<T>::print() const
{
    NodeType<T>* current = first;
    while (current != nullptr)
    {
        cout << current->info << " ";
        current = current->next;
    }
    cout << endl;
}
template <typename T>
void DoublyLinkedList<T>::reversePrint() const
{
     NodeType<T> *current = last;
    while (current != nullptr)
    {
        cout << current->info << " ";
        current=current->prev;

    }
}
template <typename T>
void DoublyLinkedList<T>::deleteNode(const T& deleteItem)
{
    NodeType<T> *current = first , *trailCurrent = nullptr;
    bool found  = false;
     if (first == nullptr)
     {
         cerr << "Can not Delete From An Empty List!\n";
     }
     else if (first->info == deleteItem)
    {
        first = first->next;
        if (first != nullptr)
        {
            first->prev = nullptr;
        }
        else
        {
            last = nullptr;
        }
        size --;
        delete current;
    }
     else
     {

         while (current != nullptr && !found)
         {
             if (current->info >= found)
             {
                 found = true;
             }
             else
             {
                 trailCurrent = current;
                 current = current->next;
             }
         }

         if (current == nullptr)
         {
             cerr<< "Item is not in the list! \n";
         }
         else if (current->info == deleteItem)
         {
             trailCurrent = current->prev;
             trailCurrent->next = current->next;
             if (current->next != nullptr)
             {
                 current->next->prev = trailCurrent;
             }
             if (current == last)
             {
                 last = trailCurrent;
             }
             size--;
             delete current;
         }
         else
         {
             cerr<<"item Not Found! \n";
         }
     }
}

template <typename T>
void DoublyLinkedList<T>::insert(const T& insertItem)
{
    // initialize a new node
    NodeType<T>* newNode;
    newNode = new NodeType<T>;
    newNode->info = insertItem;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (first == nullptr) // case 1
    {
        first = newNode;
        last = newNode;
        size++;
    }
    else
    {
        bool found = false;
        NodeType<T>* current = first ;
        NodeType<T>* trailCurrent = nullptr; // initial value 'keda keda hyt3mlha update fe el while loop'
        while (current != nullptr && !found)
        {
            if (current->info >= insertItem)
            {
                found = true;
            }
            else
            {
                trailCurrent = current;
                current = current->next;
            }
        }
        if (current == first) // case 2
        {
            first->prev = newNode;
            newNode->next = first;
            first= newNode;
            size ++;
        }
        else
        {
            if (current != nullptr) // case 3
            {
                trailCurrent->next = newNode;
                newNode->prev = trailCurrent;
                newNode->next = current;
                current->prev = newNode;
            }
            else //case 4
            {
               trailCurrent->next = newNode;
                newNode->prev = trailCurrent;
                last = newNode;
            }
            size++;
        }
    }
}

template <typename T>
bool DoublyLinkedList<T>::search(const T& searchItem) const
{
      bool found = false;
    NodeType<T>* current = first;
    while (current != nullptr && !found)
    {
        if (current->info >= searchItem)
        {
            found = true;
        }
        else
        {
            current = current->next;
        }
    }
    if (found)
    {
        found = (current->info == searchItem);
    }
    return found;
}

template <typename T>
void DoublyLinkedList<T>::destroyList()
{
     NodeType<T>* temp;
    while (first != nullptr)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
    last = nullptr;
    size = 0;
}
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
  destroyList();
}






