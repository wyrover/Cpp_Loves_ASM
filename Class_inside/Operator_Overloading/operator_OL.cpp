//
//  Operator_OL.cpp
//
//      Operator Overloading
//
//  10:41 PM, Aug 14, 2015, by Mighten Dai<mighten.dai@gmail.com>
//

#include <iostream>
using namespace std;

#include "Operator_OL.h"

int main( )
{
	Time  time1 = Time( 12, 30, 0); // 12:30:00
	Time  time2; // 00:00:00
	
	cout << "--------------------------------"<< endl;
	cout << "Initially" << endl;
	time1.show();
	time2.show();

	cout << "--------------------------------"<< endl;
	cout << "After time2--" << endl;
	time2--;
	time2.show();

	cout << "--------------------------------"<< endl;
	cout << "After time1++" << endl;
	time1++;
	time1.show();

	return 0;
}

/*
Display
=========================================================
--------------------------------
Initially
#12:30:0
#0:0:0
--------------------------------
After time2--
#23:59:59
--------------------------------
After time1++
#12:30:1
=========================================================
*/