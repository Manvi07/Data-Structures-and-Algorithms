#ifndef RBTree_HPP_
#define RBTree_HPP_ 1
#include "BSTree.hpp"
/* The color enumeration.
 * Please use this and not integers or characters to store the color of the node
 * in your red black tree.
 * Also create a class RBTNode which should inherit from BinaryNode and has the attribute color in it. 
 */

enum Color { RED, BLACK };

template <class Key, class Value>
class RBTNode : public BinaryNode<Key, Value> 
{
public:
	using BinaryNode<Key, Value> :: key;
	using BinaryNode<Key, Value> :: val;
	Color color;
	RBTNode() : BinaryNode<Key, Value>()
	{
		Color color = RED;
	};
	RBTNode(Key key, Value value) : BinaryNode<Key, Value>(key, value)
	{
		Color color = RED;
	}
};

template <class Key, class Value>
class RBTree : public BSTree<Key, Value> {
/* Inherit as many functions as possible from BSTree.
 * Only override those which absolutely need it.
 * Also make sure that all inherited functions work correctly in the context of a red black tree.
 * node_ptr in the following piece of code refers to a pointer to the node you may be using for your red black tree.
 * Use a typedef to refer to a pointer to your node via node_ptr
 */

	/* Function insertRBFixup
	 *
	 * Used for:
	 * Used after an insertion in the rb tree.
	 * It applies fixing mechanisms to make sure that the tree remains a valid red black tree after an insertion.
	 */
	typedef BinaryNode<Key, Value>* node_ptr;

	void insertRBFixup(node_ptr root);
/* Function deleteRBFixup
	 * Used for:
	 * Used after a deletion in the rb tree.
	 * It applies fixing mechanisms to make sure that the tree remains a valid red black tree after a deletion.
	 */
	void deleteRBFixup(node_ptr root);
	Color getColor(node_ptr node);
	void setColor(node_ptr &node, Color c);
	node_ptr findSibling(node_ptr node);
  	node_ptr minimumNode(node_ptr temp);

public:
	/* Function : blackHeight
	 * 
	 * Returns:
	 * the black height of the red black tree which begins at node_ptr root
	 */
	int blackHeight(node_ptr root);	
	/*
	 * Apart from these functions, also provide functions for rotations in the tree.
	 * The signature of the rotation functions is omitted to provide you flexibility in how you implement the internals of your node.
	 */

	  void leftRotate(node_ptr temp);
	  void rightRotate(node_ptr temp);

  	void insert(const Key& key, const Value& value, node_ptr &temp);
  	void remove_node(node_ptr temp, Key key);
  	void remove(Key key);
  	int getHeight(node_ptr temp);
  void updateHeight(node_ptr temp);
  void rbTransplant(node_ptr a, node_ptr b);
  void deleteChild(node_ptr &nodeToBeDeleted);
  
};
#endif /* ifndef RBTree_HPP_ */