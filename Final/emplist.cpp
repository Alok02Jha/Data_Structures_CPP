// Petin Evgeniy	CSIT-836
//Section#:			7026
// Final

#include "emplist.h"
#include <iostream>
#include<string>
using namespace std;

int EmployeeList::TotalPay()
{
	return TotalPayR(head);
}

int EmployeeList::TotalPayR(Employee* Str)
{
	int Total=0;

	if(Str != NULL)
	{
		Employee* Cond = Str;

		Total+= Cond->pay;

		while (Cond->link != NULL)
		{
			Cond = Cond->link;
			Total+=Cond->pay;
		}
	}
	return Total;
}

EmployeeList::EmployeeList()
{
	head = NULL;
}

EmployeeList::~EmployeeList()
{
	Employee* start = head;

	while(start != NULL)
	{
		Employee* next = start->link;
		delete start;
		start = next;
	}
}

void EmployeeList::ViewList()
{
	
	Employee* Conductor = head;

	if(Conductor == NULL)
	{
		cout<<endl<<"List is Empty"<<endl;
	}

	else
	{

		//cout<<"# Name Contribution"<<endl;
		cout<<"======================================="<<endl<<endl;

		while(Conductor->link != NULL)
		{
			cout<<Conductor->name<<" $"<<Conductor->pay<<endl;
			Conductor = Conductor->link;
		}

		cout<<Conductor->name<<" $"<<Conductor->pay<<endl;
	}
}

void EmployeeList::AddToList()
{
	 string Aname;
	int Apay;


	cout << "\nEnter name: ";
	cin>> Aname;
	cout<< "\nEnter pay: ";
	cin >> Apay;

	Employee* currPtr = head;//= new PersonRec;
	Employee* NewEntry;
	NewEntry = new Employee;
	
	NewEntry->name = Aname;
	NewEntry->pay = Apay;
	NewEntry->link = NULL;

	if(head==NULL)
	{
		head = NewEntry;
	}
	else
	{
		while(currPtr->link != NULL)
		{
			currPtr = currPtr->link;
		}

		currPtr->link = NewEntry;
		/*currPtr->name = Aname;
		currPtr->pay = Apay;*/
	}
}

void EmployeeList::MovetoFront()
{

	if(head != NULL)
	{
		if(head->link != NULL)
		{
			Employee* BeforeLast = head;
			Employee* LastOne =head;

			while(BeforeLast->link->link != NULL)
			{
				BeforeLast = BeforeLast->link;
			}

			/*while(BeforeLast->link != NULL)
			{
			if(BeforeLast->link->link != NULL)
			{
			BeforeLast = BeforeLast->link;
			}
			}*/
			while (LastOne->link != NULL)
			{
				LastOne = LastOne->link;
			}

			LastOne->link=head;
			head = LastOne;
			BeforeLast ->link = NULL;
			//delete Conductor;
		}
		else
		{
			cout<<"Nothing to move"<<endl;
		}
	}
	else
	{
		cout<<"List is Empty"<<endl;
	}
	
}