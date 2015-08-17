//
//    class_static.cpp
//
//    Demonstration on static variable & function.
//
//    10:06 PM, Aug 17, 2015, by Mighten Dai<mighten.dai@gmail.com>
//
#include <iostream>

using namespace std;

/////////////////////////////////////////////////////////////////////
class    DEMO_static
{
private:
    static unsigned int    m_obj_counter;

public:
	DEMO_static() { ++DEMO_static::m_obj_counter; }
	static unsigned int    get_counter();
};

// It is rather important,
//   without it will trigger an :
//  error LNK2001: unresolved external symbol "private: static unsigned int DEMO_static::m_obj_counter" (?m_obj_counter@DEMO_static@@0IA)
unsigned int DEMO_static::m_obj_counter = 0;


/////////////////////////////////////////////////////////////////////
unsigned int    DEMO_static::get_counter()
{
	return m_obj_counter;
//   Remain immutable
// 01151023  mov      eax,dword ptr [DEMO_static::m_obj_counter (115336Ch)]  
}
/////////////////////////////////////////////////////////////////////
int main( void )
{
	unsigned int   counter = 0;

    DEMO_static    t1;
	counter = t1.get_counter();
	cout << counter << endl;

	DEMO_static    t2;
	counter = t1.get_counter();
	cout << counter << endl;

	DEMO_static    t3;
	counter = t3.get_counter();
	cout << counter << endl;

	DEMO_static    t4;
	counter = t2.get_counter();
	cout << counter << endl;
	counter = t4.get_counter();
	cout << counter << endl;

	return 0;
}

/*
Portray onscreen:
---------------------
1
2
3
4
4
---------------------
*/