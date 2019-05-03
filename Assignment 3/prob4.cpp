/* CS202 - Assignment 4
 * Topic :"Graphs"
 * Problem #4
 * Author : Manvi Gupta (B17092)
 */

#include <iostream>
#include "DirectedGraph.hpp"
#define MAX 1000000000

using namespace std;

int v, e;
LinearList<int> Distance(v);
LinearList<bool> set(v);
LinearList<int> path(v);
LinearList<int> parent(v);
LinkedList<int> Queue;

void dijkstra(DirectedGraph g, int src)
{
	for(int i=0; i<v; i++)
	{
		Distance[i] = MAX;
		set[i] = false;
		parent[i] = -1;
		path[i] = -1;
	}
	Distance[src] = 0;
	for(int i=0; i<v; i++)
	{
		Queue.push(i, Distance[i]);
	}

	while(!Queue.isEmpty())
	{
		int u = Queue.pop();
		set[u] = true;
		for(int j=0; j<v; j++)
		{
			if(!set[j] and g.edgeExists(u, j) and Distance[u]+g.weight(u, j) < Distance[j] )
			{
				parent[j] = u;
				Distance[j] = Distance[u] + g.weight(u, j);
				Queue.push(j, Distance[j]);
			}
		}
	}
}

int main()
{
	cin >> v >> e;
	int v1, v2, w;

	DirectedGraph g(v, 'l');
	DirectedGraph p(v, 'm');
	for(int i=0; i<e; i++)
	{
		cin >> v1 >> v2 >> w;
		g.add_weighted(v1-1, v2-1, w);
		p.add_weighted(v1-1, v2-1, w);
	}
	g.printGraph();
	p.printGraph();
	dijkstra(g, 0);
	int i = v-1;
	int k = 0;
	while(i != 0)
	{
		path[k] = i+1;
		k++;
		i = parent[i];
	}
	path[k] = 1;
	cout << "The path is: ";
	for(int i=v-1; i>0; i--)
	{
		if(path[i]>0)
		{
			cout << path[i] << "->";
		}
	}
	cout <<v<< endl;
	cout << "Total Time is: " << Distance[v-1] << endl;
	return 0;
}
