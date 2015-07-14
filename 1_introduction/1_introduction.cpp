//    1_Introduction.cpp
//
//    This is a deliberate to demonstrate how 
//        C++ and ASM as well as C are connected.
//
//    Mighten Dai
//    21:57
//    Jul 13, 2015
//
//
// ---Part 1: Basic structures( Empty Compilation )

/////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

int main( void )
{
	// TODO: Nothing but demonstrate the code assembled.

	return 0;
}
////////////////////////////////////////////////////////////
//
//  As you can see, VS2010 is very powerful, the result of compilation are as following.

/*
==============================================================
     The Release Version
--------------------------------------------------------------
00141000  xor         eax,eax    \  Actually, the effective codes are merely this.
00141002  ret                    /


==============================================================
     The Debug Version
--------------------------------------------------------------
// 012B1350  push        ebp                \
// 012B1351  mov         ebp,esp            |
// 012B1353  sub         esp,0C0h           |
// 012B1359  push        ebx                |
// 012B135A  push        esi                |    After Disassembling several times,
// 012B135B  push        edi                |     you will become pretty familar with these
// 012B135C  lea         edi,[ebp-0C0h]     |        initialization codes.
// 012B1362  mov         ecx,30h            |
// 012B1367  mov         eax,0CCCCCCCCh     |   This codes are filling int 0x3 ( 0xCC ) into the stack,
// 012B136C  rep stos    dword ptr es:[edi] /       which could avoid commiting undue code-executing mistakes.

// 012B136E  xor         eax,eax  

// 012B1370  pop         edi           \
// 012B1371  pop         esi           |
// 012B1372  pop         ebx           |
// 012B1373  mov         esp,ebp       |
// 012B1375  pop         ebp           /

// 012B1376  ret
==============================================================
*/
