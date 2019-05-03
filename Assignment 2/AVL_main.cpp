/*CS-202 DATA STRUCTURES AND ALGORITHMS 
 *Assignment-2
 *Topic : Trees
 *Author : MANVI GUPTA (B17092)
 */

#include <iostream>
#include "BinaryTree.cpp"
#include "BSTree.cpp"
#include "AVL.cpp"
#define KEY int 
#define VALUE int

using namespace std;

int main(int argc, char const *argv[])
{
	int Q;
	cout << "Enter the number of queries to be answered: ";
	cin >> Q;
	cout << "\nEnter each query as follows: \n";
	cout << "{1 x y} to insert (x,y) into the tree.\n";
	cout << "{2 x} to delete one occurence of x from tree if present.\n";
	cout << "{3 x} to find x in tree.\n";
	cout << "{4} to print value of maximum element in the tree.\n";
	cout << "{5} to print value of minimum element in the tree.\n";
	cout << "{6} to print Preorder Traversal of the tree.\n";
    cout << "{7} to print Inorder Traversal of the tree. \n";
    cout << "{8} to print postorder Traversal of the tree." << '\n';
    cout << "{9 x} to get value corresponding to key x in the tree." << '\n';
    cout << "{10 x} to get successor of x in the tree." << '\n';
    cout << "{11 x} to get predecessor of x in the tree." << '\n';


	AVL<KEY, VALUE>Tree;
	while(Q--)
	{
		int query;
		KEY key;
		VALUE v;
		cin >> query;
		if(query == 1)
		{
			cin >> key >> v;
			Tree.put(key, v);
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
		else if(query == 6)
		{
			Tree.print_pre_order();
		}
		else if(query == 7)
		{
			Tree.print_in_order();
		}
		else if(query == 8)
		{
			Tree.print_post_order();
		}
		else if(query == 9)
		{
			cin >> key;
			cout << "Value: "  << Tree.get(key) << endl;
		}
		else if(query == 10)
		{
			cin >> key;
			cout << "Successor: "  << Tree.successor(key) << endl;
		}
		else if(query == 11)
		{
			cin >> key;
			cout << "Predecessor: " << Tree.predecessor(key) << endl;
		}
		else
		{
			cout << "Invalid Query\n";
		}
	}
	return 0;
}