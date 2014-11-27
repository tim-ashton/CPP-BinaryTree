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


void BinaryTree::deleteNode(int value){
	root = deleteNode(value, root);
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
 * Cases for deletion
 *
 * is not in a tree;
 * is a leaf;
 * has only one child;
 * has two children.
 */
BinaryTree::Node* BinaryTree::deleteNode(int value, Node *root){

	if(root){
		if(value < root->data){
			root->left = deleteNode(value, root->left);
		}
		else if(value > root->data){
			root->right = deleteNode(value, root->right);

		}
		else {
			if(root->left == 0){
				return root->right;
			}
			else if(root->right == 0){
				return root->left;
			}
			else{

				// get data from the rightmost node in the left subtree
				Node* tmp = root->left;
				while(tmp->right != 0){
					tmp = tmp->right;
				}
				root->data = tmp->data;

				//delete the rightmost node in the left subtree
				root->left =  deleteNode(root->data, root->left) ;
	       }
		}
	}

	/*

    if (compare(toDelete, p.data) < 0)
    p.left = delete (p.left, toDelete);
    else
    if (compare(toDelete, p.data)  > 0)
    p.right = delete (p.right, toDelete);
    else
    {
       if (p.left == null) return p.right;
       else
       if (p.right == null) return p.left;
       else
       {
       // get data from the rightmost node in the left subtree
          p.data = retrieveData(p.left);
       // delete the rightmost node in the left subtree
          p.left =  delete(p.left, p.data) ;
       }
    }*/

	return root;
}


/*
 * Node implementation
 */

BinaryTree::Node::Node(int value){
	data = value;
	left = right = 0;
}


