/*Author: Manvi Gupta
 *CS202 - Data Structures and Algorithms
 *Assignment 1
 *Problem 4
 */
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "seqLinearList.hpp"
#include "sorting.hpp"

using namespace std;

int count;
bool isPrime(int n)
{
    if (n < 1)  return false;
    if(n==1) return true;
    for (int i=2; i<n; i++)
        if (n%i == 0)
            return false;

    return true;
}

int gcd(int a, int b)
{
	if (a == 0)
	      return b;
    return gcd(b % a, a);
}

bool factorsCheck(int a, int b)
{
	int g = gcd(a,b);
	if(!isPrime(g))
		return true;
	else
		return false;
}

typedef struct l{
  int d;
  double c;
  struct l* next;
}List;

List* createList()
{
  return NULL;
}
void printList(List* l)
{
  List* temp=l;
  while(temp)
  {
    printf("%d-->",temp->d);
    temp=(List*)temp->next;
  }
  printf("\n" );
}

List *insertAfter(List *l, int val, double p)
{
	List *temp=l;
	if(l==NULL)
	{
		l=(List*)malloc(sizeof(List));
	    l->d=val;
	    l->c=p;
	    l->next=NULL;
	    return l;
	}
	if(factorsCheck(val, temp->d)==true);
	else
	{while(temp->next!=NULL and factorsCheck(val, temp->next->d)==false)
	{
		temp=temp->next;
	}
	}
	List *newNode=createList();
	newNode = (List*)malloc(sizeof(List));
	newNode->d=val;
	newNode->c=p;
	newNode->next=temp->next;
	temp->next=newNode;
    return l;
}

List *deleteNode(List* l, int key)
{
    List *temp =l;
    List *prev;
    if (temp != NULL && temp->d == key)
    {
        l = temp->next;
        free(temp);
        return l;
    }
    while (temp != NULL && temp->d != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {printf("Not found.\n" );return l;}
    prev->next = temp->next;
    free(temp);
    return l;
}
List *findMin(List* l)
{
	double m = 100000;
	List *temp = l;
	List *minNode;
	while(temp)
	{
		if(temp->c < m)
		{
			m = temp->c;
			minNode = temp;
		}
		temp = temp->next;
	}
	return minNode;
}
void exchange(List *k, List *p)
{
	List *temp;
	if(k->d!=p->d)
		count++;
	temp->d = k->d;
	temp->c = k->c;
	k->d = p->d;
	k->c = p->c;
	p->d = temp->d;
	p->c = temp->c;
}
List *insert(List *l,int val, double d)
{
  List *temp=l;
  if(temp==NULL)
  {
    l=(List*)malloc(sizeof(List));
    l->d=val;
    l->c = d;
    l->next=NULL;
    return l;
  }
  while(temp->next)
  {
    temp=temp->next;
  }
  temp->next=(List*)malloc(sizeof(List));
  temp->next->d=val;
  temp->next->c = d;
  temp->next->next=NULL;
  return l;
}
List* sortList(List *l)
{
	List *temp = l;
	List *ans=NULL;
	count=0;
	while(temp)
	{
		ans = insert(ans, findMin(temp)->d, findMin(temp)->c);
		exchange(temp, findMin(temp));
		temp = temp->next;
	}
	return ans;
}

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	LinearList<int> id(k);
	LinearList<double> height(k);

	for(int i=0;i<k;i++)
		cin>>id[i]>>height[i];

	char s[10];

	List *l[26];

	for(int i=0;i<26;i++)
	l[i]= createList();

	char c;
	int h;

	for(int i=0;i<k;i++)
	{
		scanf(" %c%d",&c, &h);
		l[c-'A'] = insertAfter(l[c-'A'],h, height[id.search(h)]);
	}
	for(int i=0;i<26;i++)
		if(l[i])
		{
			l[i] = sortList(l[i]);
			// printList(l[i]);
			cout << count*0.5 <<'\t';

		}
		cout << endl;
	return 0;
}
