#include "Stack.h"
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class BSTNode
{
public:
	BSTNode(const string& newData = "", char let = NULL); //constructor


	//setters
	void setLeftPtr(BSTNode* const newleft);
	void setrightPtr(BSTNode* const newright);
	void setdata(string& const newData, char let);
	//getters
	BSTNode* getLeftPtr();
	BSTNode* getrightPtr();
	string getdata();
	char getlet();



private:

	char letter; //associtated character
	string morse; //dash dot string

	BSTNode* pleft; //lesser
	BSTNode* pright; //greater
};


std::ofstream& operator<< (std::ofstream& outfile, BSTNode* node); //ended up not using

