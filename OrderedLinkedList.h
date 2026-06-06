//
// Created by Aya on 2026-06-06.
//

#ifndef LEARNING_DATA_STRUCTURE_ORDEREDLINKEDLIST_H
#define LEARNING_DATA_STRUCTURE_ORDEREDLINKEDLIST_H
#include "LinkedList.h"

template<typename T>
class OrderedLinkedList :public LinkedList<T>
{
public:
    bool search(const T& item); //O(n)
    void insert(const T& item);//O(n)
    /*
     * we should search for the place to insert into it then we will have 4 cases:
     * case 1: list is empty
     * case 2: insert in the first node
     * case 3:insert somewhere but not the last
     * case 4: insert in the last node
     */
    void insertFirst(const T& newItem);
    void insertLast(const T& newItem) ;
    void deleteNode(const T& item); //O(n)
};

#include "OrderedLinkedList.tpp"
#endif //LEARNING_DATA_STRUCTURE_ORDEREDLINKEDLIST_H