#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST 1

#include <iostream>
#include <fstream>
#include  "list.hpp"
#include "seqLinearList.hpp"
#include "GraphAdjacencyBase.hpp"
using namespace std;
/*
 * 	Class AdjacencyList
 *	Can be used to represent a Graph using adjacency-list.
 */


class AdjacencyList : public GraphAdjacencyBase {
	int size;
	int Vertices;
	LinearList<int>indegree;
	public:

	LinkedList<int>*list;
	AdjacencyList(int vertices)
	{
		list = new LinkedList<int>[vertices];
		indegree.initialise(vertices);
		size = 0;
		Vertices = vertices;
	};
	~AdjacencyList()
	{
		delete list;
	};
	/*
	 * Function: edgeExists
	 * Returns true if an edge exists between vertices i and j, false otherwise.
	 */
	bool edgeExists(int i, int j)
	{
		return list[i].search(j);
	}
	/*
	 * Function add:
	 * Adds an edge between vertices i and j
	 */
  	void add(int i, int j)
  	{
  		if(i>=Vertices or j>=Vertices)
  		{
  			cout << "Out of range \n";
  			return;
  		}
			if(edgeExists(i, j))
			return;
  		list[i].insert(j, 1);
  		indegree[j]++;
  		size++;
  	}
  			/*
	 * Function add_weighted:
	 * Adds a 'w' weighted edge between vertices i and j
	 */
  	void add_weighted(int i, int j, int w)
  	{
			if(i>=vertices() or j>=vertices() or i<0 or j<0)
  		{
  			cout << "Out of range \n";
  			return;
  		}
  		list[i].insert(j, w);
  		indegree[j]++;
  		size++;
  	}
	/*
	 * Function: vertices
	 * Returns the number of vertices in the adjacency structure.
	 */
  	int vertices()
  	{
  		return Vertices;
  	}
  	/*
	 * Function: edges
	 * Returns the number of edges in the adjacency structure.
	 */
  	int edges()
  	{
  		return size;
  	}
  	/*
	 * Function: remove
	 * Deleted the edge between vertices i and j
	 */
  	void remove(int i, int j)
  	{
  		list[i].remove(j);
  		if(edgeExists(i, j))
  		{
  			indegree[j]--;
  			size--;
  		}
  	}
  	/*
	 * Function: degree
	 * Returns the degree of the vertex i
	 */
  	int degree(int i)
  	{
  		return list[i].size+indegree[i];
  	}
  	/*
	 * Function: showEdges
	 * diplays the connected edges
	 */
  	void showEdges(int v)
  	{
  		cout << v << " ";
	  	list[v].display();
  	}
  	int weight(int i, int j)
  	{
  		return list[i].wt(j);
  	}
		LinkedList<int> operator [](const int &i){return list[i];}
		void printGraph()
		{
			ofstream oFile("adj_lst.txt");
			for(int i=0; i<vertices(); i++)
			{
				oFile << i << "-> ";
				node<int> *temp = list[i].head;
				while(temp!=nullptr)
				{
					oFile << temp->val << " ";
					temp  = temp->next;
				}
				oFile << endl;
			}
			oFile.close();
		}
};
#endif /* ifndef ADJACENCY_LIST */
