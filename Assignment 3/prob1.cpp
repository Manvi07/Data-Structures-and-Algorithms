/* CS202 - Assignment 4
 * Topic :"Graphs"
 * Problem #1
 * Author : Manvi Gupta (B17092)
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include "UndirectedGraph.hpp"
using namespace std;

int rows, cols;
LinkedList<int>Q;
int ** M;
char **c;

int pairUp(int x, int y)
{
	return (cols*x) + y;
}

void modifiedBFS(UndirectedGraph g)
{
	while(!Q.isEmpty())
	{
		int y = Q.head->weight;
		int x = Q.pop();
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				if(g.edgeExists(pairUp(x, y), pairUp(i, j)) and M[i][j] == -1 and c[i][j] != 'W')
				{
					M[i][j] = M[x][y] + 1;
					Q.insert(i, j);
				}
			}
		}
	}
}


void SolveGraph()
{
	UndirectedGraph g(rows*cols, 'l');
	UndirectedGraph p(rows*cols, 'm');
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			int k = pairUp(i, j);
			if(i+1 < rows)
			{
				g.add(pairUp(i+1, j), k);
				p.add(pairUp(i+1, j), k);
			}
			if(i-1 >=0)
			{
				g.add(k, pairUp(i-1, j));
				p.add(k, pairUp(i-1, j));
			}
			if(j+1<cols)
			{
				g.add(k, pairUp(i, j+1));
				p.add(k, pairUp(i, j+1));
			}
			if(j-1 >= 0)
			{
				g.add(k, pairUp(i, j-1));
				p.add(k, pairUp(i, j-1));
			}
		}
	}
	g.printGraph();
	p.printGraph();
	modifiedBFS(g);
}
int main()
{
		ifstream iFile("input1.in");
		if(!iFile.is_open())
		{
			cout << "Error Opening File!\n";
			return -1;
		}
		string line;
		int character = 0;
		while (getline(iFile, line))
	      {
					 cols = (strlen(line.c_str())+1)/2;
					 rows++;
				}

		iFile.clear();
    iFile.seekg(0, ios::beg);
		M = new int*[rows];
		c = new char*[rows];
		for(int i=0; i<rows; i++)
		{
			M[i] = new int[cols];
			c[i] = new char[cols];
		}
		int cnt=0;
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				iFile >> c[i][j];
				if(c[i][j] == 'G')
				{
					M[i][j] = 0;
					Q.insert(i, j);
				}
				else M[i][j] = -1;
			}
		}
		SolveGraph();
		ofstream oFile("output1.out");
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				oFile << M[i][j] << " ";
			}
			oFile << endl;
		}
		cout << "The output has been written to File.\n";
		oFile.close();
		iFile.close();
		delete M, c;
	return 0;
}
