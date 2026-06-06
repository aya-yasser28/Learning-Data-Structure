//
// Created by Aya on 2026-05-20.
//
#include <iostream>

#include "BinarySearchTree.h"
#include "AVLTree.h"
#include "sortingAlgorithms.h"
#include "Heap.h"
#include "UnorderedLinkedList.h"
#include "OrderedLinkedList.h"
#include "DoublyLinkedList.h"
using namespace std;
int main()
{
    //int array[5] ={3 , 2 , 8 , 1 , 9};
    // SelectionSort(array ,5);
    //  InsertionSort(array, 5);
    //ShellSort( array , 5);
    // BubbleSort(array , 5);
   // QuickSort(array , 0 , 4);
  // displaySortedArray(array , 5);
    // int a = 4 , b = 6;
    // Swap(a , b);
  //// cout << a << b;
  //BinarySearchTree<int> bst;
  //AVLTree<int> avlTree;
  //avlTree.insert(15);
  //avlTree.insert(20);
  //avlTree.insert(24);
  //avlTree.insert(10);
  //avlTree.insert(13);
  //avlTree.insert(7);
  //avlTree.insert(30);
  //avlTree.insert(36);
  //avlTree.insert(25);
  //  cout << bst.numberOfNodes();
  /// cout << bst.numberOfLeaves();
  //cout << "Initial insertion: " ;
  //avlTree.print();
  ////avlTree.removeNode(20);
  ////avlTree.print();
  //avlTree.removeNode(10);
  //avlTree.print();
   UnorderedLinkedList<int> ull;
   ull.insertFirst(10);
   ull.insertFirst(50);
   ull.insertLast(30);
   ull.print();
   ull.deleteNode(10)   ;
   ull.print();
    cout <<ull.length()     << endl;
   if (ull.search(10))
   {
       cout <<"Found\n";
   }
   else
   {
       cout << "Not Found\n";
   }
   if (ull.isEmpty())
   {
       cout << "List is Empty! \n";
   }
   else
   {
       cout << "List has  elements\n";
   }
    OrderedLinkedList<int> oll;
    oll.insertFirst(10);
    oll.insertFirst(50);
    oll.insertLast(30);
    oll.print();
    oll.deleteNode(10)   ;             
    oll.print();
    cout <<oll.length()     << endl;
    if (oll.search(50))
    {
        cout <<"Found\n";
    }
    else
    {
        cout << "Not Found\n";
    }
    oll.destroyList();
    if (oll.isEmpty())
    {
        cout << "List is Empty! \n";
    }
    else
    {
        cout << "List has  elements\n";
    }
    DoublyLinkedList<int> dll;
    dll.insert(50);
    dll.insert(60);
    dll.insert(10);
    dll.print();
    dll.deleteNode(10)   ;
    dll.print();
    cout <<dll.length()     << endl;
    if (dll.search(80))
    {
        cout <<"Found\n";
    }
    else
    {
        cout << "Not Found\n";
    }
    dll.destroyList();
    if (dll.isEmpty())
    {
        cout << "List is Empty! \n";
    }
    else
    {
        cout << "List has  elements\n";
    }
    Heap<int> h;
    h.push(50);
    h.push(20);
    h.push(40);
    h.push(30);
    h.display();
    h.pop();
    cout<<h.size() <<endl;
    cout<< h.top() <<endl;
    cout << h.empty() << endl;
    h.clear();
    cout << h.empty() <<endl;
    h.display();


    return 0;

}
//56 87 23 65 34 45 12 90 66