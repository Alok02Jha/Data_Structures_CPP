// Petin Evgeniy	CSIT-836
//Section#:			7026


#include <cstring>
using namespace std;

class CStack
{
private:
	int top;
	char data[21];

public:
	void Push (char);
	void Pop ();
	char Top ();
	bool IsEmpty ();
	bool IsFull ();
	char ReturnTopChar ();

	CStack ();
};