/*
 * BinaryTree.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: tashton
 */

#include "BinaryTree.h"

BinaryTree::BinaryTree() {
	root = 0;

}

BinaryTree::~BinaryTree() {
	// TODO Auto-generated destructor stub
}



void BinaryTree::insert(int value) {
	if(!root){
		root = new Node(value);
	}
	else {
		Node *newNode = new Node(value);
		insert(newNode, root);
	}
}

/*
 * Private
 */
BinaryTree::Node* BinaryTree::insert(Node *newNode, Node *root){
	if(!root){
		root = newNode;
	}
	else if(newNode->data < root->data){
		insert(newNode, root->left);
		if(!root->left)
			root->left = newNode;
	}
	else {
		insert(newNode, root->right);
		if(!root->right)
			root->right = newNode;
	}
	return root;
}


/*
 * Node implementation
 */

BinaryTree::Node::Node(int value){
	data = value;
	left = right = 0;
}


