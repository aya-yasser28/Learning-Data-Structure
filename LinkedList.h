//
// Created by Aya on 2026-06-06.
//

#ifndef LEARNING_DATA_STRUCTURE_LINKEDLIST_H
#define LEARNING_DATA_STRUCTURE_LINKEDLIST_H
template<typename T>
struct Node
{
    T info;
    Node<T>* link;

};
template<typename T>
class LinkedListIterator
{
private:
    Node<T>* current;
public:
    LinkedListIterator();
    LinkedListIterator(Node<T>* p);
    T operator*();
    LinkedListIterator<T> operator++();
    bool operator==(const LinkedListIterator<T>& right) const;
    bool operator!=(const LinkedListIterator<T> & right) const;
};
template<typename T>
class LinkedList
{
private:
    void copyList(const LinkedList<T>& other);
protected:
    int size{};
    Node<T>* first;
    Node<T>* last;
public :
    LinkedList();
    LinkedList<T>& operator=(const LinkedList<T> & other);
    bool isEmpty()const;
    void print() const;
    int length() const;
    void destroyList();
    T front() const;
    T back() const;
    virtual  bool search(const T & item)=0;
    virtual  void insertFirst(const T& newItem) = 0 ;
    virtual  void insertLast(const T& newItem) = 0 ;
    virtual void deleteNode(const T& item) = 0 ;
    LinkedListIterator<T> begin();
    LinkedListIterator<T> end();
    LinkedList(const LinkedList<T>& other);
    ~LinkedList();
};
#include "LinkedList.tpp"

#endif //LEARNING_DATA_STRUCTURE_LINKEDLIST_H