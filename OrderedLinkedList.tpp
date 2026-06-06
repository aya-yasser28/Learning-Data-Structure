//
// Created by Aya on 2026-06-06.
//
#pragma once

template <typename T>
void OrderedLinkedList<T>::deleteNode(const T& item)
{
    if (this->first == nullptr) // case 1
    {
        cerr<<"Can not Delete From Empty List!\n";
    }
    else
    {
        Node<T> *current , *trailCurrent;
        bool found = false;
        current = this->first;
        while (current != nullptr && !found)
        {
            if (current->info >= item)
            {
               found = true;
            }
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        }
        if (current == nullptr) // case 4
        {
            cerr<<"the item to be deleted in the List! \n";
        }
        else
        {
            if (current->info == item)
            {
                if (this->first == current) //case 2
                {
                    this->first = this->first->link;
                    if (this->first == nullptr)
                    {
                        this->last = nullptr;
                    }
                    delete current;
                }
                else // case 3
                {
                    trailCurrent->link = current->link;
                    if (current == this->last)
                    {
                        this->last = trailCurrent;
                    }
                    delete current;
                }
                --this->size;
            }
            else
            {
                cerr<<"The Item To Be Deleted is Not In The List! \n";
            }
        }
    }
}
template <typename T>
bool OrderedLinkedList<T>::search(const T& item)
{
    bool found = false ;
    Node<T>* current = this->first;
    while (current != nullptr)
    {
        if (current->info >= item)
        {
            found = true;
            break;
        }
        current = current->link;
    }
    if (found)
    {
        found = (current->info == item);
    }
    return found;
}

template <typename T>
void OrderedLinkedList<T>::insert(const T& item)
{
    Node<T>* newNode;
    Node<T> *current , *trailCurrent;
    bool found = false;
    newNode = new Node<T>;
    newNode->info = item;
    newNode->link = nullptr;
    if (this->first == nullptr) // case 1
    {
        this->first = newNode;
        this->last = newNode;
        ++this->size;
    }
    else
    {
        current = this->first;
        while(current != nullptr && !found)
        {
            if (current->info >= item)
            {
                found = true;
            }
            else
            {
                trailCurrent = current;
                current=current->link;
            }
        }
        if (current == this->first) // case 2
        {
            newNode->link = this->first;
            this->first = nullptr;
            ++this->size;
        }
        else  //case 3
        {
            trailCurrent->link = newNode;
            newNode->link = current;
            if (current == nullptr) // case 4
            {
                this->last = newNode;
            }
            ++this->size;
        }

    }

}
template <typename T>
void OrderedLinkedList<T>::insertFirst(const T& newItem)
{
    insert(newItem);
}
template <typename T>
void OrderedLinkedList<T>::insertLast(const T& newItem)
{
    insert(newItem);
}

