/*
 * BinaryTree.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: tashton
 */

#include <iostream>
#include "BinaryTree.h"

/*
 * BinaryTree constructor
 *
 * Just set root to null
 */
BinaryTree::BinaryTree() {
	root = 0;

}

/*
 * BinaryTree destructor
 *
 * Call destroyTree() to remove all nodes and
 * clean up memory on heap.
 */
BinaryTree::~BinaryTree() {
	destroyTree(root);
}

/*
 * insert(int value) inserts a value into the tree.
 *
 * Calls recursive private member function for encapsulation.
 */
void BinaryTree::insert(int value) {
	insert(value, root);
}

/*
 * deleteNode(int value) deletes the node which contains value.
 *
 * Calls recursive private member function.
 */
void BinaryTree::deleteNode(int value){
	root = deleteNode(value, root);
}

/*
 * preOrder() prints all values in the tree pre-order
 * using recursive private member function.
 */
void BinaryTree::preOrder(){
	preOrder(root);
}

/*
 * inOrder() prints all values in the tree in-order
 * using recursive private member function.
 */
void BinaryTree::inOrder(){
	inOrder(root);
}

/*
 * postOrder() prints all values in the tree post-order
 * using recursive private member function.
 */
void BinaryTree::postOrder(){
	postOrder(root);
}

/*
 * destroyTree() destroys all nodes in the tree and
 * leaves root as null ptr.
 *
 * Calls recursive private member function.
 */
void BinaryTree::destroyTree(){
	destroyTree(root);
	root = 0;
}

/*
 * Private
 */


void BinaryTree::insert(int value, Node *&node){
	if(!node){
		node = new Node(value);
	}
	else{
		if(value < *node->data) {
			insert (value, node->left);
		}
		else{
			insert (value, node->right);
		}
	}
}

/*
 * deleteNode(int value, Node *root) recurses through the tree
 * to find the value being deleted, removes the node and re-arranges
 * the tree as required.
 *
 * If value is the root node, the leftmost node will replace the root
 * and the nodes in the left are adjusted as necessary.
 */
BinaryTree::Node* BinaryTree::deleteNode(int value, Node *root){
	if(root){
		if(value < *root->data){
			root->left = deleteNode(value, root->left);
		}
		else if(value > *root->data){
			root->right = deleteNode(value, root->right);
		}
		else {
			if(root->left == 0){
				Node* tmp = root->right;
				delete root;
				root = 0;

				if(tmp){
					return tmp;
				}
				return root;
			}
			else if(root->right == 0){
				Node* tmp = root->left;
				delete root;
				root = 0;

				if(tmp){
					return tmp;
				}
				return root;
			}
			else{
				// get data from the rightmost node in the left subtree
				Node* tmp = root->left;
				while(tmp->right != 0){
					tmp = tmp->right;
				}
				root->setData(*tmp->data);

				//delete the rightmost node in the left subtree
				root->left =  deleteNode(*root->data, root->left) ;
			}
		}
	}
	return root;
}

/*
 * preOrder(Node *node) recurses through the tree
 * and prints the value stored in each node pre-order.
 */
void BinaryTree::preOrder(Node *node){

	if(!node) return;

	std::cout << *node->data << " ";
	preOrder(node->left);
	preOrder(node->right);
}

/*
 * inOrder(Node *node) recurses through the tree
 * and prints the value stored in each node in-order.
 */
void BinaryTree::inOrder(Node *node){

	if(!node) return;

	inOrder(node->left);
	std::cout << *node->data << " ";
	inOrder(node->right);
}

/*
 * postOrder(Node *node) recurses through the tree
 * and prints the value stored in each node post-order.
 */
void BinaryTree::postOrder(Node *node){

	if(!node) return;

	postOrder(node->left);
	postOrder(node->right);
	std::cout << *node->data << " ";
}

/*
 * destroyTree(Node *node)
 *
 * Resets the BinaryTree by destroying all nodes
 * in the tree and setting root to null.
 */
void BinaryTree::destroyTree(Node *node)
{
	if(node)
	{
		destroyTree(node->left);
		destroyTree(node->right);
		delete node;
		node = 0;
	}
}


/*
 * Nested Class - Node definitions follow.
 */

/*
 * Node constructor
 */
BinaryTree::Node::Node(int value){
	data = new int(value);
	left = right = 0;
}

/*
 * Node Destructor
 */
BinaryTree::Node::~Node(){
	delete data;
	data = 0;
	left = right = 0;
}

/* Node::
 *
 * void setData(int value)
 *
 * Sets the value of data in a Node.
 *
 */
void BinaryTree::Node::setData(int value){
	*data = value;
}


