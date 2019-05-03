#ifndef SORTING_HPP
#define SORTING_HPP
#include <iostream>
#include "seqLinearList.hpp"

template<class Item>
class Sort{
	private:
		
	public:
		void insertionSort(LinearList<Item>& A, int low, int high);
		void bubbleSort(LinearList<Item>& A, int low, int high);
	 	void rankSort(LinearList<Item>& A, int low, int high);
            	void selectionSort(LinearList<Item>& A, int low, int high);
		void mergeSort(LinearList<Item>& A, int low, int high);
		void merge(LinearList<Item>& A, int low, int mid, int high);
           	void quickSort(LinearList<Item>& A, int low, int high);
           	int partition(LinearList<Item>& A, int low, int high);
           	void heapSort(LinearList<Item>& A, int low, int high);
           	void heapify(LinearList<Item>& A, int low, int high, int index);
};

template<class Item>
void Sort<Item>::insertionSort(LinearList<Item>& A, int low, int high)
{
	Item key;
  for(int i=low;i<high;i++)
  {
    key = A[i];
    int j = i-1;
    while(j>=0 and key<A[j])
    {
      A[j+1] = A[j];
      j--;
    }
    A[j+1]=key;
    }
}
template<class Item>
void Sort<Item>::bubbleSort(LinearList<Item>& A, int low, int high)
{
	Item temp;
	 for(int i=low;i<high;i++)
  {
      for(int j=i+1;j<high;j++)
    {
      if(A[i]>A[j])
      {
      	temp = A[i];
      	A[i] = A[j];
      	A[j] = temp;
      }
    }
  }
}

template<class Item>
void Sort<Item>::rankSort(LinearList<Item>& A, int low, int high)
{
	LinearList<Item> r(high-low);
	for(int i=0;i<high-low;i++)
		r[i]=0;

	for(int i=low+1;i<high;i++)
		for(int j=low;j<i;j++)
	  	if(A[i]<A[j])
	  		r[j]++;
	  	else
	  		r[i]++;
	LinearList<Item> u(high-low);
	for(int i=low;i<high;i++)
	  u[r[i]] = A[i];
	for(int i=low;i<high;i++)
	  A[i] = u[i];
}

template<class Item>
void Sort<Item>::selectionSort(LinearList<Item>& A, int low, int high)
{
	int min_index;
	Item temp;
    for (int i=low; i<	high; i++)
    {
        min_index = i;
        for (int j=i+1; j<high; j++)
          if (A[j]<A[min_index])
            min_index = j;
        swap(A[min_index], A[i]);
    }
}
template<class Item>
void Sort<Item>::merge(LinearList<Item>& A, int low,int mid, int high)
{
  int s1 = mid - low + 1;
  int s2 = high -mid;
  LinearList<Item>left(s1);
  LinearList<Item>right(s2);
  for(int i=0;i<s1;i++)
  left[i] = A[low+i];
  for(int i = 0;i<s2;i++)
  right[i] = A[mid+i+1];
  int i=0,k=low,j=0;
  while(i<s1 and j< s2)
  {
    if(left[i]<=right[j])
    {
      A[k] = left[i];
      k++;
      i++;
    }
    else
    {
      A[k] = right[j];
      j++;
      k++;
    }
  }
  while(i<s1)
  {
    A[k] = left[i];
    k++;
    i++;
  }
  while(j<s2)
  {
    A[k] = right[j];
    k++;
    j++;
  }
}
template<class Item>
void Sort<Item>::mergeSort(LinearList<Item>& A, int low, int high)
{
	if(low<high)
  {
    Item mid = (low+high)/2;
    mergeSort(A, low, mid);
    mergeSort(A, mid+1, high);
    merge(A, low, mid, high);
  }
}
template<class Item>
int Sort<Item>::partition(LinearList<Item>& A, int low, int high)
{
	Item pivot = A[high];
  int partitionIndex = low;
  for(int i = partitionIndex; i<high; i++)
  {
    if(A[i]<=pivot)
    {
      swap(A[i], A[partitionIndex]);
      partitionIndex++;
    }
  }
  swap(A[partitionIndex], A[high]);

return partitionIndex;
}
template<class Item>
void Sort<Item>::quickSort(LinearList<Item>& A, int low, int high)
{
	if(low<high)
  {
    int p = partition(A, low, high);
    quickSort(A, low, p-1);
    quickSort(A, p+1, high);
  }
}
template<class Item>
void Sort<Item>::heapify(LinearList<Item>& A, int low,int high, int index)
{
	int Max = index;
	int left = 2*index +1;
	int right = 2*index +2;

	if(left < high and A[left]>A[Max])
		Max = left;
	if(right< high and A[right]>A[Max])
		Max = right;
	if(Max!=index)
	{
		swap(A[index], A[Max]);
		heapify(A, low, high, Max);
	}
}
template<class Item>
void Sort<Item>::heapSort(LinearList<Item>& A, int low, int high)
{
	for(int i = high/2-1; i>=low; i--)
	{
		heapify(A, low, high, i);
	}
	for(int i=high-1; i>=low; i--)
	{
		swap(A[low], A[i]);
		heapify(A, low, i, low);
	}

}
#endif