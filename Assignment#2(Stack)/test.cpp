// Petin Evgeniy	CSIT-836
//Section#:			7026

#include "cstack.h"
#include <iostream>
#include <cstring>
using namespace std;
bool isValidExpression (CStack&, char*);
//#include "date.h"

int main (void)    // The driver file has the main function 
{
	char expression[21];    // allocate memory for user string input
	cout<< "Enter an expression: ";
	cin >>expression;

	CStack stack1;    // creates an instance of a stack (stack1) using class constructor
	if (isValidExpression (stack1, expression))

	/* This calls the isValidExpression function (which you still need to write) to
	fill the data array of the stack. The parameter is the stack instance stack1 */

	cout << "\nIt's a valid expression"<<endl;
	else
	cout << "\nIt's NOT a valid expression"<<endl;

	system ("pause");
	return 0;
}

/* This ends the main function. Now we (you) have 
to write the isValidExpression function. I'll give you 
the function header, and then some hints. */

bool isValidExpression (CStack& stackA, char* strExp)
{
	bool bal;//=false;
	for (int x=0; x<22; x++)
	{
		//bal = false;
		//while (strExp[x] != 0)
		//{
			if (strExp[x] == '{' || strExp[x] == '[' || strExp[x] == '(')
			{
				bal=false;
				if(stackA.IsFull())
				{cout<<endl<<"STacks (char* data) is Full, cannot write character to the ARRAY"<<endl;/*break;*/} //Could use break to stop loop (Not using by Genghis Khent)
				else
				stackA.Push(strExp[x]);
			}

			else if (strExp[x] == '}' || strExp[x] == ']' || strExp[x] == ')')
			{
				//bool bal = false;
				if(stackA.IsEmpty()){cout<<endl<<"Stacks (char* data) is Empty, cannot return top character to compare"<<endl;/*break;*/} //Could use break to stop loop (Not using by Genghis Khent)
				else{
				char test = stackA.ReturnTopChar();
				char test2 = strExp[x];

				if (test == '(' && test2 == ')' || test == '[' && test2 == ']' || test == '{' && test2 == '}' )
				{
					stackA.Pop();
					bal=true;
				}
				else
					bal=false;
				}
			}
					
		}


	if(stackA.IsEmpty())
	{bal=true;}
	else
	{bal=false;}

	return bal;
}
// end of driver file
// call printDate
	


 