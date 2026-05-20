//
// Created by Aya on 2026-05-19.
//

#include <iostream>
using namespace std;
template<typename T>
void Swap(T& a , T& b)
{
    T temp = a ;
    a  = b ;
    b = temp;
}
/**
 * Selection Sort: Choose the smallest item in the list and then swap it with the first item
 * of the unsorted list. after every swapping the list size decrease by ! as the first item is in it final place.
 * the algorithm only have two steps:
 *                             1.Find the smallest item in the unsorted list
 *                             2. Swap it with the first item of the unsorted list
 */
/*
 * this algorithm is based on the comparison which will make the Best/Average/Worst case is O(n)
 */
template<typename T>
void SelectionSort(T arr[] , int size)
{
    for (int i = 0 ; i < size ; i++)
    {
        int min = i;
        for ( int j= i+1 ; j < size && arr[min] > arr[j] ; j++)
        {
            min = j;
        }
        Swap(arr[min] , arr[i]);
    }
}

/*
 *Insertion Sort: this is like sort cards take the card that smaller than its previous and insert it at hte right place
 * which is before the first item greater than it.
 * 1. Find the first item that is previous items greater than it.
 * 2. shift all items greater than it.
 * 3. finally insert it in the right place (all previous items smaller and at least one item after it is greater than it).
 */

/*
 * Best case:O(n) => the array is already sorted
 * Worst case: O(n^2) => the array is sorted in a reverse order
 */
template <typename T>
void InsertionSort(T array[] , int size)
{
   for (int i = 0 , j ; i < size ; i ++)
   {
       T temp= array[i];
       for (j  = i ; j > 0 && temp < array[j-1]; j--)
       {
           if (array[j] < array[j-1])
           {
               array[j] =  array[j-1];
           }
       }
       array[j] =  temp;
   }
}

/*
 * Shell Sort: This is a modified insertion sort to minimize the number of movements. It is done by sorting the subarrays of equally spaces indices
 *  instead of moving to an adjacent location an element moves several locations away => results an almost sorted array and reducing the number of unneeded
 *  movements in (insertion sort / bubble sort) and unneeded comparisons in (selection sort).
 */

 /*
 * it is hard to obtain the time complexity of the algorithm because it is based on the size and if it almost sorted or not but it is almost O(n^1.25)
 */
template<typename T>
void ShellSort(T array[] , int size)
{
    for (int gap = size / 2 ; gap > 0 ; gap /=2)
    {
        for (int i = gap , j ; i< size ; i++)
        {
            T temp = array[i];
            for ( j = i ; j >= gap && temp < array[ j - gap]; j-=gap )
            {
                array[j] = array[j-gap];
            }
            array[j]= temp;
        }
    }
}
/*
 * Bubble Sort: This algorithm is the most straight forward algorithm. it compares every adjacent items and swap if they are out of order.
 * Smaller values bubble up to the top of the array and larger values sink to the bottom.
 */

/*
 * Best case: o(n) => if comparison is improved and if the array is sorted
 * Average/worst case: O(n^2)
 */
template<typename T>
void BubbleSort(T array[] , int size)
{
    for (int i = 0 ; i < size ; i++)
    {
        for (int j = size -1  ; j > i ; j--)
        {
            if (array[j] < array[j-1])
            {
                Swap(array[j] , array[j-1]);
            }
        }
    }
}
/*
 * Merge Sort:this algorithm is all about merging.divide each subarray, compare then at the end merge them.
 */
/*
 * Space :O(n)
 * Every case :O(n*log n)
 */
template<typename T>
void Merge(T array[] , int left , int middle , int right)
{
     int leftSize = middle - left + 1;
    int rightSize =  right - middle;
    T L[leftSize] , R[rightSize];
    for(int i = 0 ; i < leftSize ; i++)
    {
        L[i] = array[left+i];
    }
    for(int i = 0 ; i < rightSize ; i++)
    {
        R[i] = array[middle+1+i];
    }
    int lIndex = 0 , rIndex = 0 , oIndex=left;
    while (lIndex < leftSize && rIndex < rightSize)
    {
        if (L[lIndex] < R[rIndex])
        {
            array[oIndex] = L[lIndex];
            lIndex++;
        }
        else
        {
            array[oIndex] = R[rIndex];
            rIndex++;
        }
        oIndex++;
    }
    while (lIndex < leftSize)
    {
        array[oIndex] = L[lIndex];
        lIndex++;
        oIndex++;
    }
    while (rIndex < rightSize)
    {
        array[oIndex] = R[rIndex];
        rIndex++;
        oIndex++;
    }

}
template<typename T>
void MergeSort(T array , int left , int right)
{
    if (left >= right)
    {
        return;
    }
    int middle = (left+ right)/2;
    MergeSort(array , left , middle);
    MergeSort(array , middle +1 , right);
    Merge(array , left , middle , right);

}
/*
 * Quick Sort : this is based on choosing the right pivot.
 * the values smaller than it on its left the values greater than it on its right.
 * the best pivot is at the median of first , last and middle elements
 *  first element is bad for sorted arrays middle is ok median value is expensive to calculate
*/

/*
 * Average case : O(n*log n)
 */
template <typename T>
T medianOfThree(T first , T middle , T last)
{
   T median;
    if (first > middle  && first < last)
    {
        median = first;
    }
    else if (last > middle && last < first)
    {
        median = last;
    }
    else
    {
        median = middle;
    }

    return median;
}

template <typename T>
int Partition (T array[] , int left , int right)
{
    int middle =(left+right)/2;
    T pivot = medianOfThree(array[left] , array[middle] , array[right]); //this is the value now we will look for the index
    int i = left  ;
    int j = right ;
   while (true)
   {
       while (array[i] < pivot)
       {
           i++;
       }
       while (array[j] > pivot)
       {
           j--;
       }
       Swap(array[i] , array[j]);
       if ( i >= j)
       {
           return j;
       }

   }

}
template <typename T>
void QuickSort(T array[] , int left , int right)
{
    if (left >= right)
    {
        return;
    }
    int PivotIndex = Partition(array , left , right);
    QuickSort(array , left , PivotIndex);
    QuickSort(array , PivotIndex+1 , right);

}
template<typename T>
void displaySortedArray(T array[] , int size)
{
    cout << '[';
    for (int i = 0 ;  i< size ; i ++)
    {
        if (i == size-1 )
        {
            cout << array[i] << ']';
        }
        else
        {
            cout << array[i] <<", ";
        }
    }
}
int main()
{
    int array[5] ={3 , 2 , 8 , 1 , 9};
   // SelectionSort(array ,5);
  //  InsertionSort(array, 5);
    //ShellSort( array , 5);
   // BubbleSort(array , 5);
    QuickSort(array , 0 , 4);
    displaySortedArray(array , 5);
   // int a = 4 , b = 6;
   // Swap(a , b);
   // cout << a << b;
    return 0 ;
}