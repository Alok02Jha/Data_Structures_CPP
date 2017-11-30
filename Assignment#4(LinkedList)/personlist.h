#ifndef PERSON_H
#define PERSON_H

struct PersonRec
	{
		char name[20];
		int bribe;
		PersonRec* link;
	};

class PersonList {

public:
	PersonList();
	~PersonList();

	void ViewList();
	void AddToList ();

	
	
private:
	PersonRec* head;
	bool IsEmpty();
	bool EndOfList (PersonRec*);
	PersonRec* PrevPtr(PersonRec*);
	void InsertAfter (PersonRec*,PersonRec*);
	void InsertBefore (PersonRec*,PersonRec*);
	/*

	insert here other private member functions as you

	see the need for them. However, you cannot add

	any additional member variables or public

	member functions than the four listed above

	*/
};
#endif