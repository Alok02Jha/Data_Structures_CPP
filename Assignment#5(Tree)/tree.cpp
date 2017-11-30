// Petin Evgeniy	CSIT-836
//Section#:			7026
// Assignment #5

#include "tree.h"
#include <iostream>
using namespace std;

//4 argument constructor for structure
PersonRec::PersonRec(char* TName, int TBribe, PersonRec* TEmpty, PersonRec* TNull)
{
	//name = something;
	strcpy(name, TName);
	bribe = TBribe;
	lChild = TEmpty;
	rChild = TNull;
}
CTree::CTree()
{
	root = NULL;
}
CTree::~CTree()
{
	Destruct(root);
}
void CTree::Destruct(PersonRec* Decay)
{
	if( Decay != NULL)
	{
		Destruct(Decay->rChild);
		Destruct(Decay->lChild);
		delete Decay;
	}
}
bool CTree::isEmpty()
{
	return (root==NULL);
}
void CTree::BuildRoot(char* Name, int Bribe)
{
	//PersonRec* NewEntry;
	root = new PersonRec (Name, Bribe, NULL, NULL);
	//PersonRec* currPtr = root;
}
void CTree::AddItem(PersonRec*& leaf, char* Name, int Bribe)
{
	if (Bribe < leaf->bribe)
	{
		if(leaf->lChild != NULL)
			AddItem(leaf->lChild, Name, Bribe);
		else
		{
			leaf->lChild = new PersonRec (Name, Bribe, NULL, NULL);
		}
	}

	else if (Bribe > leaf->bribe)
	{
		if (leaf->rChild != NULL)
			AddItem(leaf->rChild, Name, Bribe);
		else
		{
			leaf->rChild = new PersonRec (Name, Bribe, NULL, NULL);
		}
	}

	else if (Bribe == leaf->bribe)
	{
		cout<<endl<<"This bribe amount has already been paid"<<endl;
	}
}
void CTree::Add()
{
	char aName[40];
	int aBribe;
	cout << "\nEnter the person's name: ";
	cin >> aName; // assumes no embedded spaces in name
	cout<< "\nEnter the person's contribution: ";
	cin >> aBribe;

	/*PersonRec* NewEntry;
	NewEntry = new PersonRec (aName, aBribe, NULL, NULL);*/
	
	if(isEmpty())
	{
		BuildRoot(aName, aBribe);
	}
	else
		AddItem(root, aName, aBribe);
}

void CTree::DisplayTree(PersonRec* RT)
{
	
	if(RT != NULL)
	{
		DisplayTree(RT->rChild);
		cout<< RT->name<< " $" <<RT->bribe<<endl;
		DisplayTree(RT->lChild);
	}

	/*else
		cout<<RT->bribe<<endl;*/
	/*else
		cout<<"List is Empty"<<endl;*/
}

void CTree::View()
{
	cout<<endl;
	if(isEmpty())
	{
		cout<<"List is Empty"<<endl;
	}
	else
	DisplayTree(root);
}