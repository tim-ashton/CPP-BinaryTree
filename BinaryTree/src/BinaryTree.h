/*
 * BinaryTree.h
 *
 *  Created on: Nov 18, 2014
 *      Author: tashton
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

class BinaryTree {

	class Node{
	public:
		int data;
		Node *left, *right;

	public:
		Node(int value);
		~Node();

		int getData();
	};

	Node *root;

public:
	BinaryTree();
	~BinaryTree();

	void insert(int value);

private:
	Node* insert(Node *newNode, Node *root);

};

#endif /* BINARYTREE_H_ */
