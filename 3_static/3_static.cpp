//
//     3_static.cpp
//
//  Part 3: static
//  TODO: Illustrate why could static variable's value can remain fixed in memory 
//
//    Mighten Dai <mighten.dai@gmail.com>
//      20:47   ~ 21:26
//		July 15, 2015
//
#include <iostream>

using namespace std;

////////////////////
int static_test( void)
{
	static  int test_static_var = 0;
	return test_static_var++;
}

////////////////////
int nonstatic_test( void)
{
	int test_non_static_var = 0;
	return test_non_static_var++;
}

int main( void)
{
	printf( "#1: static test = %d\n", static_test() );
	printf( "#2: static test = %d\n", static_test() );
	printf( "#3: non-static test = %d\n", nonstatic_test() );
	printf( "#4: non-static test = %d\n", nonstatic_test() );

	return 0;
}


/*
========================================================
Output:
-----------------------------------------
#1: static test = 0
#2: static test = 1
#3: non-static test = 0
#4: non-static test = 0
Press any key to continue. . .
-----------------------------------------
Illustration:
	From the following codes disassemblied by MSVS, we
	    can easily knows that:
	<1>   Static variable was operated directly in a constant memory space.
	<2>   nonstatic one was operated via stack, which cannot modify its initial value.

////////////////////////////////////////////////////////////////
Disassembly by MSVS2010
////////////////////////////////////////////////////////////////
int static_test( void)
{
01161000  push        ebp  
01161001  mov         ebp,esp  
01161003  push        ecx  
	static  int test_static_var = 0;
	return test_static_var++;
01161004  mov         eax,dword ptr [test_static_var (116336Ch)] ; a constant memory space.s
01161009  mov         dword ptr [ebp-4],eax  
0116100C  mov         ecx,dword ptr [test_static_var (116336Ch)]  
01161012  add         ecx,1  
01161015  mov         dword ptr [test_static_var (116336Ch)],ecx  
0116101B  mov         eax,dword ptr [ebp-4]  
}
0116101E  mov         esp,ebp  
01161020  pop         ebp  
01161021  ret  

////////////////////
int nonstatic_test( void)
{
01161030  push        ebp  
01161031  mov         ebp,esp  
01161033  sub         esp,8  
	int test_non_static_var = 0;
01161036  mov         dword ptr [test_non_static_var],0  
	return test_non_static_var++;
0116103D  mov         eax,dword ptr [test_non_static_var]  
01161040  mov         dword ptr [ebp-8],eax                ; [ EBP - 8 ]  as  test_non_static_var 
01161043  mov         ecx,dword ptr [test_non_static_var]  
01161046  add         ecx,1  							   ; test_non_static_var++ means: first use, later change
01161049  mov         dword ptr [test_non_static_var],ecx  ;   so use ECX to increase.  
0116104C  mov         eax,dword ptr [ebp-8]  		       ;   But the return value was still stored in EAX
}
0116104F  mov         esp,ebp  
01161051  pop         ebp  
01161052  ret  

========================================================
Hard to grasp why it is written complexily
 In my view, the nonstatic_test should be written as following:

/////////////////////
int nonstatic_test( void)
{
	int test_non_static_var = 0;
xor		eax, eax
push	eax					;  Allocate variable, Initialization

	return test_non_static_var++;
pop		eax
}
ret  
*/