/*Author: Manvi Gupta
 *CS202 - Data Structures and Algorithms
 *Assignment 1
 *Quick Sort
 */
#include <iostream>
#include <string.h>
#include "sorting.hpp"
#include "seqLinearList.hpp"

using namespace std;

int main()
{
	int n;
	cin >> n;
	LinearList<int> l(n);

	for(int i=0;i<n;i++)
		cin >> l[i];

	Sort<int>s;
	s.quickSort(l, 0, n-1);

	int ans=0;

	if(n%2==0)
	{
		for(int i=l[(n-1)/2];i<=l[n/2];i++)
			ans+=i;
	}
	else
		ans = l[n/2];
	cout << ans << endl;
	return 0;
}
