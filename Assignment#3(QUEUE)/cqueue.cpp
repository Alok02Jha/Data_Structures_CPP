#include "cqueue.h"

//using namespace std;

CQueue::CQueue()
{
	front = MAX-1;
	rear = MAX-1;
}

void CQueue::Dequeue()
{
	if (front == MAX-1)
	{front = 0;}
	else
	{front++;}// = (front+1)%MAX;}
}

void CQueue::Enqueue(Passenger pass)
{
	
	if (rear == MAX-1)
	{	
		rear = (rear + 1) % MAX;
	}
	else	
	{rear++;}// = (rear+1)%MAX;}
	
	for (int i=0; i<80; i++)
	{
		passengers[rear].name[i] = pass.name[i];
	}
}

Passenger CQueue::Front()
{
		return passengers [(front + 1) % MAX];
}


bool CQueue::IsEmpty()
{
	return (front == rear);
}

bool CQueue::IsFull()
{
	if((rear + 1) % MAX == front)
		return true;
	else
		return false;
}

CQueue CQueue::operator=(const CQueue *right)
{
		front = right->front;
		rear = right->rear;
	
		for (int x=0; x<MAX; x++)
		{
			for(int i=0; i<80; i++)
			{
				passengers[x].name[i] = right->passengers[x].name[i];
			}

		/*passengers[0].name[80] = right->passengers[0].name[80];
		passengers[1].name[80] = right->passengers[1].name[80];
		passengers[2].name[80] = right->passengers[2].name[80];
		passengers[3].name[80] = right->passengers[3].name[80];*/
		}

		return *this;
}

ostream& operator << (ostream& out, CQueue& Data)
{
	
	/*for (int i=0; i<4; i++)
	{
		for(int d=0; d<81; d++)
		{
			out<<Data.passengers[i].name[d];
		}
		cout<<endl;
	}*/
	cout<<endl;
	cout<<endl;
	out<<Data.passengers[3].name;
	cout<<endl;
	cout<<endl;
	out<<Data.passengers[0].name;
	cout<<endl;
	cout<<endl;
	out<<Data.passengers[1].name;
	cout<<endl;
	cout<<endl;

	return out;
}