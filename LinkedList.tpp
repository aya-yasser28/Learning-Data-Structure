//
// Created by Aya on 2026-06-06.
//
#pragma once
#include <assert.h>
#include <iostream>
using namespace std;

template <typename T>
LinkedListIterator<T>::LinkedListIterator()
{
    current = nullptr;
}

template <typename T>
LinkedListIterator<T>::LinkedListIterator(Node<T>* p)
{
    current = p;
}

template <typename T>
T LinkedListIterator<T>::operator*()
{
    return current->info;
}

template <typename T>
LinkedListIterator<T> LinkedListIterator<T>::operator++()
{
    current = current->link;
    return *this;
}

template <typename T>
bool LinkedListIterator<T>::operator==(const LinkedListIterator<T>& right) const
{
    return (current == right.current);
}

template <typename T>
bool LinkedListIterator<T>::operator!=(const LinkedListIterator<T>& right) const
{
    return (current != right.current);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
template <typename T>
LinkedList<T>::LinkedList()
{
    this->size = 0;
    this->first = nullptr;
    this->last = nullptr;
}

template <typename T>
T LinkedList<T>::back() const
{
    assert(last != nullptr);
    return last->info;
}

template <typename T>
LinkedListIterator<T> LinkedList<T>::begin()
{
    LinkedListIterator<T> temp(first);
    return temp;
}

template <typename T>
void LinkedList<T>::copyList(const LinkedList<T>& other)
{
    Node<T>* newNode;
    Node<T>* current;
    if (first != nullptr)
    {
        destroyList();
    }
    if (other.first == nullptr)
    {
        first = nullptr;
        last = nullptr;
        size = 0;
    }
    else
    {
        current = other.first;
        size = other.size;
        first = new Node<T>;
        first->info = current->info;
        first->link = nullptr;
        last = first;
        current = current->link;
        while (current != nullptr)
        {
            newNode = new Node<T>;
            newNode->info = current->info;
            newNode->link = nullptr;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }
    }
}

template <typename T>
void LinkedList<T>::destroyList()
{
    Node<T>* temp;
    while (first != nullptr)
    {
        temp = first;
        first = first->link;
        delete temp;
    }
    last = nullptr;
    size = 0;
}

template <typename T>
LinkedListIterator<T> LinkedList<T>::end()
{
    LinkedListIterator<T> temp(nullptr);
    return temp;
}

template <typename T>
T LinkedList<T>::front() const
{
    assert(first!=nullptr);
    return first->info;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
    return first == nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
    first = nullptr;
    copyList(other);
}

template <typename T>
int LinkedList<T>::length() const
{
    return size;
}

template <typename T>
void LinkedList<T>::print() const
{
    if (first == nullptr)
    {
        cerr << "Error: Can not Print Empty List! \n";
    }
    Node<T>* current = first;
    while (current != nullptr)
    {
        cout << current->info << " ";
        current = current->link;
    }
    cout << endl;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
    if (this != &other)
    {
        copyList(other);
    }
    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    destroyList();
}
