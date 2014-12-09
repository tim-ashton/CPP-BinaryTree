/*
 * Main.cpp
 *
 *  Created on: Nov 19, 2014
 *      Author: Tim Ashton
 */

#include "BinaryTree.h"

#include <iostream>

using namespace std;


int main() {
	BinaryTree *bt = new BinaryTree();

	bt->insert(7);
	bt->insert(6);
	bt->insert(8);
	bt->insert(3);
	bt->insert(11);
	bt->insert(15);
	bt->insert(9);
	bt->insert(4);
	bt->insert(5);
	bt->insert(1);

	bt->preOrder();
	cout << "\n";

	bt->inOrder();
	cout << "\n";

	bt->postOrder();
	cout << "\n";

	bt->deleteNode(1);
	bt->inOrder();
	cout << "\n";

	bt->deleteNode(3);
	bt->inOrder();
	cout << "\n";

	bt->deleteNode(7);
	bt->inOrder();
	cout << "\n";

	bt->deleteNode(5);
	bt->inOrder();

	bt->deleteNode(15);
	bt->deleteNode(9);

	bt->deleteNode(4);
	bt->deleteNode(8);

	bt->deleteNode(1);
	bt->deleteNode(11);
	bt->deleteNode(9);
	bt->deleteNode(6);


	delete bt;
	return 0;
}



