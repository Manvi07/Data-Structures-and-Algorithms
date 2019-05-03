#include <iostream>
#include <cstring>
#include "BinaryTree.cpp"
#include "BSTree.cpp"
#include "AVL.cpp"
#include "RBTree.cpp"

#define KEY int
#define VALUE int

using namespace std;

void func()
{
	cout << "\nEnter each query as follows: \n";
	cout << "{1 x} to insert x into the tree.\n";
	cout << "{2 x} to delete one occurence of x from tree if present.\n";
	cout << "{3 x} to find x in tree.\n";
	cout << "{4} to print value of maximum element in the tree.\n";
	cout << "{5} to print value of minimum element in the tree.\n";
}

int main(int argc, char const *argv[])
{
	if(argc !=2 )
	{
		cout << "Command line: ./trees tree-name\n";
		return -1;
	}
	int Q;
	string s = argv[1];
	if(s == "bt")
	{
		cout << "Binary Tree.\n";
		cout << "Enter the number of queries to be answered: ";
		cin >> Q;
		func();
		BinaryTree<KEY, VALUE>Tree;
		while(Q--)
		{
			int query;
			KEY key;
			cin >> query;
			if(query == 1)
			{
				cin >> key;
				Tree.put(key, 1);
			}
			else if(query == 2)
			{
				cin >> key;
				Tree.remove(key);
			}
			else if(query == 3)
			{
				cin >> key;
				cout << Tree.has(key) << endl;
			}
			else if(query == 4)
			{
				cout << "Maximum element: " << Tree.maximum() << endl;
			}
			else if(query == 5)
			{
				cout << "Minimum element: " <<Tree.minimum() << endl;
			}
			else
			{
				cout << "Invalid Query! Try again\n";
				Q++;
			}
		}
	}
	else if(s == "bst")
	{
		cout << "Binary Search Tree.\n";
		cout << "Enter the number of queries to be answered: ";
		cin >> Q;
		func();
		BSTree<KEY, VALUE>Tree;
		while(Q--)
		{
			int query;
			KEY key;
			cin >> query;
			if(query == 1)
			{
				cin >> key;
				Tree.put(key, 1);
			}
			else if(query == 2)
			{
				cin >> key;
				Tree.remove(key);
			}
			else if(query == 3)
			{
				cin >> key;
				cout << Tree.has(key) << endl;
			}
			else if(query == 4)
			{
				cout << "Maximum element: " << Tree.maximum() << endl;
			}
			else if(query == 5)
			{
				cout << "Minimum element: " <<Tree.minimum() << endl;
			}
			else
			{
				cout << "Invalid Query! Try again\n";
				Q++;
			}
		}
	}
	else if(s == "avl")
	{
		cout << "AVL\n";
		cout << "Enter the number of queries to be answered: ";
		cin >> Q;
		func();
		AVL<KEY, VALUE>Tree;
		while(Q--)
		{
			int query;
			KEY key;
			cin >> query;
			if(query == 1)
			{
				cin >> key;
				Tree.put(key, 1);
			}
			else if(query == 2)
			{
				cin >> key;
				Tree.remove(key);
			}
			else if(query == 3)
			{
				cin >> key;
				cout << Tree.has(key) << endl;
			}
			else if(query == 4)
			{
				cout << "Maximum element: " << Tree.maximum() << endl;
			}
			else if(query == 5)
			{
				cout << "Minimum element: " <<Tree.minimum() << endl;
			}
			else
			{
				cout << "Invalid Query! Try again\n";
				Q++;
			}
		}
	}
	else if(s == "rbt")
	{
		cout << "Red Black Tree.\n";
		cout << "Enter the number of queries to be answered: ";
		cin >> Q;
		func();
		RBTree<KEY, VALUE>Tree;
		while(Q--)
		{
			int query;
			KEY key;
			cin >> query;
			if(query == 1)
			{
				cin >> key;
				Tree.put(key, 1);
			}
			else if(query == 2)
			{
				cin >> key;
				Tree.remove(key);
			}
			else if(query == 3)
			{
				cin >> key;
				cout << Tree.has(key) << endl;
			}
			else if(query == 4)
			{
				cout << "Maximum element: " << Tree.maximum() << endl;
			}
			else if(query == 5)
			{
				cout << "Minimum element: " <<Tree.minimum() << endl;
			}
			else
			{
				cout << "Invalid Query! Try again\n";
				Q++;
			}
		}
	}
	else
	{
		cout << "Invalid command!\n";
	}

	return 0;
}