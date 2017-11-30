// Petin Evgeniy	CSIT-836
//Section#:			7026

#include "cstack.h"
using namespace std;

CStack::CStack()
{
	top = -1;
	for (int x=0; x<21; x++)
	data[x] = 0;
}

void CStack::Push(char par)
{
	data[top+1] = par;
	top++;
}

void CStack::Pop()
{
	top--;
}

char CStack::Top()
{
	return top;
}

bool CStack::IsEmpty()
{
	if(top>(-1))
		return false;
	else
		return true;
}

bool CStack::IsFull()
{
	if(top == 20)
		return true;
	else
		return false;
}

char CStack::ReturnTopChar()
{
	return data[top];
}