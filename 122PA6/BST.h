#include <iostream>
#include <string>
#include <fstream>
#include "BSTNode.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class BST
{
public:
	BST(std::ifstream& infile); //constroctor requires a file to load tree from

	~BST(); //destroctor calls destroy tree function

	void insertNode(BSTNode* const newnode, BSTNode* check); //inserts the node by comparing its numerical ascii value, recursive
	

	void print(BSTNode* printnode); //prints node tree using inorder traversal
	BSTNode* getRoot(); //getter for root

	string search(char c, BSTNode* searchnode); //used stacks for this 


private:
	BSTNode* root;

	void destroyTree(BSTNode* killnode);
};


