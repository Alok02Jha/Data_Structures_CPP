// Petin Evgeniy	CSIT-836
//Section#:			7026
// Assignment #3


#include <iostream>
#include <string>
#include "cqueue.h"
using namespace std;

enum choice { BOOKED, WAITING };

const int LINES = 2;

int showMenu(void);
void addPassenger(CQueue*);
void deletePassenger(CQueue*);
void showPassengers(CQueue*);

int main (void)
{
	system("color 02");

	CQueue qPassengers[LINES];

	int x;
	
	do{
		x = showMenu();
		switch (x)
		{
		case 1: addPassenger(qPassengers);
			break;
		case 2: deletePassenger(qPassengers);
			break;
		case 3: showPassengers(qPassengers);
			break;
		}
	} while (x != 4);
	system ("pause");
	return 0;
}

int showMenu(void)
{
	int select;

	cout << "Menu\n";
	cout << "========\n";
	cout << "1. Add Passenger\n";
	cout << "2. Delete Passenger\n";
	cout << "3. Show Passengers\n";
	cout << "4. Exit\n";
	cout << "Enter choice: ";
	cin >> select;
	return select;
}



// To do: implement addPassenger, deletePassenger and showPassengers

void addPassenger (CQueue* P)
{
	Passenger NameInput;
	cout<<"Enter name: ";
	cin>>NameInput.name;
	
	if(P[BOOKED].IsFull())
	{
		if(P[WAITING].IsFull())
		{
			cout<<"Sorry. Plane and waiting list fully booked. Try later"<<endl;
		}
		else
		{
			cout<<"Sorry. Plane fully booked. Adding "<<NameInput.name<<" to waiting list"<<endl;
			P[WAITING].Enqueue(NameInput);
		}
	}

	else
	{
		cout<<"Booking "<<NameInput.name<<" on flight"<<endl;
		P[BOOKED].Enqueue(NameInput);
	}
}

void deletePassenger (CQueue* DelP)
{
	
	if (DelP[BOOKED].IsEmpty())
	{
		cout<<"No passengers to delete"<<endl;
	}

	else
	{
		cout<<endl<<"Removing "<< DelP[BOOKED].Front().name <<" from booked passengers"<<endl;
		
		
		DelP[BOOKED].Dequeue();

		if (!DelP[WAITING].IsEmpty())
		{
			cout<<"Adding "<< DelP[WAITING].Front().name <<" fron waiting list"<<endl<<endl;
			DelP[BOOKED].Enqueue(DelP[WAITING].Front());
			DelP[WAITING].Dequeue();
		}
		
		/*if(DelP[WAITING].IsFull())
		{
			DelP[WAITING].Dequeue();
		}
		else
		{
			DelP[BOOKED].Enqueue(DelP[WAITING].Front());
			DelP[WAITING].Dequeue();
		}*/
		
	}
}



void showPassengers (CQueue* ShowP)
{
	
	
	CQueue OutPut[LINES];
	OutPut[BOOKED]  = ShowP[BOOKED];
	OutPut[WAITING] = ShowP[WAITING];

	Passenger show;

	/*cout<<ShowP[BOOKED].passengers[0].name<<endl;
	cout<<ShowP[BOOKED].passengers[1].name<<endl;
	cout<<ShowP[BOOKED].passengers[2].name<<endl;
	cout<<ShowP[BOOKED].passengers[3].name<<endl;
	cout<<ShowP[BOOKED].passengers[4].name<<endl;*/

	/*cout<<ShowP[0].front<<endl;
	cout<<ShowP[0].rear<<endl;
	cout<<ShowP[1].front<<endl;
	cout<<ShowP[1].rear<<endl;*/

		if(OutPut[BOOKED].IsEmpty())
		{
			cout<<"Booked list is Empty"<<endl;
		}
		else
		{
			//cout<<"First in QUEUE#2: " <<ShowP[WAITING].Front().name<<endl;
			cout<<endl<<"Booked Passengers"<<endl;
			cout<<"==================================="<<endl;

			//system("color 0A");

			for(int x=0; x<3; x++)
			{
				if(OutPut[BOOKED].IsEmpty())
				{
				}
				else
				{
					show = OutPut[BOOKED].Front();
					cout<<show.name<<endl;
					OutPut[BOOKED].Dequeue();
				}
			}

			cout<<endl<<"Waiting List"<<endl;
			cout<<"==================================="<<endl;

			//cout<<"End of Booked list"<<endl;
			//cout<<"Start of Waiting list"<<endl;
			for(int x=0; x<3; x++)
			{
				if(OutPut[WAITING].IsEmpty())
				{
				}
				else
				{
					show = OutPut[WAITING].Front();
					cout<<show.name<<endl;
					OutPut[WAITING].Dequeue();
				}
			}

			cout<<endl;

			//system("color 07");
			//cout<<"End of waiting list"<<endl;
		}
}