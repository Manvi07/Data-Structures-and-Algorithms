
BTree : BinaryTree.hpp BinaryTree.cpp BTree_main.cpp
	g++ -o BTree BTree_main.cpp

BSTree : BinaryTree.hpp BinaryTree.cpp BSTree.hpp BSTree.cpp BSTree_main.cpp
	g++ -o BSTree BSTree_main.cpp

AVL : BinaryTree.hpp BinaryTree.cpp BSTree.hpp BSTree.cpp AVL.cpp AVL.hpp AVL_main.cpp
	g++ -o AVL AVL_main.cpp

RBTree : BinaryTree.hpp BinaryTree.cpp BSTree.hpp BSTree.cpp AVL.cpp AVL.hpp RBTree.cpp RBTree.hpp RBTree_main.cpp
	g++ -o RBTree RBTree_main.cpp

trees : RBTree_main.cpp BSTree_main.cpp AVL_main.cpp BTree_main.cpp trees.cpp
	g++ -o trees trees.cpp

prob1 : BinaryTree.hpp BinaryTree.cpp BSTree.hpp BSTree.cpp AVL.cpp AVL.hpp prob1.cpp seqLinearList.hpp
	g++ -o prob1 prob1.cpp

prob2 : BinaryTree.hpp BinaryTree.cpp BSTree.hpp BSTree.cpp AVL.cpp AVL.hpp prob2.cpp seqLinearList.hpp
	g++ -o prob2 prob2.cpp

clean :
	rm BTree BSTree AVL RBTree trees prob1 prob2
