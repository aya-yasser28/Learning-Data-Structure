//
// Created by Aya on 2026-06-06.
//

#ifndef LEARNING_DATA_STRUCTURE_DOUBLYLINKEDLIST_H
#define LEARNING_DATA_STRUCTURE_DOUBLYLINKEDLIST_H

template<typename  T>
struct NodeType
{
 T info;
 NodeType<T>* next;
 NodeType<T>* prev;
};
template<typename T>
class DoublyLinkedList
{
private:
 void copyList(const DoublyLinkedList<T>& otherList);
protected:
 int size;
 NodeType<T>* first;
 NodeType<T>* last;
public:
 const DoublyLinkedList<T>& operator= (const DoublyLinkedList<T>& other);
 bool isEmpty()const;
 void destroyList();
 void print() const;
 void reversePrint() const;
 int length() const;
 T front() const;
 T back() const;
 bool search(const T& searchItem) const;
 void insert(const T& insertItem);
 /*
  * we have 4 cases as I illustrate in the single linked list :
  * case 1: list is empty
  * case 2: insert in the first node
  * case 3: insert somewhere in the list
  * case 4: insert at the end  of the list
  */
 void deleteNode(const T& deleteItem);
 /*
  * 4 cases:
  * case 1: list is empty
  * case 2: the item to be deleted is the first item
  * case 3: the item to be deleted is somewhere in the list may be the last node
  * case 4: the item to be deleted not in the list
  */
 DoublyLinkedList();
 DoublyLinkedList(const DoublyLinkedList<T>& other);
 ~DoublyLinkedList();
};
#include "DoublyLinkedList.tpp"


#endif //LEARNING_DATA_STRUCTURE_DOUBLYLINKEDLIST_H