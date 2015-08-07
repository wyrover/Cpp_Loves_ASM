//
//    by_Reference.cpp
//
//    Demonstrate how Reference is implemented.
//
//    07:39 PM, August 07, 2015, by Mighten Dai <mighten.dai@gmail.com>
//

// The reference is naturally a pointer,
//    but compiler illustrate the reference's address as the value stored in ref_a,
//       while do the same thing on pointer get the actual address of pointer.

#include <iostream>

using namespace std;

int  swap_pt( int *param1, int *param2 )
{
	int   temp = *param1;

	*param1 = *param2;
	*param2 = temp;

	return 0;
}

int  swap_ref( int & param1, int & param2, int & place_holder )
{
	int   temp = param1;

	param1 = param2;
	param2 = temp;
	place_holder = 0;

	return 0;
}


int main(void )
{
	int a = 10, b = 20, c= 30;
	int & ref_a = a;
// 0082107B  lea         eax,[a]  
// 0082107E  mov         dword ptr [ref_a],eax  

	int & ref_b = b;
// 00821081  lea         ecx,[b]  
// 00821084  mov         dword ptr [ref_b],ecx  

	int & ref_c = c;
// 00821087  lea         edx,[c]  
// 0082108A  mov         dword ptr [ref_c],edx  


	swap_pt(  &a, &b );
// 0082108D  lea         eax,[b]  
// 00821090  push        eax  
// 00821091  lea         ecx,[a]  
// 00821094  push        ecx  
// 00821095  call        swap_pt (821000h)  
// 0082109A  add         esp,8  

	swap_ref( c, b, a  );
// 0082109D  lea         edx,[a]  
// 008210A0  push        edx  
// 008210A1  lea         eax,[b]  
// 008210A4  push        eax  
// 008210A5  lea         ecx,[c]  
// 008210A8  push        ecx  
// 008210A9  call        swap_ref (821030h)  
// 008210AE  add         esp,0Ch  

	//////////////////////////////////////////////////
	//   External experiment: print ref-var address
	cout << "Address of ref_a is "<< &ref_a << ", and of a is " << &a << endl;
//  Irrelevant info was omitted.
// -----> Get variable a's address
// 00EA1128  lea         eax,[a]
// -----> Get address of Reference
// 00EA1131  mov         ecx,dword ptr [ref_a]

	//////////////////////////////////////////////////
	//   External experiment: print pointer's address
	//    Contrast to the Reference's Same work
	int * pa = &a;
	cout << "Address of pa is "<< &pa << ", and of a is " << &a << endl;
// -----> Get variable a's address
// 01181177  lea         edx,[a]  

// -----> Get address of pointer pointed to a
// 01181180  lea         eax,[pa]  

	return 0;
}

/*
output:
------------
Address of ref_a is 001DFB6C, and of a is 001DFB6C
Address of pa is 001DFB68, and of a is 001DFB6C
------------
*/