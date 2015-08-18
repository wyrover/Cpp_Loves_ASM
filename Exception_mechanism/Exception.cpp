//
//  Exception.cpp
//
//  The implementation of C++ Exception mechanism.
//
//  09:22 AM, Aug 18, 2015, by Mighten Dai<mighten.dai@gmail.com>
//
#include <iostream>

using namespace std;

#define     TraceMark(x)    __asm  mov eax, x;

//////////////////////////////////////////////////////////////////////
int    div_test( int dividend, int divisor )
{
	if  ( !divisor )
	{
		TraceMark(0x55AA55AA);
		TraceMark(0x55AA55AA);
		throw  "[Runtime Error]: The divisor in division cannot be zero.";
// 00AE1084  mov         dword ptr [ebp-4],offset type_info::`vftable'+0Ch (0AE314Ch)  
// 00AE108B  push        offset __TI2PAD (0AE33C8h)  
// 00AE1090  lea         eax,[ebp-4]  
// 00AE1093  push        eax  
// 00AE1094  call        _CxxThrowException (0AE2360h)
		TraceMark(0x55AA55AA);
		TraceMark(0x55AA55AA);
	}

	return dividend / divisor;
}

//////////////////////////////////////////////////////////////////////
int main( void )
{
	for ( int i = 2; i > -5; --i )
// 011B10DC  mov         dword ptr [i],2  
// 011B10E3  jmp         main+3Eh (11B10EEh)  
// 011B10E5  mov         eax,dword ptr [i]  
// 011B10E8  sub         eax,1  
// 011B10EB  mov         dword ptr [i],eax  
// 011B10EE  cmp         dword ptr [i],0FFFFFFFBh  
// 011B10F2  jle         $LN10+0Ah (11B121Ah)  
	{

		try{
// 011B10F8  mov         dword ptr [ebp-4],0

			cout << "[Mission] 10 / " << i << '=' << div_test( 10, i ) << endl;
// 011B10FF  mov         ecx,dword ptr [i]  
// 011B1102  push        ecx  
// 011B1103  push        0Ah  
// 011B1105  call        div_test (11B1070h)  
// 011B110A  add         esp,8 

		TraceMark(0x22222222);
		TraceMark(0x22222222);
		}
// 011B1191  jmp         $LN7 (11B1207h)
		catch( const char *error_msg)
		{
			TraceMark(0x33333333);
			TraceMark(0x33333333);
			TraceMark(0x33333333);
			cout << error_msg << endl << "        try again..." << endl;;
			TraceMark(0xAAAAAAAA);
			TraceMark(0xAAAAAAAA);
			continue;
// 011B11EA  mov         dword ptr [ebp-4],0FFFFFFFFh  
// 011B11F1  mov         eax,offset $LN10 (11B1210h)  
// 011B11F6  ret  

			TraceMark(0xAAAAAAAA);
			TraceMark(0xAAAAAAAA);
		}
	}

	cout << " Mission done, exit" << endl;

	return 0;
}

/*
Portray onscreen:
-----------------------------------
[Mission] 10 / 2=5
[Mission] 10 / 1=10
[Runtime Error]: The divisor in division cannot be zero.
        try again...
[Mission] 10 / -1=-10
[Mission] 10 / -2=-5
[Mission] 10 / -3=-3
[Mission] 10 / -4=-2
 Mission done, exit
-----------------------------------


Continue tracking...
_CxxThrowException:
00AE2360  jmp         dword ptr [__imp___CxxThrowException@8 (0AE30F4h)]  
    But continue tracking triggered an Access Violation.

	    Stop
*/