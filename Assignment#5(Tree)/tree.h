// Petin Evgeniy	CSIT-836
//Section#:			7026
// Assignment #5

struct PersonRec
{
	char name[20];
	int bribe;
	PersonRec* lChild;
	PersonRec* rChild;

	PersonRec(char*, int, PersonRec*, PersonRec*);
};

class CTree 
{
public:

	CTree();
	~CTree();

	void Add();
	bool isEmpty();
//	bool isFull();
	void View();

private:

	void Destruct (PersonRec*);
	PersonRec* root;
	//PersonRec* Root();
	void BuildRoot(char*, int);
	//void AppendLeft (PersonRec*, char*, int);
	//void AppendRight (PersonRec*, char*, int);
	void AddItem (PersonRec*&, char*, int);
	void DisplayTree(PersonRec*);
};