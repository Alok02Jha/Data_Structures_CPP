// Petin Evgeniy	CSIT-836
//Section#:			7026

#include <iostream>
#include "date.h"
using namespace std;

void Date::setDate(int& mo, int& da, int& ye)
{
	
	month = mo;
	day = da;
	year = ye;

	if (ye < 1900 || ye > 2008)
	{
		year=2008;
		day= 2;
		month = 9;
	}

	if (da < 1 || da > 31)
	{
		year=2008;
		day= 2;
		month = 9;
	}
	if (mo <1 || mo > 12)
	{
		year=2008;
		day= 2;
		month = 9;
	}

}

void Date::printDate()
{
	cout<<month;
	cout<<"/";
	cout<<day;
	cout<<"/";
	cout<<year;
	cout<<endl;
}