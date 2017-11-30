//Code for Program #1
// Petin Evgeniy	CSIT-836
//Section#:			7026


//stest.cpp

#include "estack.h"
#include <iostream>
#include <string>
using namespace std;

/* include any other standard library files 
and namespaces you may need */
int displayMenu();
 void hire (EStack&);
 void fire (EStack&);
 void view (EStack);

int displayMenu();

int main ()
{
	EStack stk;
	int choice;
	do {
		choice = displayMenu();
		switch (choice)
		{
		case 1:
			hire(stk);
			break;
		case 2: 
			fire(stk);
			break;
		case 3: 
			view(stk);
			break;
		case 4:	cout << "Exiting\n";
			break;
		default: cout<< "Invalid choice\n";
		}
	} while (choice != 4);
}

int displayMenu()
{
	int input;
	cout << "1. Hire\n";
	cout << "2. Fire\n";
	cout << "3. View\n";
	cout << "4. Exit\n";
	cout << "Enter choice: ";
	cin >> input;
	return input;
}

void hire (EStack& OurStack)
{
	if (OurStack.IsFull())
	{
		cout<<"No Positions available"<<endl;
	}
	else
	{
		string name;
		cout<<"Enter name of hiree: ";
		cin >> name;
		OurStack.Push(name);
	}
}

void fire (EStack& OurStack)
{
	if(OurStack.IsEmpty())
	{
		cout<<"No one left to fire"<<endl;
	}
	else
	{
		cout<<OurStack.Top()<<" is fired"<<endl;
		OurStack.Pop();
	}

}

void view (EStack OurStack)
{
	if(OurStack.IsEmpty())
	{
		cout<<"No Employees"<< endl;
	}
	else
	{
		EStack ViewStack = OurStack;
		while (!ViewStack.IsEmpty())
		{
			cout<<ViewStack.Top()<<endl;
			ViewStack.Pop();
		}
	}

}

