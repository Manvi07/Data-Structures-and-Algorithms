/* CS202 - Assignment 4
 * Topic :"Graphs"
 * PriorityQueue
 * Author : Manvi Gupta (B17092)
 */

#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE 1
#include <iostream>
using namespace std;

struct Node
{
	int val;
	int priority;
};

class PriorityQueue
{
private:
	Node *array;
	int currentSize;
	int size;
public:
	PriorityQueue(int n)
	{
		size = n;
		array = new Node[size+1];
	}
	~PriorityQueue(){delete array;}
	void push(int v, int p)
	{
		int i=currentSize+1;
		for(; i>1 and p < array[i/2].priority; i=i/2)
			array[i] = array[i/2];
		array[i].val = v;
		array[i].priority = p;
		currentSize++;
	}
	void extract_min()
	{
		if(currentSize == 0)
		{
			cout << "Underflow!\n";
			return ;
		}
		array[1] = array[currentSize];
		currentSize--;
		heapify(1);
	}
	void heapify(int t)
	{
		int left = 2*t;
		int right = 2*t+1;
		int index= t;
		if(left <= currentSize and array[t].priority > array[left].priority)
			index = left;
		if(right <= currentSize and array[t].priority > array[right].priority)
			index = right;

		if(t!=index)
		{
			swap(array[index], array[t]);
			heapify(index);
		}
	}
	void display()
	{
		for(int i=1; i<=currentSize; i++)
		{
			cout  << array[i].priority << " ";
		}
		cout << endl;
	}
};

#endif
