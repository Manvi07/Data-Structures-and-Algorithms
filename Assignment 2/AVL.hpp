#ifndef AVL_HPP
#define AVL_HPP 1
#include "BSTree.hpp"

template<class Key, class Value>
class AVL : public BSTree<Key, Value> {
  /*
   * Inherit as much functionality as possible from the BSTree class.
   * Then provide custom AVL Tree functionality on top of that.
   * The AVL Tree should make use of as many BST functions as possible.
   * Override only those methods which are extremely necessary.
   */
  /*
   * Apart from that, your code should have the following four functions:
   * getBalance(node) -> To get the balance at any given node;
   * doBalance(node) -> To fix the balance at the given node;
   * rightRotate(node) -> Perform a right rotation about the given node.
   * leftRotate(node) -> Perform a left rotation about the given node.
   *
   * The signature of these functions are not provided in order to provide you
   * some flexibility in how you implement the internals of your AVL Tree. But
   * make sure these functions are there.
   */
public:
  using BSTree<Key, Value>::size;
  int getHeight(BinaryNode<Key, Value> *temp);
  int getBalance(BinaryNode<Key,Value> *temp);
  virtual void updateHeight(BinaryNode<Key,Value> *temp);
  virtual void rightRotate(BinaryNode<Key,Value> *temp);
  virtual void leftRotate(BinaryNode<Key,Value> *temp);
  virtual void doBalance(BinaryNode<Key, Value> * &temp);
  virtual void insert(const Key& key, const Value& value, BinaryNode<Key, Value> * &temp);
  bool Remove(BinaryNode<Key, Value> * &temp, Key key);
  void Insert(const Key& key, const Value& value, BinaryNode<Key, Value>* &temp, int &size);
  int Put(Key key, Value v);
  int size(BinaryNode<Key, Value> * temp);
  void updateSize(BinaryNode<Key, Value>* node);
  void InsertNode(const Key& key, const Value& value, BinaryNode<Key, Value> * &temp, int &ans);
  int InsertNode(const Key& key, const Value& value);
};

#endif /* ifndef AVL_HPP */