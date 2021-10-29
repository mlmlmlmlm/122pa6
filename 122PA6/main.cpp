
/*******************************************************************************************

* Programmer: Matthew McIntosh                                                    *

*******************************************************************************************/


#include "BST.h"


int main(void)
{


	std::ifstream infile;
	infile.open("MorseTable.txt", std::ios::in);

	std::ifstream convert;
	convert.open("Convert.txt", std::ios::in);

	BST morse(infile);

//	morse.print(morse.getRoot());

	char c;
	string help;


	morse.print(morse.getRoot()); //in order traversal print node

	cout << endl << endl;


	while (convert.eof() == false) //while file is open
	{
				
		std::getline(convert, help); //pulls ine from convert

		for (int i = 0; i < help.length(); i++) //loops thorugh string at certain characters
		{
			c = help.at(i);
			if (c == ' ')
			{
				cout << "  "; //converst single space to 2 space like in example
			}
	
			else
			{				
				cout << morse.search(toupper(c), morse.getRoot());
				
				cout << " "; //need to add space after every morese letter
			}
		}
		cout << endl; //add endl at aend of line
	}	
	convert.close(); //close convert file

	return 0;
}

