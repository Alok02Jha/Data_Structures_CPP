#include <iostream>
#include <string>
using namespace std;
const int MAX = 4;  //To do: determine appropriate number

struct Passenger 
{
	char name[80];
};

class CQueue 
{
private:
	int front;
	int rear;
	Passenger passengers[MAX];

public:
	CQueue();
	bool IsEmpty(void);
	bool IsFull(void);
	void Enqueue(Passenger);
	Passenger Front(void);
	void Dequeue(void);

	//void ShowQueue();


	CQueue operator = (const CQueue *right);
	friend ostream& operator << (ostream&, CQueue&);


	
};