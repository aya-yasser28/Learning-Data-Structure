//
// Created by Aya on 2026-06-06.
//

#pragma once
#include<iostream>

template <typename T, typename Compare>
Heap<T, Compare>::Heap()
{
    comp = Compare();
}

template <typename T, typename Compare>
Heap<T, Compare>::Heap(const Compare& comp)
{
    this->comp = comp;
}

template <typename T, typename Compare>
Heap<T, Compare>::Heap(const vector<T>& v)
{
    comp = Compare();
    build(v);
}

template <typename T, typename Compare>
int Heap<T, Compare>::parent(int i)
{
    return (i - 1) / 2;
}

template <typename T, typename Compare>
int Heap<T, Compare>::left(int i)
{
    return (2 * i) + 1;
}

template <typename T, typename Compare>
int Heap<T, Compare>::right(int i)
{
    return (2 * i) + 2;
}

template <typename T, typename Compare>
void Heap<T, Compare>::heapifyUp(int i)
{
    while (i > 0 && comp(data[i], data[parent(i)]))
    {
        swap(data[i], data[parent(i)]);
        i = parent(i);
    }
}

template <typename T, typename Compare>
void Heap<T, Compare>::heapifyDown(int i)
{
    int largest = i;
    int l = left(i);
    int r = right(i);
    if (l < data.size() && comp(data[l], data[largest]))
    {
        largest = l;
    }
    if (r < data.size() && comp(data[r], data[largest]))
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(data[i], data[largest]);
        heapifyDown(largest);
    }
}

template <typename T, typename Compare>
void Heap<T, Compare>::build(const vector<T>& v)
{
    data = v;
    for (int i = data.size() / 2 - 1; i >= 0; --i)
    {
        heapifyDown(i);
    }
}

template <typename T, typename Compare>
void Heap<T, Compare>::push(const T& value)
{
    data.push_back(value);
    heapifyUp(data.size() - 1);
}

template <typename T, typename Compare>
void Heap<T, Compare>::pop()
{
    if (data.empty())
    {
        cerr << "Heap is Empty!\n";
        return;
    }
    data[0] = data.back();
    data.pop_back();
    if (!data.empty())
    {
        heapifyDown(0);
    }
}

template <typename T, typename Compare>
const T& Heap<T, Compare>::top() const
{
    if (data.empty())
    {
        cerr << "Heap is Empty!\n";
        return T(0);
    }
    return data[0];
}

template <typename T, typename Compare>
int Heap<T, Compare>::size() const
{
    return data.size();
}

template <typename T, typename Compare>
bool Heap<T, Compare>::empty() const
{
    return data.empty();
}

template <typename T, typename Compare>
void Heap<T, Compare>::clear()
{
    data.clear();
}
template <typename T, typename Compare>
void Heap<T, Compare>::display() const
{
    if (data.empty())
    {
        cerr<<"Empty Heap\n";
    }
    for (T value : data)
    {
        cout<< value << " ";
    }
    cout << endl;
}
