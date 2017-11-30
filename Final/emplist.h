
// Petin Evgeniy	CSIT-836
//Section#:			7026
// Final

//  emplist.h

#include <iostream>
#include<string>
using namespace std;

struct Employee {
   string name;
   int pay;
   Employee* link;
};

class EmployeeList {
public:
   EmployeeList();
   ~EmployeeList();
   void AddToList();
   void ViewList(); 
   void MovetoFront(); 
   int TotalPay();     
private:
    Employee* head;
    int TotalPayR(Employee*); 
};
