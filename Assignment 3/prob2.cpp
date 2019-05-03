/* CS202 - Assignment 4
 * Topic :"Graphs"
 * Problem #2
 * Author : Manvi Gupta (B17092)
 */

#include <iostream>
#include <fstream>
#include "UndirectedGraph.hpp"
using namespace std;

void print(int &x)
{
	cout << x << " ";
}

int main()
{
	ifstream iFile("input2.in");
	streambuf *psbuf, *backup;
	ofstream oFile("output2.out");

	if(!iFile.is_open())
		{
			cout << "Error Opening File!\n";
			return -1;
		}

	int v, e;
	iFile >> v >> e;
	int v1, v2;
	UndirectedGraph g(v, 'l');
	UndirectedGraph p(v, 'm');
	for(int i=0; i<e; i++)
	{
		iFile >> v1 >> v2;
		g.add(v1, v2);
		p.add(v1, v2);
	}
	backup = cout.rdbuf();
	psbuf = oFile.rdbuf();
	cout.rdbuf(psbuf);
	g.dfs(&print);
   	g.printGraph();
	p.printGraph();
	cout.rdbuf(backup);
	cout << "The output has been written to File.\n";
	oFile.close();
	iFile.close();
	return 0;
}
