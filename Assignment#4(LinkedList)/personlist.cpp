#include "personlist.h"
#include <iostream>
using namespace std;

PersonList::PersonList()
{
	head = NULL;
//	head->link = NULL;
}

bool PersonList::IsEmpty()
{
	return (head==NULL);
}

//void PersonList::InsertBefore(PersonRec* Conductor, PersonRec* InsertThis)
//{
//	
//}

void PersonList::InsertAfter(PersonRec* Conductor, PersonRec* InsertThis)
{
	InsertThis->link = Conductor->link;
	Conductor->link = InsertThis;
}

void PersonList::AddToList()
{
	char aName[20];
	int aBribe;

	cout << "\nEnter the person's name: ";
	cin.getline(aName, 20);
	cout<< "\nEnter the person's contribution: ";
	cin >> aBribe;

	PersonRec* currPtr = head;//= new PersonRec;
	PersonRec* NewEntry;
	NewEntry = new PersonRec;
	
	
	strcpy (NewEntry->name, aName);
	NewEntry->bribe = aBribe;
	NewEntry->link = NULL;

	if(head==NULL)
	{
		head = NewEntry;
	}

	else if(NewEntry->bribe > currPtr->bribe)
		{
			NewEntry->link = head;
			head = NewEntry;
			currPtr = head;
		}

	else
	{
		while (NewEntry->bribe < currPtr->bribe && currPtr->link != NULL || NewEntry->bribe == currPtr->bribe && currPtr->link != NULL )
		{
			currPtr = currPtr->link;
		}

		if(NewEntry->bribe == currPtr->bribe)
		{
			InsertAfter(currPtr, NewEntry);
		}

		else
		{
			InsertAfter(PrevPtr(currPtr), NewEntry);
		}
	}
}

void PersonList::ViewList()
{
	
	PersonRec* Conductor = head;

	if(Conductor == NULL)
	{
		cout<<endl<<"List is Empty"<<endl;
	}

	else
	{

		cout<<"# Name Contribution"<<endl;
		cout<<"======================================="<<endl<<endl;

		while(Conductor->link != NULL)
		{
			cout<<Conductor->name<<" $"<<Conductor->bribe<<endl;
			Conductor = Conductor->link;
		}

		cout<<Conductor->name<<" $"<<Conductor->bribe<<endl;
	}
}

PersonList::~PersonList()
{
	PersonRec* start = head;

	while(start != NULL)
	{
		PersonRec* next = start->link;
		delete start;
		start = next;
	}
}

bool PersonList::EndOfList(PersonRec* currP)
{
	return (currP==NULL);
}

PersonRec* PersonList::PrevPtr(PersonRec* currP)
{
	//PersonRec returnVal;
	PersonRec* retpointer;// = currP;

	retpointer = head;

	while (retpointer->link != currP)
	{
		retpointer = retpointer->link;
	}

	/*if(retpointer->link == currP)
		retpointer = retpointer->link;*/
	/*if(retpointer == head)
		retpointer=NULL;*/
	
	return retpointer;
}