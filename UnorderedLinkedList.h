//
// Created by Aya on 2026-06-06.
//

#ifndef LEARNING_DATA_STRUCTURE_UNORDEREDLINKEDLIST_H
#define LEARNING_DATA_STRUCTURE_UNORDEREDLINKEDLIST_H
#include "LinkedList.h"

template<typename  T>
class UnorderedLinkedList : public LinkedList<T>
{
public:
    bool search(const T& item) ; // O(n)
    void insertFirst(const T& item); // O(1)
    void insertLast(const T& item); //O(1)
    void insert(const T& item);
    //it does not matter where to insert the item because it is unordered
    // But I considered it to insert in the last
    void deleteNode(const T& item); // O(n)


};

#include"UnorderedLinkedList.tpp"
#endif //LEARNING_DATA_STRUCTURE_UNORDEREDLINKEDLIST_H