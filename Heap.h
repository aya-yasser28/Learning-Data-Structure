//
// Created by Aya on 2026-06-06.
//

#ifndef LEARNING_DATA_STRUCTURE_HEAP_H
#define LEARNING_DATA_STRUCTURE_HEAP_H
#include <vector>
using namespace std;
template<typename  T , typename  Compare = less<T>>
class Heap
{
private:
    vector<T> data;
    Compare comp;
    static int parent(int i);
    static int left(int i);
    static int right(int i);
    void heapifyUp(int i);
    void heapifyDown(int i);
    void build(const vector<T>& v);
public :
    Heap();
    explicit Heap(const Compare& comp);
    Heap(const vector<T>& v);
    void push(const T& value);
    void pop();
    const T& top() const;
    int size() const ;
    bool empty() const;
    void clear();
    void display() const;

};

#include "Heap.tpp"
#endif //LEARNING_DATA_STRUCTURE_HEAP_H