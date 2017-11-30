// estack.h
// Petin Evgeniy	CSIT-836
//Section#:			7026

#ifndef ESTACK_H
#define ESTACK_H
#include <string>
using namespace std;
//#include <estack.cpp>
/* include any standard library files and namespaces you may need */
const int MAX = 3;
class EStack 
{
public:
	EStack();
	bool IsEmpty();
	bool IsFull();
	void Push(string);
	void Pop();
	string Top();

private:
	int top;
	string data[MAX];
};
#endif 