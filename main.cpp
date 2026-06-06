//
// Created by Aya on 2026-05-20.
//
#include <iostream>

#include "BinarySearchTree.h"
#include "AVLTree.h"
#include "sortingAlgorithms.h"
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
    // cout << a << b;
    BinarySearchTree<int> bst;
    AVLTree<int> avlTree;
    avlTree.insert(15);
    avlTree.insert(20);
    avlTree.insert(24);
    avlTree.insert(10);
    avlTree.insert(13);
    avlTree.insert(7);
    avlTree.insert(30);
    avlTree.insert(36);
    avlTree.insert(25);
  //  cout << bst.numberOfNodes();
   // cout << bst.numberOfLeaves();
    cout << "Initial insertion: " ;
    avlTree.print();
    //avlTree.removeNode(20);
    //avlTree.print();
    avlTree.removeNode(10);
    avlTree.print();
    return 0;
}
//56 87 23 65 34 45 12 90 66