#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH 1

#include "AbstractGraph.hpp"

/*
* A class to represent a directed graph.
*/
class DirectedGraph : AbstractGraph {

	GraphAdjacencyBase *base;
	char rep;

	public:
	/*
	 * Constructor: DirectedGraph
	 *
	 * Parameters: mode
	 * Used to decide which representation to use
	 * 'm' for AdjacencyMatrix
	 * 'l' for AdjacencyList
	 */
	DirectedGraph(int numVertices, char rep)
	{
		this->rep = rep;
		if(rep == 'l')
        	base = new AdjacencyList(numVertices);
      	else
        	base = new AdjacencyMatrix(numVertices);
	};
	/*
	 * Destructor
	 */
	~DirectedGraph(){};

	bool edgeExists(int i, int j)
    {
      return base->edgeExists(i, j);
    }
  /*
   * Function: vertices
   * Returns the number of vertices in the adjacency structure.
   */
    int vertices()
    {
      return base->vertices();
    }
  /*
   * Function: edges
   * Returns the number of edges in the adjacency structure.
   */
   int edges()
   {
    return base->edges();
   }
  /*
   * Function add:
   * Adds an edge between vertices i and j
   */
    void add(int i, int j)
    {
      base->add(i, j);
    }
           /*
   * Function add_weighted:
   * Adds a 'w' weighted edge between vertices i and j
   */
    void add_weighted(int i, int j, int w)
    {
      base->add_weighted(i, j, w);
    }

  /*
   * Function: remove
   * Deleted the edge between vertices i and j
   */
    void remove(int i, int j)
    {
      base->remove(i, j);
    }
  /*
   * Function: degree
   * Returns the degree of the vertex i
   */
    int degree(int i)
    {
      return base->degree(i);
    }
    void dfs(void (*work)(int&))
    {
      	int Vertices = vertices();
	    LinearList<int>visited(Vertices);
	    if(rep == 'm')
	    {
	    	for(int i=0; i<Vertices; i++)
	    	{
	    		if(!visited[i])
	    			DFS_Matrix(work, i, visited);
	    	}
	    }
	    else
	    {
	    	for(int i=0; i<Vertices; i++)
	    	{
	    		if(!visited[i])
	    			DFS_List(work, i, visited);
	    	}
	    }
	}
	void DFS_List(void (*work)(int&), int src, LinearList<int> &visited)
	{
		visited[src] = 1;
		(*work)(src);
		node<int> *temp = ((AdjacencyList*)base)->list[src].head;
		while(temp)
		{
			if(!visited[temp->val])
			DFS_List(work, temp->val, visited);
			temp = temp->next;
		}
	}
	void DFS_Matrix(void (*work)(int&), int src, LinearList<int> &visited)
	{
		visited[src] = 1;
		(*work)(src);
		for(int i=0; i<vertices(); i++)
		{
			if(((AdjacencyMatrix*)base)->graph[src][i] and !visited[i])
				DFS_Matrix(work, i, visited);
		}
	}

	void bfs(void (*work)(int&))
	{
		int Vertices = vertices();
		LinearList<int> visited(Vertices);
		if(rep == 'm')
		{
			for(int i=0; i<Vertices; i++)
	    	{
	    		if(!visited[i])
	    			BFS_Matrix(work, i, visited);
	    	}
		}
		else
	    {
	    	for(int i=0; i<Vertices; i++)
	    	{
	    		if(!visited[i])
	    			BFS_List(work, i, visited);
	    	}
	    }
	}
	void BFS_List(void (*work)(int&), int src, LinearList<int> &visited)
	{
		LinkedList<int> Q;
		Q.insert(src, 1);
		node<int> *temp = ((AdjacencyList*)base)->list[src].head;
		while(Q.size>0)
		{
			int u = Q.pop();
			visited[u] = 1;
			(*work)(u);
			temp = ((AdjacencyList*)base)->list[u].head;
			while(temp)
			{
				if(!visited[temp->val])
				{
					Q.insert(temp->val, 1);
				}
				temp = temp->next;
			}
		}
	}
	void BFS_Matrix(void (*work)(int&), int src, LinearList<int> &visited)
	{
		LinkedList<int> Q;
		Q.insert(src, 1);
		visited[src] = 1;
		while(Q.size)
		{
			int u = Q.pop();
			(*work)(u);
			for(int i=0; i<vertices(); i++)
			{
				if(!visited[i] and ((AdjacencyMatrix*)base)->graph[u][i])
				{
					visited[i] = 1;
					Q.insert(i, 1);
				}
			}
		}
	}
	int weight(int i, int j)
	  {
	    return base->weight(i, j);
	  }
		void printGraph()
		{
			base->printGraph();
		}
};

#endif /* ifndef DIRECTED_GRAPH */
