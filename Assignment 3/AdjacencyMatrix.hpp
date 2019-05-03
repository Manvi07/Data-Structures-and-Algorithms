#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX 1

#include "GraphAdjacencyBase.hpp"
#include "seqLinearList.hpp"
#include <fstream>
#include <iomanip>

/*
 * 	Class AdjacencyMatrix
 *	Can be used to represent a Graph using adjacency-matrix.
 */
class AdjacencyMatrix : public GraphAdjacencyBase {

	int size;
	LinearList<int>indegree;
	int Vertices;
	public:

	LinearList<int> *graph;
		AdjacencyMatrix(int vertices)
		{
			graph = new LinearList<int>[vertices];
			for(int i=0; i<vertices; i++)
			{
				graph[i].initialise(vertices);
			}
			indegree.initialise(vertices);
			Vertices = vertices;
		};
		~AdjacencyMatrix(){};
		/*
	 * Function: edgeExists
	 * Returns true if an edge exists between vertices i and j, false otherwise.
	 */
  		bool edgeExists(int i, int j)
  		{
  			if(graph[i][j] !=0 )
  				return true;
  				else
  			return false;
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
	 * Function add:
	 * Adds an edge between vertices i and j
	 */
  	void add(int i, int j)
  	{
			if(i>=vertices() or j>=vertices() or i<0 or j<0)
  		{
  			cout << "Out of range \n";
  			return;
  		}
  		graph[i][j] = 1;
  		indegree[j]++;
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
  		graph[i][j] = w;
  		indegree[j]++;
  	}
  	/*
	 * Function: remove
	 * Deleted the edge between vertices i and j
	 */
  	void remove(int i, int j)
  	{
  		graph[i][j] = 0;
  		indegree[j]--;
  	}
  	/*
	 * Function: degree
	 * Returns the degree of the vertex i
	 */
  	int degree(int i)
  	{
  		int count= 0;
  		for(int j=0; j<vertices(); j++)
  		{
  			if(graph[i][j])
  				count ++;
  		}
  		return count + indegree[i];
  	}
  	int weight(int i, int j)
  	{
  		return graph[i][j];
  	}
		void printGraph()
		{
			ofstream oFile("adj_mat.txt");
			for(int i=0; i<vertices(); i++)
			{
				for(int j=0; j<vertices(); j++)
				{
					oFile << setw(2) << graph[i][j] << " ";
				}
				oFile << endl;
			}
			oFile.close();
		}
};

#endif /* ifndef ADJACENCY_MATRIX */
