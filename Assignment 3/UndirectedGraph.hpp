#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH 1

#include "AbstractGraph.hpp"

/*
* A class to represent an UndirectedGraph
* Subclasses AbstractGraph
*/
class UndirectedGraph : public AbstractGraph {

	GraphAdjacencyBase *base;
		char rep;
 	public:

  	/*
   	* Constructor: UndirectedGraph
   	*
   	* Parameters: mode
   	* Used to decide which representation to use
   	* 'm' for AdjacencyMatrix
   	* 'l' for AdjacencyList
   	*/
  	UndirectedGraph(int vertices, char mode)
    {
      rep = mode;
      if(mode == 'l')
        base = new AdjacencyList(vertices);
      else
        base = new AdjacencyMatrix(vertices);
    };
  	/*
  	* Destructor
  	*/
  	~UndirectedGraph(){};
     /*
   * Function: edgeExists
   * Returns true if an edge exists between vertices i and j, false otherwise.
   */
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
      base->add(j, i);
    }
        /*
   * Function add_weighted:
   * Adds a 'w' weighted edge between vertices i and j
   */
    void add_weighted(int i, int j, int w)
    {
      base->add_weighted(i, j, w);
      base->add_weighted(j, i, w);
    }
  /*
   * Function: remove
   * Deleted the edge between vertices i and j
   */
    void remove(int i, int j)
    {
      base->remove(i, j);
      base->remove(j, i);
    }
		void show()
		{
			for(int i=0; i< vertices(); i++)
			{
				for(int j=0; j<vertices(); j++)
				cout << edgeExists(i, j) << " ";
				cout << endl;
			}

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
      int k=1;
      if(rep == 'm')
      {
        for(int i=0; i<Vertices; i++)
        {
          if(!visited[i])
            {
              cout << "Connected Component " << k << ": " ;
              DFS_Matrix(work, i, visited);
              cout << "\n";
              k++;
            }
        }
      }
      else
      {
        for(int i=0; i<Vertices; i++)
        {
          if(!visited[i])
            {
              cout << "Connected Component " << k << ": " ;
              DFS_List(work, i, visited);
              cout << "\n";
              k++;
            }
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
    while(!Q.isEmpty())
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

#endif /* ifndef UNDIRECTED_GRAPH */
