//
// Created by Aya on 2026-06-06.
//
#pragma once
template <typename T>
void UnorderedLinkedList<T>::deleteNode(const T& item)
{
     if (this->first == nullptr) // case 1 :empty
     {
         cerr<<"Can not Delete From Empty List! \n";
         return;
     }
    if (this->first->info == item) // case 2
    {
        Node<T>* temp = this->first;
        this->first= this->first->link;
        if (this->first == nullptr) // the list have only one node and it is deleted
        {
            this->last = nullptr;
        }
        delete temp;
        --this->size;
    }
    else // search for the item in the list
    {
        bool found = false;
        Node<T> *current , *trailCurrent;
        trailCurrent = this->first;
        current = this->first->link;
        while (current != nullptr && !found)
        {
            if (current->info == item)
            {
                found = true;
            }
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        }
        if (found) // the node to be deleted is current  // case 3
        {
            trailCurrent->link = current->link;
            --this->size;
            if (this->last == current)  // case 3b: the item to be deleted is the last item
            {
                this->last = trailCurrent;
            }
            delete current;
        }
        else // case 4: not found
        {
            cerr<<"The item to be deleted is not in the list!\n";
        }
    }
}
template <typename T>
void UnorderedLinkedList<T>::insertFirst(const T& item)
{
    Node<T>* newNode;
    newNode = new Node<T>;
    newNode->info = item;
    newNode->link = this->first;
    this->first = newNode;
    ++this->size ;
    if (this->last == nullptr)
    {
        this->last =newNode;
    }
}

template <typename T>
void UnorderedLinkedList<T>::insertLast(const T& item)
{
    Node<T>* newNode;
    newNode =  new Node<T>;
    newNode->info = item;
    newNode->link = nullptr;
    if (this->first == nullptr) //list is empty
    {
        this->first = newNode;
        this->last = newNode;
    }
    else
    {
        this->last->link = newNode;
        this->last = newNode;
    }
    ++this->size;
}
template <typename T>
void UnorderedLinkedList<T>::insert(const T& item)
{
    insertLast(item);
}

template <typename T>
bool UnorderedLinkedList<T>::search(const T& item)
{
    bool found = false;
    if (this->first == nullptr)
    {
        return found;
    }
    Node<T>* current = this->first;
    while (current != nullptr )
    {
        if (current->info == item)
        {
            found = true;
            break;
        }
        current = current->link;
    }
    return found;
}

