//
//    demo.cpp
//
//    The codes contain main()
//
//    09:44 PM, Aug 11, 2015, by Mighten Dai <mighten.dai@gmail.com>
//
#include <string>
#include <iostream>

#include "stock.h"

using namespace std;

int main()
{
	Stock    Mr_Tom;

	// Share numbers tests
	Mr_Tom.set_num( 0L );   // Poor Mr. Tom
	cout << "Now, Mr. Tom has " << Mr_Tom.get_num() << " shares of stocks." << endl;

	Mr_Tom.set_num( 100000L );   // Rich Mr. Tom
	cout << "Now, Mr. Tom has " << Mr_Tom.get_num() << " shares of stocks." << endl;

	return 0;
}