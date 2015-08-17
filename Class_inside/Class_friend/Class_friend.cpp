//
//    Class_friend.cpp
//
//    Using Friend within class
//
//    09:32, Aug 17, 2015, by Mighten Dai<mighten.dai@gmail.com>
//
#include <iostream>
#include "..\..\00000_Coding_suggestion\trace_mark.h"

using namespace std;

/////////////////////////////////////////////////////
class  Friend_class
{
private:
	int   m_MarkA;
	int   m_MarkB;

public:
	Friend_class( int MarkA = 0, int MarkB = 0){  m_MarkA = MarkA; m_MarkB=MarkB;}
	~Friend_class() {}

	// 
	friend  ostream & operator << ( ostream & stream, Friend_class & outprint );
};

/////////////////////////////////////////////////////
//        Overload operator << to accomplish output
//  *** Friend_class::operator is a wrong notation
ostream &    operator << ( ostream & stream,   Friend_class & outprint )
{
	stream << "==================================" << endl;
	stream << "Mark A = " << outprint.m_MarkA << endl;
	stream << "Mark B = " << outprint.m_MarkB << endl;
	stream << "==================================" << endl;

	return stream;
}



int main( void )
{
	TraceMark(0xAAAAAAAA);
	TraceMark(0xAAAAAAAA);
	TraceMark(0xAAAAAAAA);

	Friend_class  test_1 = Friend_class(10, 20);
// 01211194  push        14h               ;; 20
// 01211196  push        0Ah               ;; 10
// 01211198  lea         ecx,[ebp-14h]     ;; this <- offset test_1
// 0121119B  call        Friend_class::Friend_class (1211070h)  
// 012111A0  mov         dword ptr [ebp-4],0  

	TraceMark(0xAAAAAAAA);
	TraceMark(0xAAAAAAAA);
	TraceMark(0xAAAAAAAA);

	Friend_class  test_2( 30, 50 );
// 012111B6  push        32h     ;; 50  
// 012111B8  push        1Eh     ;; 30
// 012111BA  lea         ecx,[ebp-1Ch]        ;; this <- offset test_2
// 012111BD  call        Friend_class::Friend_class (1211070h)  
// 012111C2  mov         byte ptr [ebp-4],1  

	TraceMark(0xAAAAAAAA);
	TraceMark(0xAAAAAAAA);
	TraceMark(0xAAAAAAAA);

	cout << "Now show onscreen..." << endl;
	cout << "  First, the obj test_1:" << endl;
	cout << test_1;

	cout << endl;
	cout << endl;

	cout << "  Next, the obj test_2:" << endl;
	cout << test_2;
 
	return 0;
}

/*
Output:
---------------------------
Now show onscreen...
  First, the obj test_1:
==================================
Mark A = 10
Mark B = 20
==================================


  Next, the obj test_2:
==================================
Mark A = 30
Mark B = 50
==================================
---------------------------
*/