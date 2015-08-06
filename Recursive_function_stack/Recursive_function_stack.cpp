//
//    Recursive_function_stack.cpp
//
//    Demonstrate the stack balancing of a recursive function
//    05:24 AM, Aug 07, 2015, by Mighten Dai <mighten.dai@gmail.com>
//
#include <cstdio>
using namespace std;

unsigned int counter = 0;

//  Recursive function
int  test(int index)
{
	printf("After execution, counter = %u\n", ++counter );

	return index?test(index - 1):0;
//   Recursive codes
//
//  Check patameter:
// 00EB1026  cmp         dword ptr [index],0  
// 00EB102A  je          test+40h (0EB1040h) --\ 
// 00EB102C  mov         edx,dword ptr [index]  |
// 00EB102F  sub         edx,1                  |
//                                              |
//   (index-1) as param, recursive call         |
// 00EB1032  push        edx                    |
// 00EB1033  call        test (0EB1000h)        |
// 00EB1038  add         esp,4                  |
//                                              |
// 00EB103B  mov         dword ptr [ebp-4],eax  |
// 00EB103E  jmp         test+47h (0EB1047h) ---|-----\
//                                              |     |
//  if param =0, change return value=0          |     |
// 00EB1040  mov         dword ptr [ebp-4],0 ---/     |
//                                                    |
// 00EB1047  mov         eax,dword ptr [ebp-4] -------/
// 00EB104A  mov         esp,ebp  
// 00EB104C  pop         ebp  ;; [ebp], while [ebp-4] leaves last calling hierarchy to process. 
// 00EB104D  ret  

}

int main(void)
{
	test(2);

	getchar();
	getchar();

	return 0;
}

/*
test:
----------------------
00EB1000 55                   push        ebp  
00EB1001 8B EC                mov         ebp,esp  
00EB1003 51                   push        ecx  
00EB1004 A1 6C 33 EB 00       mov         eax,dword ptr [counter (0EB336Ch)]  
00EB1009 83 C0 01             add         eax,1  
00EB100C A3 6C 33 EB 00       mov         dword ptr [counter (0EB336Ch)],eax  
00EB1011 8B 0D 6C 33 EB 00    mov         ecx,dword ptr [counter (0EB336Ch)]  
00EB1017 51                   push        ecx  
00EB1018 68 F4 20 EB 00       push        offset ___xi_z+30h (0EB20F4h)  
00EB101D FF 15 A4 20 EB 00    call        dword ptr [__imp__printf (0EB20A4h)]  
00EB1023 83 C4 08             add         esp,8  
00EB1026 83 7D 08 00          cmp         dword ptr [index],0  
00EB102A 74 14                je          test+40h (0EB1040h)  
00EB102C 8B 55 08             mov         edx,dword ptr [index]  
00EB102F 83 EA 01             sub         edx,1  
00EB1032 52                   push        edx  
00EB1033 E8 C8 FF FF FF       call        test (0EB1000h)  
00EB1038 83 C4 04             add         esp,4  
00EB103B 89 45 FC             mov         dword ptr [ebp-4],eax  
00EB103E EB 07                jmp         test+47h (0EB1047h)  
00EB1040 C7 45 FC 00 00 00 00 mov         dword ptr [ebp-4],0  
00EB1047 8B 45 FC             mov         eax,dword ptr [ebp-4]  
00EB104A 8B E5                mov         esp,ebp  
00EB104C 5D                   pop         ebp  
00EB104D C3                   ret  
----------------------
*/



/*
Trace log:
----------------------
00EB1050  push        ebp  
00EB1051  mov         ebp,esp  
00EB1053  push        2  
00EB1055  call        test (0EB1000h)  

test (0EB1000h):
00EB1000  push        ebp  
00EB1001  mov         ebp,esp  
00EB1003  push        ecx  
00EB1004  mov         eax,dword ptr [counter (0EB336Ch)]  
00EB1009  add         eax,1  
00EB100C  mov         dword ptr [counter (0EB336Ch)],eax  
00EB1011  mov         ecx,dword ptr [counter (0EB336Ch)]  
00EB1017  push        ecx  
00EB1018  push        offset ___xi_z+30h (0EB20F4h)  
00EB101D  call        dword ptr [__imp__printf (0EB20A4h)]  
00EB1023  add         esp,8  
00EB1026  cmp         dword ptr [index],0  
00EB102A  je          test+40h (0EB1040h)  
00EB102C  mov         edx,dword ptr [index]  
00EB102F  sub         edx,1  
00EB1032  push        edx  
00EB1033  call        test (0EB1000h)  

00EB1000  push        ebp  
00EB1001  mov         ebp,esp  
00EB1003  push        ecx  
00EB1004  mov         eax,dword ptr [counter (0EB336Ch)]  
00EB1009  add         eax,1  
00EB100C  mov         dword ptr [counter (0EB336Ch)],eax  
00EB1011  mov         ecx,dword ptr [counter (0EB336Ch)]  
00EB1017  push        ecx  
00EB1018  push        offset ___xi_z+30h (0EB20F4h)  
00EB101D  call        dword ptr [__imp__printf (0EB20A4h)]  
00EB1023  add         esp,8  
00EB1026  cmp         dword ptr [index],0  
00EB102A  je          test+40h (0EB1040h)  
00EB102C  mov         edx,dword ptr [index]  
00EB102F  sub         edx,1  
00EB1032  push        edx  
00EB1033  call        test (0EB1000h)  

00EB1000  push        ebp  
00EB1001  mov         ebp,esp  
00EB1003  push        ecx  
00EB1004  mov         eax,dword ptr [counter (0EB336Ch)]  
00EB1009  add         eax,1  
00EB100C  mov         dword ptr [counter (0EB336Ch)],eax  
00EB1011  mov         ecx,dword ptr [counter (0EB336Ch)]  
00EB1017  push        ecx  
00EB1018  push        offset ___xi_z+30h (0EB20F4h)  
00EB101D  call        dword ptr [__imp__printf (0EB20A4h)]  
00EB1023  add         esp,8  
00EB1026  cmp         dword ptr [index],0  
00EB102A  je          test+40h (0EB1040h)  

00EB1040  mov         dword ptr [ebp-4],0  
00EB1047  mov         eax,dword ptr [ebp-4]  
00EB104A  mov         esp,ebp  
00EB104C  pop         ebp  
00EB104D  ret  

00EB1038  add         esp,4  
00EB103B  mov         dword ptr [ebp-4],eax  
00EB103E  jmp         test+47h (0EB1047h)  
00EB1040  mov         dword ptr [ebp-4],0  
00EB1047  mov         eax,dword ptr [ebp-4]  
00EB104A  mov         esp,ebp  
00EB104C  pop         ebp  
00EB104D  ret  

00EB1038  add         esp,4  
00EB103B  mov         dword ptr [ebp-4],eax  
00EB103E  jmp         test+47h (0EB1047h)  
00EB1040  mov         dword ptr [ebp-4],0  
00EB1047  mov         eax,dword ptr [ebp-4]  
00EB104A  mov         esp,ebp  
00EB104C  pop         ebp  
00EB104D  ret  

00EB105A  add         esp,4  
00EB105D  call        dword ptr [__imp__getchar (0EB209Ch)]  
00EB1063  call        dword ptr [__imp__getchar (0EB209Ch)]  
00EB1069  xor         eax,eax  
00EB106B  pop         ebp  
00EB106C  ret  
----------------------
*/