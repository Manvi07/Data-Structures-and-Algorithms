#include <iostream>
#include "BinaryTree.cpp"
#include "BSTree.cpp"
#include "AVL.cpp"

using namespace std;

template<class Key, class Value>
void AVL<Key, Value> :: InsertNode(const Key& key, const Value& value, BinaryNode<Key, Value>* &temp, int &ans)
{
	if(temp == nullptr)
    {
      temp = new BinaryNode<Key, Value>(key, value);
      return;
    }
    if(temp->key > key)
    {
    	if(temp->left == nullptr)
    	{
    		temp->left = new BinaryNode<Key, Value>(key,value);
    		temp->left->parent = temp; 
    		
    		if(temp->right!=nullptr)
    		temp->left->maxIndex = max(temp->right->maxIndex, temp->maxIndex); 
   		 	else
   		 		temp->left->maxIndex = max(temp->val, temp->maxIndex);

    		if(temp->maxIndex == -1)
	    		{
	    			ans = max(temp->val, ans);
	    		}
    		else
    			{
    				ans = max(temp->left->maxIndex, ans);
    			}
    	}
    	else
    	{
    	   if(temp->right==nullptr)
    		  ans = max(temp->maxIndex, temp->val);
    	   else
    		  ans = max(max(max(temp->right->val, temp->right->maxIndex),temp->val), temp->maxIndex);
    		InsertNode(key, value, temp->left, ans);
    	}
    	    	
    }
    else if(temp->key <= key)
    {
    	if(temp->right == nullptr)
    	{
    		temp->right = new BinaryNode<Key, Value>(key, value);
    		temp->right->parent = temp;
    		temp->maxIndex = temp->right->val;
    	}
    	else
    	{
    		InsertNode(key, value, temp->right, ans);
    	}
    }
    updateHeight(temp);
    doBalance(temp);
    return;
}

template<class Key, class Value>
int AVL<Key, Value> :: InsertNode(const Key& key, const Value& value)
{
	int ans = -1;
	InsertNode(key, value, this->root, ans);
	if(ans!=-1)
	return abs(ans - value);
	else
		return ans;
}


int main()
{
	AVL<int, int>t1;
	AVL<int, int>t2;
	int n;
	cin >> n;
	LinearList<int>l(n);
	LinearList<int>Ans(n);
	LinearList<int>A(n);
	for(int i=0; i<n; i++)
	{
		cin >> l[i];
		Ans[i] = t1.InsertNode(l[i], i+1);
	}

	for(int i=n-1; i>=0; i--)
	{
		A[i] = t2.InsertNode(l[i], n-i);
	}
	for(int i=0;i<n; i++)
	{
		if(Ans[i]==-1 or A[i]==-1)
		cout << max(Ans[i], A[i]) << " ";
		else
			cout << min(Ans[i], A[i]) << " ";
	}

	cout << endl;
}