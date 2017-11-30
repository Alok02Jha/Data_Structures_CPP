// Petin Evgeniy	CSIT-836
//Section#:			7026

#include "estack.h"
#include <string>
//#include <cstring>
using namespace std;

EStack::EStack()
{
	top = -1;
	for (int x=0; x<3; x++)
		data[x] = "" ;
}

void EStack::Push(string par)
{
	data[top+1] = par;
	top++;
}

void EStack::Pop()
{
	top--;
}

string EStack::Top()
{
	return data[top];
}

bool EStack::IsEmpty()
{
	if(top>(-1))
		return false;
	else
		return true;
}

bool EStack::IsFull()
{
	if(top == 2)
		return true;
	else
		return false;
}

//char EStack::ReturnTopChar()
//{
//	return data[top];
//}