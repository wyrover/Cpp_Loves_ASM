//
//    new_delete.cpp
//
//    The following section includes:
//      > dynamic variable
//      > dynamic variable array
//      > dynamic struct array
//      > Differences as well as similarities existed between C and C++
//
//    09:00, Aug 06, 2015, by Mighten Dai<mighten.dai@gmail.com>
//
//     Conclusion:  The malloc/free use partly the same codes as new/delete use.
//
//     Sorry: I disassembed the file for several times,
//             it is no wonder that the memory address existed a "leap"
//
// 
//////////////////////////////////////////////////////////////////////////////////////
// In an other External experiment,  I'll demonstrate how it would be if an "Memory Leak" occures

#include <cstdlib>

using namespace std;

// Dynamic structure.
struct Students
{
	unsigned int     student_ID;
	unsigned int     age;
	unsigned int     academic_performance;
}  *p_student = NULL;

// Pair the     malloc/free   &   new/delete

//   Once a memory space is allocated, we must release it, or cause "Memory Leak"

// One runtime entry address = 00AD1000h
int main(void)
{
	unsigned int    *p_i = NULL;

	//  Allocate traditionally
	p_i = (unsigned int *)malloc( sizeof(unsigned int) );  //  get 0x004A2BA8, irrelevant to the Program address
	*p_i = 0;
	free( p_i );  // EAX == 00000001

	// Now, try the new approach
	p_i = new unsigned int; // 004A2BA8
	delete p_i; // EAX == 00000001

	// also the dynamic array
	p_i = new unsigned int[10]; // 004A2BA8
	delete [] p_i; // EAX == 00000001

	//	finally comes the dynamic structure.
	p_student = new struct Students[5];
	p_student[0].student_ID = 0;
	p_student[1].age = 18;
	p_student[2].academic_performance = 100;
	delete [] p_student;

	// External test:
	//   Base address of this module = 003B10D0
	p_student = new struct Students[100]; // 00182BA8
	p_i = new unsigned int [10];          // 00183070 !=  00182BA8 + 64     ( Hexadecimal 64 is Decimal 100 )

	delete [] p_i;
	delete [] p_student;

	return 0;
}

/*
// These address mismatch to the entry address.

__imp_malloc:
------------------------
66580233  mov         edi,edi  
66580235  push        ebp  
66580236  mov         ebp,esp  
66580238  push        ebx  
66580239  mov         ebx,dword ptr [ebp+8]  
6658023C  cmp         ebx,0FFFFFFE0h  
6658023F  ja          665AF26F  
66580245  push        esi  
66580246  push        edi  
66580247  cmp         dword ptr ds:[666248B0h],0  
6658024E  je          665AF227  
66580254  test        ebx,ebx  
66580256  je          66580282  
66580258  mov         eax,ebx  
6658025A  push        eax  
6658025B  push        0  
6658025D  push        dword ptr ds:[666248B0h]  
66580263  call        dword ptr ds:[665711F8h]  
66580269  mov         edi,eax  
6658026B  test        edi,edi  
6658026D  je          665AF241  
66580273  mov         eax,edi  
66580275  pop         edi  
66580276  pop         esi  
66580277  pop         ebx  
66580278  pop         ebp  
66580279  ret  
------------------------

__imp_free:
-------------
6658014E  mov         edi,edi  
66580150  push        ebp  
66580151  mov         ebp,esp  
66580153  cmp         dword ptr [ebp+8],0  
66580157  je          66580172  
66580159  push        dword ptr [ebp+8]  
6658015C  push        0  
6658015E  push        dword ptr ds:[666248B0h]  
66580164  call        dword ptr ds:[665711FCh]
6658016A  test        eax,eax  
6658016C  je          665AF288  
66580172  pop         ebp  
66580173  ret  
-------------

__imp_operator new:
-------------------------
6658232B  mov         edi,edi  
6658232D  push        ebp  
6658232E  mov         ebp,esp  
66582330  sub         esp,10h  
66582333  push        dword ptr [ebp+8]  
66582336  call        66580233      // call to __imp_malloc
6658233B  pop         ecx  
6658233C  test        eax,eax  
6658233E  je          665AF2A5  
66582344  leave  
66582345  ret  
-------------------------

__imp_operator delete:
------------
6658014E  mov         edi,edi  
66580150  push        ebp  
66580151  mov         ebp,esp  
66580153  cmp         dword ptr [ebp+8],0  
66580157  je          66580172  
66580159  push        dword ptr [ebp+8]  
6658015C  push        0  
6658015E  push        dword ptr ds:[666248B0h]  
66580164  call        dword ptr ds:[665711FCh]      // Remain fixed to imp_malloc
6658016A  test        eax,eax  
6658016C  je          665AF288  
66580172  pop         ebp  
66580173  ret  
66580174  mov         edi,edi  
    --->>>>> Module Entry
66580176  push        ebp  
66580177  mov         ebp,esp  
66580179  pop         ebp  
6658017A  jmp         6658014E 
------------
*/