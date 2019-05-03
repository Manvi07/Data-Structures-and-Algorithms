#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP 1
#include "seqLinearList.hpp"


template <class Key,class Value>
class BinaryNode
{
public:
	Key key;
	Value val;
  int height, size, maxIndex;
	BinaryNode<Key,Value> * root,* left,* right,* parent;
    /*Default constructor. Should assign the default value to key and value
     */
	BinaryNode()
  {
    root = nullptr;  
    left = nullptr;
    right = nullptr;    
    height = 0;
    parent = nullptr;
    size = 1;
    maxIndex = -1;
  };

	/*This contructor should assign the key and val from the passed parameters
     */
	BinaryNode(Key key, Value value)
  {
    root = nullptr;
    this->key = key;
    this->val = value;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    height = 0;
    size = 1;
    maxIndex = -1;
  };
};

template<class Key,class Value>
class BinaryTree
{
	/* You can implement your own helper functions whenever required.
	 */
protected:
	BinaryNode<Key,Value> * root;

public:
  /* Implement get function to retrieve the value corresponding to given key in binary tree.
   */
  BinaryTree()
  {
    root = nullptr;
    srand(time(0));
  };
  virtual Value get(const Key& key, BinaryNode<Key, Value> * temp);
  virtual Value get(const Key& key);
  
  /* Implement remove function that can delete a node in binary tree with given key. 
 */
  virtual bool Remove(BinaryNode<Key, Value> * &temp, Key key);
  virtual void remove(const Key& key);

  //  Implement has function which will return true if the given key is present in binary tree 
//  * otherwise return false.  
  virtual bool has(const Key& key);

  /* Implement put function such that newly inserted node keep the tree balanced. 
 */ 
  virtual void insert(const Key& key, const Value& value, BinaryNode<Key, Value>* &temp);
  virtual void put(const Key& key, const Value& value);

  /*
 *This method print all the key value pairs of the binary tree, as
 *observed in an in order traversal.
 */
  virtual void inorder(BinaryNode<Key ,Value>* temp);
  virtual void print_in_order();

  /*
 *This method print all the key value pairs of the binary tree, as
 *observed in an pre order traversal.
 */
  void preorder(BinaryNode<Key ,Value>* temp);
  virtual void print_pre_order();

  /*
 *This method print all the key value pairs of the binary tree, as
 *observed in a post order traversal.
 */
  void postorder(BinaryNode<Key ,Value>* temp);
  virtual void print_post_order();

  /*
 *This method returns the minimum element in the binary tree.
 */
  Key minimum(Key v,BinaryNode<Key, Value>* &temp);
  Key minimum();

  /*
 * This method returns the maximum element in the binary tree.
 */
  Key maximum(Key v,BinaryNode<Key, Value>* &temp);
  Key maximum();

  //  *This method returns the successor, i.e, the next larget element in the
//  *binary tree, after Key.
  Key successor(Key key, BinaryNode<Key, Value>* &temp, Key &tempKey);
  Key successor(const Key& key);
  // /*
//  * This method returns the predessor, ie, the next smallest element in the
//  * binary tree, after Key.
//  */
  Key predecessor(Key key, BinaryNode<Key, Value>* &temp, Key &tempKey);
  Key predecessor(const Key& key);
};


#endif /* ifndef BINARYTREE_HPP */