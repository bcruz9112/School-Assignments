#include "BST.h"

/*
	Bradley Cruz
	Assignment: PA6
	October 25, 2021

	Description: This program builds a tree using letters and morse code equivalents from text file "MorseTable.txt" and prints the contents of the tree.
	It then uses this data to convert expressions from "Convert.txt" into morse code.


	Last edited: 10/27/2021

*/
int main()
{
	fstream conversion;
	conversion.open("Convert.txt", std::ios::in);
	BST<char> bruh;

	cout << "Printing tree contents!" << endl;
	bruh.print();


	if (conversion.is_open())
	{
		while (!conversion.eof())
		{
			
			char text[333] = "";
			conversion.getline(text, 333);
			cout << "\nTranslating: " << text << endl;
			for (int i = 0; i < sizeof(text); i++)
			{
				if (text[i] == ' ')
				{
					cout << "   ";
				}
				else
				{
					bruh.search(text[i]);
				}
			}
			cout << endl;
		}
	}
	bruh.destroyTree();
	conversion.close();
	return 0;

}