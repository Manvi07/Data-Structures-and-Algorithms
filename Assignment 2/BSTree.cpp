/*CS-202 DATA STRUCTURES AND ALGORITHMS 
 *Assignment-2
 *Topic : Trees
 *Author : MANVI GUPTA (B17092)
 */

#include <iostream>
#include "BSTree.hpp"
#include "BinaryTree.hpp"

using namespace std;

template<class Key, class Value>
void BSTree< Key, Value> :: insert(const Key& key, const Value& value, BinaryNode<Key, Value> * &temp)
  {
    if(temp==nullptr)
    {
      temp = new BinaryNode<Key, Value>(key, value);
      return;
    }
    if(temp->key>key)
    {
      insert(key, value, temp->left);
    }
    else 
    {
      insert(key, value, temp->right);
    }
  }
  
  /*
   * This method returns the current height of the binary search tree.
   */
template<class Key, class Value>
int BSTree< Key, Value> :: getHeight(BinaryNode<Key, Value> * temp)
  {
    if(temp==nullptr)
    {
      return 0;
    }
    return(max(getHeight(temp->left), getHeight(temp->right)))+1;
  }

template<class Key, class Value>
int BSTree< Key, Value> :: getHeight()
  {
    return getHeight(this->root)-1;
  }

  /*
   * This method returns the total number of elements in the binary search tree.
   */
  
 template<class Key, class Value> 
int BSTree<Key, Value> :: size(BinaryNode<Key, Value> *temp, int &s)
  {
    if(temp!=nullptr)
    {
      size(temp->left, s);
      s++;
      size(temp->right, s);
    }
    return s;
  }

template<class Key, class Value>
int BSTree< Key, Value> :: size()
  {
    int s = 0;
    return size(this->root, s);
  }
  
 /*
   * This method prints the key value pairs of the binary search tree, sorted by
   * their keys.
   */
template<class Key, class Value>
void BSTree< Key, Value> :: print()
  {
    this->inorder(this->root);
  };

template<class Key, class Value>
Value BSTree<Key, Value> :: get(const Key& key, BinaryNode<Key, Value> * temp)
{
  if(temp->key == key)
  {
    return temp->val;
  }
  else if(temp->key < key)
  {
    if(temp->right==nullptr)
      return Value();
    else return get(key, temp->right);
  }
  else
  {
    if(temp->left==nullptr)
      return Value();
    else return get(key, temp->left);
  }
}

template<class Key,class Value>
bool BSTree<Key, Value> :: Remove(BinaryNode<Key, Value> * &temp, Key key)
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
  
}

template<class Key, class Value>
Key BSTree<Key, Value> :: minimum(BinaryNode<Key, Value>* &temp)
{
  if(temp==nullptr)
  {
    return Key();
  }
  if(temp -> left ==nullptr)
  {
    return temp->key;
  }
  else return minimum(temp->left);
}

template<class Key, class Value>
Key BSTree<Key, Value> :: maximum(BinaryNode<Key, Value>* &temp)
{
  if(temp==nullptr)
  {
    return Key();
  }
  if(temp -> right ==nullptr)
  {
    return temp->key;
  }
  else return maximum( temp->right);
}

template<class Key, class Value>
Key BSTree<Key, Value> :: successor(Key key, BinaryNode<Key, Value>* &temp)
{
  Key s = Key();
  BinaryNode<Key, Value> *t = temp;
  while(t!=nullptr)
  {
    if(t->key > key and s > key)
    {
      s = t->key;
      t = t->left;
    }
    else if(t->key > key and s==Key())
     {
      s = t->key;
      t = t->left;
     }
    else if(t->key <= key)
      t = t->right;
  }
  return s;
}

template<class Key, class Value>
Key BSTree<Key, Value> :: predecessor(Key key, BinaryNode<Key, Value>* &temp)
{
  Key s = Key();
  BinaryNode<Key, Value> *t = temp;
  while(t!=nullptr)
  {
    if(t->key < key and s < key)
    {
      s = t->key;
      t = t->right;
    }
    else if(t->key < key and s ==  Key())
     {
      s = t->key;
      t = t->right;
     }
    else if(t->key >= key)
      t = t->left;
  }
  return s;
}

template<class Key, class Value>
Key BSTree<Key, Value> :: predecessor(const Key& key)
{
  return predecessor(key ,this->root);
}

template<class Key, class Value>
Key BSTree<Key, Value> :: successor(const Key& key)
{
  return successor(key ,this->root);
}


template<class Key, class Value>
Key BSTree<Key, Value> :: maximum()
{
  return maximum(this->root);
}

template<class Key, class Value>
Key BSTree<Key, Value> :: minimum()
{
  return minimum(this->root);
}