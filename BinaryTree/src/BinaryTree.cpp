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
	destroyTree(root);
}



void BinaryTree::insert(int value) {
	insert(value, root);
}


void BinaryTree::deleteNode(int value){
	root = deleteNode(value, root);
}


/*
 * destroys all nodes in the tree and
 * leaves root as null ptr.
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
				root->assignNewData(*tmp->data);

				//delete the rightmost node in the left subtree
				root->left =  deleteNode(*root->data, root->left) ;
			}
		}
	}
	return root;
}


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
 * Node implementation
 */

BinaryTree::Node::Node(int value){
	data = new int(value);
	left = right = 0;
}

BinaryTree::Node::~Node(){
	delete data;
	data = 0;
	left = right = 0;
}

void BinaryTree::Node::assignNewData(int value){
	delete data;
	data = 0;
	data = new int(value);
}


