/*CS-202 DATA STRUCTURES AND ALGORITHMS 
 *Assignment-2
 *Topic : Trees
 *Author : MANVI GUPTA (B17092)
 */

#include <iostream>
#include "BSTree.hpp"
#include "BinaryTree.hpp"
#include "AVL.hpp"
using namespace std;

template<class Key, class Value>
int AVL<Key, Value> :: getBalance(BinaryNode<Key, Value>* temp)
{
	if(temp!=nullptr)
		return getHeight(temp->left) - getHeight(temp->right);
	else
		return 0;
}

template<class Key, class Value>
int AVL<Key, Value> :: getHeight(BinaryNode<Key, Value> *temp)
{
	if(temp==nullptr)
	{
		return -1;
	}
	else return temp->height;
}

template<class Key, class Value>
void AVL<Key, Value> :: updateHeight(BinaryNode<Key,Value> *temp)
{
	if(temp==nullptr)
	{
		return;
	}
	if(temp->right == nullptr and temp->left == nullptr)
		temp->height = 0;
	else if(temp->left==nullptr)
		temp->height = 1 + getHeight(temp->right);
	else if(temp->right == nullptr)
		temp->height = 1 + getHeight(temp->left);
	else
		temp -> height = 1 + max(getHeight(temp->left), getHeight(temp->right));
}

template<class Key, class Value>
void AVL<Key, Value> :: rightRotate(BinaryNode<Key, Value> *temp)
{
	BinaryNode<Key, Value>* leftChild = temp->left;
	BinaryNode<Key ,Value>* grandChild = leftChild->right;
	BinaryNode<Key, Value>* Parent = temp->parent;

	leftChild->right = temp;
	temp->left = grandChild;
	
	leftChild -> parent = temp->parent;
	temp->parent  = leftChild;
	if(grandChild!=nullptr)
	{
		grandChild -> parent = temp;
	}

	if(Parent==nullptr)
	{
		this->root = leftChild;
	}
	else if(Parent->right==temp)
	{
		Parent->right = leftChild;
	}
	else
	{
		Parent->left = leftChild;
	}
	updateHeight(temp);
	updateHeight(leftChild);
	updateSize(temp);
	updateSize(leftChild);
}

template<class Key, class Value>
void AVL<Key, Value> :: updateSize(BinaryNode<Key, Value>* node)
{
	if(node == nullptr)
		{
			return;
		}
	if(node->left == nullptr and node->right == nullptr)
		node->size = 1;
	else if(node->left == nullptr)
		node->size = node->right->size +1;
	else if(node->right == nullptr)
		node->size = node->left->size + 1;
	else
		node->size = node->left->size + node->right->size +1;
	return;
}


template<class Key, class Value>
void AVL<Key, Value> :: leftRotate(BinaryNode<Key,Value> *temp)
{
	BinaryNode<Key, Value>* rightChild = temp->right;
	BinaryNode<Key ,Value>* grandChild = rightChild->left;
	BinaryNode<Key, Value>* Parent = temp->parent;

	rightChild->left = temp;
	temp->right = grandChild;

	rightChild -> parent = temp->parent;
	temp->parent  = rightChild;

	if(grandChild!=nullptr)
	{
		grandChild->parent = temp;
	}

	if(Parent==nullptr)
	{
		this->root = rightChild;
	}
	else if(Parent->right==temp)
	{
		Parent->right = rightChild;
	}
	else
	{
		Parent->left = rightChild;
	}
	updateHeight(temp);
	updateHeight(rightChild);

	updateSize(temp);

	updateSize(rightChild);
}

template<class Key, class Value>
void AVL<Key, Value> :: insert(const Key& key, const Value& value, BinaryNode<Key, Value> * &temp)
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
    	}
    	else
    		insert(key, value, temp->left);
    }
    else
    {
    	if(temp->right == nullptr)
    	{
    		temp->right = new BinaryNode<Key, Value>(key, value);
    		temp->right->parent = temp;
    	}
    	else
    		insert(key, value, temp->right);
    }
    updateHeight(temp);
    updateSize(temp);
    doBalance(temp);
    return;
}

template<class Key, class Value>
void AVL<Key, Value> :: doBalance(BinaryNode<Key, Value> * &temp)
{
	int balance = getBalance(temp);
	if(balance > 1 and getBalance(temp->left) >= 0)
	{
		rightRotate(temp);
	}
	if(balance < -1 and getBalance(temp->right) <= 0)
	{
		leftRotate(temp);
	}
	if(balance > 1 and getBalance(temp->left) < 0)
	{
		leftRotate(temp->left);
		rightRotate(temp);
	}
	if(balance < -1 and getBalance(temp->right) > 0)
	{
		rightRotate(temp->right);
		leftRotate(temp);
	}
}

template<class Key,class Value>
bool AVL<Key, Value> :: Remove(BinaryNode<Key, Value> * &temp, Key key)
{
  if(temp==nullptr)
  {
    return false;
  }
  if(temp->key==key)
  {     
    if(temp->right==nullptr and temp->left==nullptr)
    {
      BinaryNode<Key, Value> *t = temp;
      temp = nullptr;
      delete t;
      return true;
    }
    else if(temp->right==nullptr)
    {
      BinaryNode<Key, Value> * t = temp;
      temp  = temp->left;
      delete t; 
      return true;
    }
    else if(temp->left==nullptr)
    {
      BinaryNode<Key, Value> * t = temp;
      temp = temp->right;
      delete t; 
      return true;
    }
    else
    {
      BinaryNode<Key, Value> * t = temp;
      t = t->right;
      while(t->left!=nullptr)
      {
        t = t->left;
      }
      swap(t->key, temp->key);
      swap(t->val, temp->val);
      return Remove(temp->right, key);
    }
  }
  else
  {
    bool f = false;
    if(temp->key < key)
      {
        f = Remove(temp->right, key);
      }
    else if(temp->key > key)
      f = Remove(temp->left, key);
    return f;
  }
  
  updateHeight(temp);
  updateSize(temp);
  doBalance(temp);
}