#include "BSTNode.h"


BSTNode::BSTNode(const std::string& newData, char let) //constructor
{
	this->letter = let;
	this->morse = newData;
	this->pleft = nullptr;
	this->pright = nullptr;
}


void BSTNode::setLeftPtr(BSTNode* const newleft)
{
	this->pleft = newleft;
}
void BSTNode::setrightPtr(BSTNode* const newright)
{
	this->pright = newright;
}
void BSTNode::setdata(std::string& const newData, char let)
{
	this->letter = let;
	this->morse = newData;
}




BSTNode* BSTNode::getLeftPtr()
{
	return pleft;
}
BSTNode* BSTNode::getrightPtr()
{
	return pright;
}
std::string BSTNode::getdata()
{
	return morse;
}
char BSTNode::getlet()
{
	return letter;
}

std::ofstream& operator<< (std::ofstream& outfile, BSTNode* node)
{

	outfile << node->getdata();
	return outfile;
}