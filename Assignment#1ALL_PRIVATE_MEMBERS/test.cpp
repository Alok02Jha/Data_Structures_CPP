// Petin Evgeniy	CSIT-836
//Section#:			7026

#include <iostream>

using namespace std;

#include "date.h"

int main()

{

Date d1;

int m, d, y;

cout << "Enter month, day and year separated by spaces: ";

cin >> m >> d >> y;

// call setDate
d1.setDate(m,d,y);
d1.printDate();

system ("pause");
// call printDate
return 0;

}

 