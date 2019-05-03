#ifndef BSTREE_HPP
#define BSTREE_HPP 1
#include "BinaryTree.hpp"
template <class Key,class Value>
class BSTree : public BinaryTree<Key, Value> {

/* Inherit as many functions as possible from BinaryTree.
 * Only override those where you can decrease the time complexity and where you absolutely need to do it.
 * Also make sure that all inherited functions work correctly in the context of a binary search tree.
 */
 public:
void insert(const Key& key, const Value& value, BinaryNode<Key, Value> * &temp);
using BinaryTree<Key, Value> :: get;

/*
   * This method returns the current height of the binary search tree.
   */
virtual int getHeight(BinaryNode<Key, Value> * temp);
virtual int getHeight();

/*
   * This method returns the total number of elements in the binary search tree.
   */
  virtual int size(BinaryNode<Key, Value> *temp, int &s);
  virtual int size();

    /*
   * This method prints the key value pairs of the binary search tree, sorted by
   * their keys.
   */
  virtual void print();

  Value get(const Key& key, BinaryNode<Key, Value> * temp);

  bool Remove(BinaryNode<Key, Value> * &temp, Key key);

  Key minimum(BinaryNode<Key, Value>* &temp);
  virtual Key maximum(BinaryNode<Key, Value>* &temp);
  virtual Key maximum();
  virtual Key minimum(); 

  virtual Key successor(Key key, BinaryNode<Key, Value>* &temp);
  virtual Key predecessor(Key key, BinaryNode<Key, Value>* &temp);
  virtual Key successor(const Key& key);
  virtual Key predecessor(const Key& key);
  
};

#endif /* ifndef BSTREE_HPP */