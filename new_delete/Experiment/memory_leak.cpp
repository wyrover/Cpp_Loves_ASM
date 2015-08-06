//
//   memory_leak.cpp
//
//   Demonstrate how it would be if an memory leak occures.
//
//    09:50, Aug 06, 2015, by Mighten Dai<mighten.dai@gmail.com>
//

#include <cstdlib>

using namespace std;

int main(void )
{
	for (;;)
	{
		int *p_i = new int [10];
	}

	return 0;
}
/*

Unhandled exception at 0x75d7812f in test.exe: Microsoft C++ exception: std::bad_alloc at memory location 0x001efb58..

*/