/* CS202 - Assignment 4
 * Topic :"Graphs"
 * Problem #3
 * Author : Manvi Gupta (B17092)
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include "UndirectedGraph.hpp"
#define MAX 10000000

using namespace std;

int wordlength, wordCount;
char ** words;
int * parent;
int ans = 0;
LinkedList<string>path;

bool adjacent(char a[], char b[])
{
	int count = 0;
	for(int i=0; i<wordlength; i++)
	{
		if(a[i] != b[i])
		count++;
		if(count > 1)
		return false;
	}
	if(count == 1)
	return true;
	else return false;
}

int modifiedBFS(int src, int dest)
{
	int distance[wordCount];
	bool visited[wordCount];

	for(int i=0; i<wordCount; i++)
	{
		distance[i] = MAX;
		visited[i] = false;
	}
	distance[src] = ans;
	visited[src] = true;
	LinkedList<int>Q;
	Q.insert(src, 1);
	while(!Q.isEmpty() and visited[dest] == false)
	{
		int u = Q.pop();
		visited[u] = true;
		for(int i=0; i<wordCount; i++)
		if(!visited[i] and adjacent(words[u], words[i]) and distance[i] > 1+distance[u])
		{
			distance[i] = 1 + distance[u];
			parent[i] = u;
			Q.insert(i, 1);
		}
	}
	return distance[dest]+1;
}

int main(const int argc, const char *argv[])
{

	// Openeing file.
	if(argc != 2)
	{
		cout << "Format : ./prob3 <inputFilename>\n";
		return -1;
	}
	ifstream iFile(argv[1]);
	if (!iFile.is_open())
	{
		cout << "Error Opening File!\n";
		return -1;
	}
	string s;

	//Counting the no. of rows and columns.
	while(iFile >> s)
	{
		wordCount ++;
	}
	wordlength = strlen(s.c_str());

	// Bring file pointer at the beginning.
	iFile.clear();
	iFile.seekg(0, ios::beg);

	//Memory allocation.
	words = new char*[wordCount];
	parent = new int[wordCount];
	for (int i = 0; i < wordCount; i++)
	{
		words[i] = new char[wordlength];
	}

	UndirectedGraph graph(wordCount, 'm');
	UndirectedGraph graph2(wordCount, 'l');

	//Read from file.
	for(int i=0; i<wordCount;i++)
	iFile >> words[i];

	//Create graph.
	for(int i=0; i<wordCount; i++)
	{
		for(int j=i+1; j<wordCount; j++)
		{
			if(adjacent(words[i], words[j]))
			{
				graph.add(i, j);
				graph2.add(i, j);
			}
		}
	}

	graph.printGraph();
	graph2.printGraph();

	//Input start and target string.
	string str, target;
	cout << "The start word is: ";
	cin >> str;
	cout << "The target word is: ";
	cin >> target;
	int src = -1, dest = -1;

	char a[wordlength+1], b[wordlength+1];
	strcpy(a, str.c_str());
	strcpy(b, target.c_str());

	if(adjacent(a, b))
	{
		ans = 2;
		path.insert(str, 1);
		path.insert(target, 1);
	}
	else
	{
		int flag = 0;
		for(int i=0; i<wordCount; i++)
		{
			if(strcmp(a, words[i]) == 0)
			{
				ans=0;
				src = i;
				flag = 1;
				parent[src] = -1;
				break;
			}
		}
		if(flag == 0)
		for(int i=0; i<wordCount; i++)
		{
			if(adjacent(a, words[i]))
			{
				ans = 1;
				src = i;
				parent[src] = -5;
				flag = 2;
				break;
			}
		}

		for(int i=0; i<wordCount; i++)
		{
			if(strcmp(b, words[i]) == 0)
			{
				dest = i;
				break;
			}
		}

		//If the start string has no adjacent vertex or target doesn't exist in the dictionary then return.
		if(dest == -1 or src == -1)
		{
			cout << "Inappropriate input!\n";
			return -1;
		}

		ans = modifiedBFS(src, dest);
		LinkedList<string>temp;
		int k = dest;
		if(flag == 1)
		{
			while(k != -1)
			{
				temp.insert(words[k], 1);
				k = parent[k];
			}
		}
		else if(flag == 2)
		{
			while(k != -5)
			{
				temp.insert(words[k], 1);
				k = parent[k];
			}
			temp.insert(str, 1);
		}
		int n = temp.size;
		char f[n][wordlength+1];
		for(int i=n-1; i>=0; i--)
		{
			strcpy(f[i], temp.pop().c_str());
		}
		for(int i=0; i<n; i++)
		{
			path.insert(f[i], 1);
		}
	}
	cout << "The path is:\n";
	path.display();
	cout << "The Length is: ";
	cout << ans << endl;
	iFile.close();
	return 0;
}
