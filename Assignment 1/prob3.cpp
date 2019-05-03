/*Author: Manvi Gupta
 *CS202 - Data Structures and Algorithms
 *Assignment 1
 *Merge Sort
 */
#include <iostream>
#include <string.h>
#include "sorting.hpp"
#include "seqLinearList.hpp"

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	LinearList<int> l(n);
	LinearList<int> t(n);
	for(int i=0;i<n;i++)
		{
			cin >> l[i];
		}

	Sort<int>s;
	s.mergeSort(l, 0, n/2-1);
	s.mergeSort(l, n/2, n-1);
	for(int i=0;i<n/2;i++)
		t[i] = l[n/2-i-1];
	for(int i=n/2;i<n;i++)
		t[i] = l[n - i + n/2-1];


	int i = 0;
	int j=0;
	int k2=k;
	while(k)
	{

		if(l[i]<l[n-i-1])
		{
			swap(l[i], l[n-i-1]);
			k--;i++;
		}
		else
		{
			break;
		}
	}
	i=0;j=0;
	while(k2)
	{

		if(t[i]>t[n-i-1])
		{
			swap(t[i], t[n-i-1]);
			k2--;i++;
		}
		else
		{
			break;
		}
	}


	int sum1=0, sum2=0;
	for(int i=0;i<n/2;i++)
		{
			sum1 = sum1+l[i];
		}
	for(int i=n/2;i<n;i++)
		{
			sum2+=t[i];
		}

	if(sum1>sum2)
	{
		for(int i=0;i<n/2;i++)
			cout << l[i] << " ";
		cout << endl;
		for(int i=n/2;i<n;i++)
			cout << l[i] << " ";
		cout << endl;
	}
	else
	{
		for(int i=n/2;i<n;i++)
			cout << t[i] << " ";
		cout << endl;
		for(int i=0;i<n/2;i++)
			cout << t[i] << " ";
		cout << endl;
	}
	return 0;
}
