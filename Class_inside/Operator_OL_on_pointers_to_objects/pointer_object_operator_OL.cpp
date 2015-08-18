//
//    pointer_object_operator_OL.cpp
//
//    Operator Overloading by using Obj-Pointer
//
//    10:17 AM, Aug 18, 2015, by Mighten Dai <mighten.dai@gmail.com>
//
#include <iostream>

using namespace std;

//////////////////////////////////////////////////////////////////////
class   DEMO
{
private:
	int   m_member[10];
	char  m_flags;

public:
	~DEMO(){}
	 DEMO(){}

	 int    operator [] ( int  index );
	 friend ostream & operator << ( ostream &stream, DEMO & demo);
};

//////////////////////////////////////////////////////////////////////
int    DEMO::operator [] ( int  index )
{
	return this->m_member[index];
}

//////////////////////////////////////////////////////////////////////
ostream &  operator << ( ostream & stream, DEMO & demo)
{
	for ( int index = 0; index < 10; ++index )
	{
		stream << "[Traverse] #" << index << " = " << demo.m_member[index] << endl;
	}

	return stream;
}

//////////////////////////////////////////////////////////////////////
int   main( void )
{
	DEMO   demo;
	DEMO   *p_demo = new DEMO;

	cout << demo[3] << endl;

	cout << demo;
    cout << *p_demo;

	delete  p_demo;

	return 0;
}

/*
-------------------
2
[Traverse] #0 = 20852988
[Traverse] #1 = 0
[Traverse] #2 = 80
[Traverse] #3 = 2
[Traverse] #4 = 2829168
[Traverse] #5 = 1374356
[Traverse] #6 = 1863307760
[Traverse] #7 = 1374392
[Traverse] #8 = 20846562
[Traverse] #9 = 20856856
[Traverse] #0 = 5729616
[Traverse] #1 = 5712064
[Traverse] #2 = 0
[Traverse] #3 = 0
[Traverse] #4 = 0
[Traverse] #5 = 0
[Traverse] #6 = 0
[Traverse] #7 = 0
[Traverse] #8 = 0
[Traverse] #9 = 0
-------------------
*/