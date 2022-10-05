#pragma once
#include "BSTNode.h"
#include <fstream>
using std::fstream;
using std::cout;
using std::endl;

template <typename TREE>
class BST
{
	public:
		BST();
		~BST();
		void print();
		void search(char& letter);
		void destroyTree();


	private:
		void insert(Node<TREE>* pTree, char& newLetter, string& newString);
		void print(Node<TREE>* pTree);
		void search(Node<TREE>* pTree, char& letter);
		void destroyTree(Node<TREE>* pTree);
		Node<TREE>* mpRoot;

};


template <typename TREE>
BST<TREE>::BST()
{
	mpRoot = nullptr;
	fstream infile;
	infile.open("MorseTable.txt", std::ios::in);

	if (infile.is_open())
	{
		while (!infile.eof())
		{
			char tempChar;
			infile >> tempChar;
			string tempString;
			infile >> tempString;
			insert(mpRoot, tempChar, tempString);
		}
	}
	infile.close();
}

template <typename TREE>
BST<TREE>::~BST()
{

}

template <typename TREE>
void BST<TREE>::insert(Node<TREE>* pTree, char& newLetter, string& newString)
{
	if (pTree == nullptr)
	{
		//tree empty, insert root
		mpRoot = new Node<TREE>(newLetter, newString);
	}
	else
	{
		if (pTree->getLetter() > newLetter)
		{
			if (pTree->getLeftPtr() == nullptr)
			{
				//insert at empty node
				pTree->setLeftPtr(new Node<TREE>(newLetter, newString));
			}
			else
			{
				//node not empty, continue traversing left subtree
				insert(pTree->getLeftPtr(), newLetter, newString);
			}
		}
		else if (pTree->getLetter() < newLetter)
		{
			if (pTree->getRightPtr() == nullptr)
			{
				//insert at empty node
				pTree->setRightPtr(new Node<TREE>(newLetter, newString));
			}
			else
			{
				//continue traversing right tree
				insert(pTree->getRightPtr(), newLetter, newString);
			}
		}
		else
		{
			//dupe
			std::cout << "Dupe data :(" << std::endl;
		}
	}
}

template <typename TREE>
void BST<TREE>::print() // public print function
{
	print(mpRoot);
}

template <typename TREE>
void BST<TREE>::print(Node<TREE>* pTree)
{
	if (pTree != nullptr)
	{
		//in order traversal 
		print(pTree->getLeftPtr());
		std::cout << pTree->getLetter() << " Translated: " << pTree->getString() << std::endl;
		print(pTree->getRightPtr());
	}

}


template <typename TREE>
void BST<TREE>::search(char& letter)
{
	if (letter > 96) //in case of a lowercase letter
	{
		letter = letter - 32;
	}
	return search(mpRoot, letter);
}

template <typename TREE>
void BST<TREE>::search(Node<TREE>* pTree, char& letter)
{
	if (pTree != nullptr) //if tree isnt empty
	{
		//post order traversal
		search(pTree->getLeftPtr(), letter);
		search(pTree->getRightPtr(), letter);
		if (pTree->getLetter() == letter)
		{
			//print morse code if letters match
			cout << pTree->getString() << " ";
		}
	}
}

template <typename TREE>
void BST<TREE>::destroyTree() //public destroy tree
{
	destroyTree(mpRoot);
}

template <typename TREE>
void BST<TREE>::destroyTree(Node<TREE>* pTree)
{
	if (pTree != nullptr)
	{
		//post ordr traversal
		destroyTree(pTree->getLeftPtr());
		destroyTree(pTree->getRightPtr());
		delete pTree;
	}
}
