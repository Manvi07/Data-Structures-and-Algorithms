/* CS202 - Assignment 4
 * Topic :"Graphs"
 * LinkedList
 * Author : Manvi Gupta (B17092)
 */


#ifndef LINKED_LIST
#define LINKED_LIST 1
#include <iostream>
using namespace std;

template<class Item>

struct node
{
	Item val;
	int weight;
	node* next;
};

template<class Item>
class LinkedList{
	public:
		node<Item> *head, *tail;
		int size;
		LinkedList()
		{
			head = tail = nullptr;
			size = 0;
		}
		void insert(Item k, int w)
		{
				node<Item> *temp;
		    temp = new node<Item>;
		    temp->val = k;
		    temp->weight = w;
		    temp->next = nullptr;
		    if(tail != nullptr){
		    	tail->next = temp;
		    }
		    tail = temp;
		    if(head == nullptr)
		    	head = tail;
		    size++;
		}
		void push(Item k, int p)
		{
			node<Item>* temp = head;
			size++;
			if(temp == nullptr)
			{
				insert(k, p);
				return;
			}
			node<Item>* newNode = new node<Item>;
			newNode->val = k;
			newNode->weight = p;
			if(head->weight >= p)
			{
				newNode->next = head;
				head = newNode;
			}
			else
			{
				while(temp->next and temp->next->weight < p)
				{
					temp = temp->next;
				}
				if(temp == tail)
					tail = newNode;
				newNode->next = temp->next;
				temp->next = newNode;
			}
		}
		void remove(Item k)
		{
			node<Item> *temp = head;
			if(temp == nullptr)
				return;
			if(temp->val == k)
			{
				head = temp->next;
				delete temp;
				size--;
			}
			else
			{
				node<Item> *prev;
				while(temp != tail and temp->val != k)
				{
					prev = temp;
					temp = temp->next;
				}
				if(temp == tail and temp->val != k)
					return;
				else if(temp == tail)
					{
						tail = prev;
					}
				prev->next = temp->next;
				delete temp;
				size--;
			}
		}
		bool search(Item k)
		{
			node<Item>* temp = head;
			while(temp)
			{
				if(temp->val == k)
					return true;
				temp = temp->next;
			}
			return false;
		}
		void display()
		{
			node<Item> *temp = head;
			while(temp!=nullptr)
			{
				cout << temp->val << "\n";
				temp  = temp->next;
			}
			// cout << endl;
		}
		void print()
		{
			node<Item> *temp = head;
			while(temp!=nullptr)
			{
				cout << temp->val << " ";
				temp  = temp->next;
			}
			cout << endl;
		}
		Item pop()
		{
			node<Item>* temp = head;
			if(temp == nullptr)
				return Item();
			Item u = head->val;
			head = temp->next;
			delete temp;
			size--;
			return u;
		}
		int wt(Item i)
		{
			node<Item>* temp = head;
			while(temp)
			{
				if(temp->val == i)
					return temp->weight;
				temp = temp->next;
			}
		}
		bool isEmpty()
		{
			if(head == nullptr or size == 0)
				return true;
			else
				return false;
		}
};
#endif
