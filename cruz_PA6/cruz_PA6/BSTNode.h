#pragma once
#include <iostream>
#include <string>

using std::string;



	template <typename NODETYPE>
	class Node
	{
	public:
		Node();
		Node(const char& newData, const string& newString);
		Node* getLeftPtr();
		Node* getRightPtr();
		char getLetter();
		string getString();
		void setLeftPtr(Node<NODETYPE>* newPtr);
		void setRightPtr(Node<NODETYPE>* newPtr);
		void setMorse(const NODETYPE& newString);

	private:
		char mpLetter;
		string mpMorse;
		Node* mpLeft;
		Node* mpRight;

	};

template <typename NODETYPE>
Node<NODETYPE>::Node()
{
	mpLetter = "";
	mpMorse = "";
	mpLeft = nullptr;
	mpRight = nullptr;

}

template <typename NODETYPE>
Node<NODETYPE>::Node(const char& newData, const string& newString)
{
	mpLetter = newData;
	mpMorse = newString;

	mpLeft = nullptr;
	mpRight = nullptr;
}

template <typename NODETYPE>
Node<NODETYPE>* Node<NODETYPE>::getLeftPtr()
{
	return mpLeft;
}

template <typename NODETYPE>
Node<NODETYPE>* Node<NODETYPE>::getRightPtr()
{
	return mpRight;
}

template <typename NODETYPE>
void Node<NODETYPE>::setLeftPtr(Node<NODETYPE>* newPtr)
{
	mpLeft = newPtr;
}

template <typename NODETYPE>
void Node<NODETYPE>::setRightPtr(Node<NODETYPE>* newPtr)
{
	mpRight = newPtr;
}

template <typename NODETYPE>
void Node<NODETYPE>::setMorse(const NODETYPE& newString)
{
	mpMorse = newString;
}

template <typename NODETYPE>
char Node<NODETYPE>::getLetter()
{
	return mpLetter;
}

template <typename NODETYPE>
string Node<NODETYPE>::getString()
{
	return mpMorse;
}

