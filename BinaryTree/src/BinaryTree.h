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
		int *data;
		Node *left, *right;

		Node(int value);
		~Node();

		void assignNewData(int value);
	};

	Node *root;

public:
	BinaryTree();
	~BinaryTree();

	void insert(int value);
	void deleteNode(int value);
	void destroyTree();

private:
	void insert(int value, Node *&node);
	Node* deleteNode(int value, Node *node);
	void destroyTree(Node *node);

};

#endif /* BINARYTREE_H_ */
