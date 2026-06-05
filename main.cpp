//
// Created by Aya on 2026-05-20.
//
#include <iostream>

#include "BinarySearchTree.h"
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
    bst.insert(56);
    bst.insert(87);
    bst.insert(23);
    bst.insert(65);
    bst.insert(34);
    bst.insert(45);
    bst.insert(12);
    bst.insert(90);
    bst.insert(66);
  //  cout << bst.numberOfNodes();
   // cout << bst.numberOfLeaves();
    bst.print();

    return 0;
}
//56 87 23 65 34 45 12 90 66