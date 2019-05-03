#include <iostream>
#include "BinaryTree.cpp"
#include "BSTree.cpp"
#include "AVL.cpp"

using namespace std;

template<class Key, class Value>
void AVL<Key, Value> :: Insert(const Key& key, const Value& value, BinaryNode<Key, Value>* &temp, int &s)
{
	if(temp == nullptr)
    {
      temp = new BinaryNode<Key, Value>(key, value);
      return;
    }
    if(temp->key >= key)
    {
    	if(temp->left == nullptr)
    	{
    		temp->left = new BinaryNode<Key, Value>(key,value);
    		temp->left->parent = temp;
    		temp->size++;
    	}
    	else
    	{
    		Insert(key, value, temp->left, s);
    	}
    }
    else if(temp->key < key)
    {
    	if(temp->right == nullptr)
    	{
    		temp->right = new BinaryNode<Key, Value>(key, value);
    		temp->right->parent = temp;
    		temp->size++;
    	}
    	else
    	{
    		Insert(key, value, temp->right, s);
    	}
    	s += 1 + size(temp->left);
    }
    updateHeight(temp);
    doBalance(temp);
    return;
}

template<class Key, class Value>
int AVL<Key,Value> :: Put(Key key, Value v)
{
	int s = 0;
	Insert(key, v, this->root, s);
	return s;
}


template<class Key, class Value>
int AVL< Key, Value> :: size(BinaryNode<Key,Value>* node)
{
	if(node == nullptr)
		return 0;
	else
		return node->size;
}

int main()
{
	int n;
	cin >> n;
	
	AVL<int, int>b;
	LinearList<int>a(n);

	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	LinearList<int>ans(n);
	for(int i=n-1; i>=0; i--)
	{
    	ans[i] = b.Put(a[i], 1);
	}
	for(int i=0;i<n;i++)
	{
		cout << ans[i] << " ";
	}
	
	cout << endl;
	return 0;
}