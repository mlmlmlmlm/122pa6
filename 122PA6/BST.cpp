#include "BST.h"



BST::BST(std::ifstream& infile)
{
	
	char nlet;
	string nstring;
	infile >> nlet;
	infile >> nstring;
	BSTNode* top = new BSTNode(nstring, nlet);
	this->root = top;

	while (!infile.eof())
	{
		infile >> nlet; 
		infile >> nstring;

		BSTNode* node = new BSTNode(nstring, nlet); //create new node wtih vales from infile 

		insertNode(node, top);
	}

	infile.close(); //close infile
}

BST::~BST()
{
	destroyTree(this->root);
}

void BST::insertNode(BSTNode* const newnode, BSTNode* check)
{
	
	if ( newnode->getlet() < check->getlet() )  //left condition
	{
		if (check->getLeftPtr() == nullptr)  
		{
			check->setLeftPtr(newnode);
			return;
		}
		else
		{
			insertNode(newnode, check->getLeftPtr());
		}
	}
	else
	{
		if (check->getrightPtr() == nullptr)
		{
			check->setrightPtr(newnode);
			return;
		}
		else
		{
			insertNode(newnode, check->getrightPtr());
		}

	}
	//ignoring duplicates for now
}

BSTNode* BST::getRoot()
{
	return this->root;
}


void BST::print(BSTNode* printnode) //in order traversal implemetned recursivly
{
	if (printnode == nullptr)
	{
		return;
	}
	print(printnode->getLeftPtr());
	std::cout << printnode->getlet();
	print(printnode->getrightPtr());
}

string BST::search(char c, BSTNode* searchnode) //nonrecursive solution for searchnode using stacks,  
{
	////recursive solution, pre order, needs return parametr prin to work and no returned value

	//if (searchnode != nullptr)
	//{
	//	if (c == searchnode->getlet())
	//	{
	//		prin = searchnode->getdata();
	//	}
	//	search(c, searchnode->getLeftPtr(), prin);
	//	search(c, searchnode->getrightPtr(), prin);
	//}

	//non recursive with stacks


	Stack<BSTNode*> stack; //create stack of nodes
	stack.push(searchnode);


	while (!stack.isEmpty())
	{
		BSTNode* test;
		BSTNode* test2;
		stack.pop(test);
		if (test->getlet() == c)
		{
			return test->getdata();
		}
		
		if (test->getrightPtr() != nullptr && c > test->getlet()) //push right pointer to stack if it isnt null
		{

			test2 = test->getrightPtr(); 
			stack.push(test2);

		}
		
		if (test->getLeftPtr() != nullptr && c < test->getlet()) //push left ptr to stack if it isnt null, 
		{
			test2 = test->getLeftPtr();
			stack.push(test2);

		}
		
	}
	return "invalid";
}




void BST::destroyTree(BSTNode* killnode)
{
	if (killnode != nullptr)
	{
		destroyTree(killnode->getLeftPtr());
		destroyTree(killnode->getrightPtr());
		delete killnode;
	}
}