/*CS-202 DATA STRUCTURES AND ALGORITHMS 
 *Assignment-2
 *Topic : Trees
 *Author : MANVI GUPTA (B17092)
 */


#include <iostream>
#include "RBTree.hpp"
using namespace std;
	
bool extra = false;

template<class Key, class Value>
void RBTree<Key, Value> :: insert(const Key& key, const Value& value, node_ptr &temp)
{
	if(temp == nullptr)
    {
      temp = new RBTNode<Key, Value>(key, value);
      insertRBFixup(temp);
      return;
    }
    if(temp->key > key)
    {
    	if(temp->left == nullptr)
    	{
    		temp->left = new RBTNode<Key, Value>(key,value);
    		temp->left->parent = temp;
    		insertRBFixup(temp->left);
    	}
    	else
    		insert(key, value, temp->left);
    }
    else
    {
    	if(temp->right == nullptr)
    	{
    		temp->right = new RBTNode<Key, Value>(key, value);
    		temp->right->parent = temp;
    		insertRBFixup(temp->right);
    	}
    	else
    		insert(key, value, temp->right);
    }
    updateHeight(temp);
    return;
}

template<class Key, class Value>
void RBTree<Key, Value> :: insertRBFixup(node_ptr temp)
{
	if(temp == this->root)
	{
		setColor(temp, BLACK);
		return;
	}
	node_ptr u;		//pointer to uncle node
	while(temp->parent != nullptr and (getColor(temp->parent) == RED))
	{
		node_ptr t = temp->parent->parent;

		/*  Parent is left child of Grand-parent of temp */
		if(t->left == temp->parent)
		{
			if(t->right!=nullptr)
			{
				u = t->right;

				/* Case : 1 
               The uncle of temp is also red. Only Recoloring required */
				if(getColor(u) == RED)
				{
					setColor(temp->parent, BLACK);
					setColor(u, BLACK);
					setColor(t, RED);
					temp = t;
				}
			}
			else
				{
					/* Case : 2 
                   temp is right child of its parent. Left-rotation required */
					if(temp->parent->right == temp)
					{
						temp = temp->parent;
						this->leftRotate((BinaryNode<Key, Value>*) (temp));
					}
					/* Case : 3 
                   temp is left child of its parent. Right-rotation required */
					setColor(temp->parent, BLACK);
					setColor(t, RED);
					this->rightRotate((BinaryNode<Key, Value>*) (t));
				}
		}
		 /* Parent right child of Grand-parent of temp */
		else
		{
			if(t->left!=nullptr)
			{
				u = t->left;
				/*  Case : 1 
                The uncle of temp is also red. Only Recoloring required */
				if(getColor(u) == RED)
				{
					((RBTNode<Key, Value>*)temp->parent)->color = BLACK;
					((RBTNode<Key, Value>*)u)->color = BLACK;
					((RBTNode<Key, Value>*)t)->color = RED;
					temp = t;
				}
			}
			else
			{
				 /* Case : 2 
                   temp is left child of its parent. Right-rotation required */
				if(temp->parent->left==temp)
				{
					temp = temp->parent;
					this->rightRotate(temp);
				}
				 // Case : 3 
                 //  temp is right child of its parent. Left-rotation required 
				setColor(temp->parent, BLACK);
				setColor(t, RED);
				this->leftRotate(t);
			}
		}
	}
		setColor(this->root, BLACK);
}

template<class Key, class Value>
void RBTree<Key, Value> :: rightRotate(node_ptr temp)
{
	node_ptr leftChild = temp->left;
	node_ptr grandChild = leftChild->right;
	node_ptr Parent = temp->parent;

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
	this->updateHeight(temp);
	this->updateHeight(leftChild);
}

template<class Key, class Value>
void RBTree<Key, Value> :: leftRotate(node_ptr temp)
{
	node_ptr rightChild = temp->right;
	node_ptr grandChild = rightChild->left;
	node_ptr Parent = temp->parent;

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
}

template<class Key, class Value>
void RBTree<Key,Value> :: rbTransplant( node_ptr node, node_ptr child)
{
	child->parent = node->parent;
	if(node->parent == nullptr)
	{
		this->root = child;
	}
	else
	{
		if(node->parent->left == node)
			node->parent->left = child;
		else
			node->parent->right =child;
	}
}

template<class Key,class Value>
void RBTree<Key, Value> :: remove_node(node_ptr temp_root, Key key)
{
	if(temp_root == nullptr or temp_root->key == Key())
	{
		return;
	}
	if(temp_root->key == key)
	{
		if(temp_root->left == nullptr || temp_root->right == nullptr)
		{
			deleteChild(temp_root);
		}
		else
		{
			temp_root->key = this->successor(key);
			temp_root->val = minimumNode(temp_root->right)->val;
			remove_node(temp_root->right, this->successor(key));
		}
	}
	else if(temp_root->key < key)
		{
			remove_node(temp_root->right, key);
		}
	else
	{
		remove_node(temp_root->left, key);
	}
	updateHeight(temp_root);
}

template<class Key, class Value>
void RBTree<Key, Value> :: deleteChild(node_ptr &nodeToBeDeleted)
{
	node_ptr child = nodeToBeDeleted->right==nullptr?nodeToBeDeleted->left : nodeToBeDeleted->right;
	

	if(child == nullptr)
	{
		child = new RBTNode<Key, Value>(Key(), Value());
		child->parent = nodeToBeDeleted;
		setColor(child, BLACK);
		extra = true;
	}
	
	rbTransplant(nodeToBeDeleted, child);

	if(getColor(nodeToBeDeleted) == BLACK)
	{
		if(getColor(child) == RED)
		{
			setColor(child, BLACK);
		}
		else
		{
			deleteRBFixup(child);
		}
	}

	if(extra)
		{
			node_ptr t = child;

			if(child!=this->root and child->parent->left == child)
				child->parent->left = nullptr;
			else if(child!=this->root)
				child->parent->right = nullptr;
			else
				this->root=nullptr;
			delete t;
		}
		extra = false;

	delete nodeToBeDeleted;
}

template<class Key, class Value>
BinaryNode<Key, Value>* RBTree<Key, Value> :: findSibling(node_ptr node)
{
	if(node->parent->left == node)
	{
		if(node->parent->right != nullptr)
			return node->parent->right;
		else
		{
			node_ptr child = new RBTNode<Key, Value>(Key(), Value());
			child->parent = node;
			setColor(child, BLACK);
			extra = true;
			return child;
		}
	}
	else
	{
		if(node->parent->left != nullptr)
		return node->parent->left;
		else
		{
			node_ptr child = new RBTNode<Key, Value>(Key(), Value());
			child->parent = node;
			setColor(child, BLACK);
			extra = true;
			return child;
		}
	}
}

template< class Key, class Value>
void RBTree<Key, Value> :: deleteRBFixup(node_ptr temp)
{
	if(temp->parent == nullptr)
	{
		this->root = temp;
		return;
	}
	node_ptr sibling = findSibling(temp);
	
	if(getColor(sibling) == RED)
	{		
		if(sibling == temp->parent->left)
			rightRotate(sibling->parent);
		else
			leftRotate(temp->parent);
		setColor(temp->parent, RED);
		setColor(sibling, BLACK);		
	}
	sibling = findSibling(temp);

	if(getColor(temp->parent) == BLACK and getColor(sibling) == BLACK and getColor(sibling->left) == BLACK and getColor(sibling->right) == BLACK)
	{
		if(sibling!=nullptr)
		setColor(sibling, RED);
		deleteRBFixup(temp->parent);
	}
	else
	{
		sibling = findSibling(temp);
		
		if(getColor(temp->parent) == RED and getColor(sibling) == BLACK  and getColor(sibling->left) == BLACK and getColor(sibling->right) == BLACK)
		{
			setColor(sibling, RED);
			setColor(temp->parent, BLACK);
			return;
		}
		else
		{

			if(getColor(sibling) == BLACK)
			{
				if(temp->parent->left == temp and getColor(sibling->right) == BLACK and getColor(sibling->left) == RED)
				{
					rightRotate(sibling);
				}
				else if(temp->parent->left != temp and getColor(sibling->left) == BLACK and getColor(sibling->right) == RED)
				{
					leftRotate(sibling);
				}
			}
			sibling = findSibling(temp);
			setColor(sibling, getColor(sibling->parent));
			setColor(sibling->parent, BLACK);
			if(temp == temp->parent->left)
			{
				setColor(sibling->right, BLACK);
				leftRotate(sibling->parent);
			}
			else
			{
				setColor(sibling->left, BLACK);
				rightRotate(sibling->parent);
			}
		}
	}
}

template<class Key, class Value>
BinaryNode<Key, Value>*  RBTree<Key, Value> :: minimumNode(node_ptr temp)
{
	while(temp->left != nullptr)
	{
		temp = temp->left;
	}
	return temp;
}


template<class Key, class Value>
int RBTree<Key,Value> :: blackHeight(node_ptr root)
{
	int black_height = 0;
	node_ptr temp = root;
	while(temp!=nullptr)
	{
		if(getColor(temp) == BLACK)
		{
			black_height++;
		}
		temp = temp->left;
	}
	return black_height;
}

template<class Key, class Value>
void RBTree<Key,Value> :: setColor(node_ptr &node, Color c)
{
	((RBTNode<Key, Value>* )node)->color = c;
	return;
}

template< class Key, class Value>
Color RBTree<Key, Value> :: getColor(node_ptr node)
{
	if(node == nullptr)
		return BLACK;
	else
		return ((RBTNode<Key, Value>*)node)->color;
}

template<class Key, class Value>
int RBTree<Key, Value> :: getHeight(node_ptr temp)
{
	if(temp==nullptr)
	{
		return -1;
	}
	else return temp->height;
}

template<class Key, class Value>
void RBTree<Key, Value> :: updateHeight(node_ptr temp)
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
void RBTree<Key, Value> :: remove(Key key)
{
	node_ptr temp = new RBTNode<Key,Value>(Key(), Value());
 	remove_node(this->root, key);
}