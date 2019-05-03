/*CS-202 DATA STRUCTURES AND ALGORITHMS 
 *Assignment-2
 *Topic : Trees
 *Author : MANVI GUPTA (B17092)
 */


#include <iostream>
#include "BinaryTree.hpp"
using namespace std;

template<class Key,class Value>
Value BinaryTree<Key, Value> :: get(const Key& key, BinaryNode<Key, Value> * temp)
{
  if(temp->key==key)
    {
      return temp->val;
    }
  else if(temp!=nullptr)
  {
    Value t;
    if(temp->left!=nullptr)
      {
        t = get(key, temp->left);
      }
    if(t==Value() and temp->right!=nullptr)
      {
        t = get(key, temp->right);
      }
      return t;
  }
  return Value();
};

template<class Key,class Value>
Value BinaryTree<Key, Value> :: get(const Key& key)
{

  if(root!=nullptr)
  return get(key, root);
  else return Value();
}
/* Implement remove function that can delete a node in binary tree with given key. 
 */

template<class Key,class Value>
bool BinaryTree<Key, Value> :: Remove(BinaryNode<Key, Value> * &temp, Key key)
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
    if(temp->right!=nullptr)
      {
        f = Remove(temp->right, key);
      }
    if(temp->left!=nullptr and f == false)
      f = Remove(temp->left, key);
    return f;
  }
  
}

template<class Key,class Value>
void BinaryTree<Key, Value> :: remove(const Key& key)
{
  if(get(key, root)!=Value())
    Remove(root, key);
  else
    return;
};
//  Implement has function which will return true if the given key is present in binary tree 
//  * otherwise return false.  
 
template<class Key,class Value>
bool BinaryTree<Key, Value> :: has(const Key& key)
{
  if(get(key, root)!=Value())
    return true;
  else
    return false;
};	
/* Implement put function such that newly inserted node keep the tree balanced. 
 */	

template<class Key,class Value>
void BinaryTree<Key, Value> :: insert(const Key& key, const Value& value, BinaryNode<Key, Value>* &temp)
{
  if(temp==nullptr)
  {
    temp = new BinaryNode<Key, Value>(key, value);
    return;
  }
  
  if(rand()%2==1)
  {
    if(temp->left==nullptr)
      insert(key, value, temp->left);
    else
      insert(key, value, temp->right);
  }
  else 
  {
   if(temp->right==nullptr)
      insert(key, value, temp->right);
   else
      insert(key, value, temp->left); 
  }
}

template<class Key,class Value>
void BinaryTree<Key, Value> :: put(const Key& key, const Value& value)
{
  insert(key, value, root);
};
/*
 *This method print all the key value pairs of the binary tree, as
 *observed in an in order traversal.
 */

template<class Key,class Value>
void BinaryTree<Key, Value> :: inorder(BinaryNode<Key ,Value>* temp)
{
  if(temp==NULL)
  {
      return;
  }

  inorder(temp->left);
  std :: cout << "Key: " << temp->key <<  '\n';
  inorder(temp->right); 
}

template<class Key,class Value>
void BinaryTree<Key, Value> :: print_in_order()
{
  inorder(root);
};
/*
 *This method print all the key value pairs of the binary tree, as
 *observed in an pre order traversal.
 */

template<class Key,class Value>
void BinaryTree<Key, Value> :: preorder(BinaryNode<Key ,Value>* temp)
{
  if(temp==NULL)
  {
    return;
  }
  std :: cout << "Key: " << temp->key <<  '\n';
  preorder(temp->left);
  preorder(temp->right); 
}

template<class Key,class Value>
void BinaryTree<Key, Value> :: print_pre_order()
{
  preorder(root);
};
/*
 *This method print all the key value pairs of the binary tree, as
 *observed in a post order traversal.
 */

template<class Key,class Value>
void BinaryTree<Key, Value> :: postorder(BinaryNode<Key ,Value>* temp)
{
 if(temp==NULL)
  {
    return;
  }
  postorder(temp->left);
  postorder(temp->right);
  std :: cout << "Key: " << temp->key <<  '\n';  
}

template<class Key,class Value>
void BinaryTree<Key, Value> :: print_post_order()
{
  postorder(root);
};
/*
 *This method returns the minimum element in the binary tree.
 */

template<class Key,class Value>
Key BinaryTree<Key, Value> :: minimum(Key v,BinaryNode<Key, Value>* &temp)
{
  if(temp->left!=nullptr && temp->left->key <= v)
  {
    v = temp->left->key;
  }
  if(temp->right!=nullptr and temp->right->key <= v)
  {
    v = temp->right->key;
  }
  if(temp->right!=nullptr)
    v = minimum(v, temp->right);
  if(temp->left!=nullptr)
    v = minimum(v, temp->left);
  return v;
};

template<class Key,class Value>
Key BinaryTree<Key, Value> :: minimum()
{
  if(root!=nullptr)
  { 
    Key v = root->key;
    return minimum(v, root);
  }
  else return Key();
}
/*
 * This method returns the maximum element in the binary tree.
 */

template<class Key,class Value>
Key BinaryTree<Key, Value> :: maximum(Key v, BinaryNode<Key, Value>* &temp)
{
  if(temp->left!=nullptr and temp->left->key >= v)
  {
    v = temp->left->key;
  }
  if(temp->right!=nullptr and temp->right->key >= v)
  {
    v = temp->right->key;
  }
  if(temp->right!=nullptr)
    v = maximum(v, temp->right);
  if(temp->left!=nullptr)
    v = maximum(v, temp->left);
  return v;
};

template<class Key,class Value>
Key BinaryTree<Key, Value> :: maximum()
{
  if(root!=nullptr)
  { 
    Key v = root->key;
    return maximum(v, root);
  }
  else return Key();
}
//  *This method returns the successor, i.e, the next larget element in the
//  *binary tree, after Key.
 

template<class Key,class Value>
Key BinaryTree<Key, Value> :: successor(Key key, BinaryNode<Key, Value>* &temp, Key &tempKey)
{
  if((temp->key > key and temp->key <= tempKey) or (temp->key > key and tempKey==Key()))
  {
    tempKey = temp->key;
  }
  if(temp->right!=nullptr)
    tempKey = successor(key, temp->right, tempKey);
  if(temp->left!=nullptr)
    tempKey = successor(key, temp->left, tempKey);
  return tempKey;
}

template<class Key,class Value>
Key BinaryTree<Key, Value> :: successor(const Key& key)
{
  if(root!=nullptr)
  {
    Key rootKey = Key();
    return successor(key, root, rootKey);
  }
  else
    return Key();
};
// /*
//  * This method returns the predessor, ie, the next smallest element in the
//  * binary tree, after Key.
//  */

template<class Key,class Value>
Key BinaryTree<Key, Value> :: predecessor(Key key, BinaryNode<Key, Value>* &temp, Key &tempKey)
{
  if((temp->key < key and temp->key >= tempKey) or (temp->key < key and tempKey==Key()))
  {
    tempKey = temp->key;
  }
  if(temp->right!=nullptr)
    tempKey = predecessor(key, temp->right, tempKey);
  if(temp->left!=nullptr)
    tempKey = predecessor(key, temp->left, tempKey);
  return tempKey;
}

template<class Key,class Value>
Key BinaryTree<Key, Value> :: predecessor(const Key& key)
{
  if(root!=nullptr)
  {
    Key rootKey = Key();
    return predecessor(key, root, rootKey);
  }
  else
    return Key();
};
