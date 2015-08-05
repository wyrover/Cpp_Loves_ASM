///////////////////////////////////////////////////////////////
//    2_arithmetic.cpp
//
//    This is a deliberate to demonstrate how 
//        C++ and ASM as well as C are connected.
//
//    Mighten Dai
//    22:32
//    Jul 13, 2015
//
///////////////////////////////////////////////////////////////
// ---Part 2: Arithmetic operations

#include <iostream>

using namespace std;

int main(void)
{
	// the unsigned integer
	unsigned int   ui_arg_1;
	unsigned int   ui_arg_2;
	unsigned int   ui_result = 0;

	// the signed integer
	signed int  si_arg_1;
	signed int  si_arg_2;
	signed int  si_result = 0;

	// the floating point number
	float   f_arg_1;
	float   f_arg_2;
	float   f_result = 0;

	// the others types
	long int		li_test = 0;
	long long int	lli_test = 0;
	bool			b_test = 0;
	char			c_test = 0;

	///////////////////////////////////////////////////
	// the unsigned integer operations
	ui_arg_1 = 10;
	ui_arg_2 = 5;
	ui_result = ui_arg_1 + ui_arg_2;
	ui_result = ui_arg_1 - ui_arg_2;
	ui_result = ui_arg_1 * ui_arg_2;
	ui_result = ui_arg_1 / ui_arg_2;
	ui_result = ui_arg_1 % ui_arg_2;

	///////////////////////////////////////////////////
	// the signed integer operations
	si_arg_1 = -10;
	si_arg_2 = -5;
	si_result = si_arg_1 + si_arg_2;
	si_result = si_arg_1 - si_arg_2;
	si_result = si_arg_1 * si_arg_2;
	si_result = si_arg_1 / si_arg_2;
	si_result = si_arg_1 % si_arg_2;

	// the floating point number operations
	f_arg_1 = 2.43E+7; // 2.43 times 10 to plus 7
	f_arg_2 = 1.62E-5; // 1.62 times 10 to minus 5
	f_result = f_arg_1 + f_arg_2;
	f_result = f_arg_1 - f_arg_2;
	f_result = f_arg_1 * f_arg_2;
	f_result = f_arg_1 / f_arg_2;

	// the others types operations
	li_test = 0xFFFFffffFFFFffff;
	lli_test = 0xFFFFffffFFFFffff;
	b_test = 0;
	b_test = 1;
	c_test = 'A';

	return 0;
}

/*
The corresponding codes.    -- Release Version Compiled by MS Visual Studio 2010 
-------------------------------
	int main(void)
	{
00A01000  push        ebp
00A01001  mov         ebp,esp
00A01003  sub         esp,38h

		// the unsigned integer
		unsigned int   ui_arg_1;
		unsigned int   ui_arg_2;
		unsigned int   ui_result = 0;
00A01006  mov         dword ptr [ui_result],0

		// the signed integer
		signed int  si_arg_1;
		signed int  si_arg_2;
		signed int  si_result = 0;
00A0100D  mov         dword ptr [si_result],0

		// the floating point number
		float   f_arg_1;
		float   f_arg_2;
		float   f_result = 0;
00A01014  fldz  
00A01016  fstp        dword ptr [f_result]

		// the others types
		long int		li_test = 0;
00A01019  mov         dword ptr [li_test],0  

		long long int	lli_test = 0;
00A01020  mov         dword ptr [lli_test],0  
00A01027  mov         dword ptr [ebp-1Ch],0 

		bool			b_test = 0;
00A0102E  mov         byte ptr [b_test],0  

		char			c_test = 0;
00A01032  mov         byte ptr [c_test],0  

		///////////////////////////////////////////////////
		// the unsigned integer operations
		ui_arg_1 = 10;
00A01036  mov         dword ptr [ui_arg_1],0Ah  

		ui_arg_2 = 5;
00A0103D  mov         dword ptr [ui_arg_2],5  

		ui_result = ui_arg_1 + ui_arg_2;
00A01044  mov         eax,dword ptr [ui_arg_1]  
00A01047  add         eax,dword ptr [ui_arg_2]  
00A0104A  mov         dword ptr [ui_result],eax

		ui_result = ui_arg_1 - ui_arg_2;
00A0104D  mov         ecx,dword ptr [ui_arg_1]  
00A01050  sub         ecx,dword ptr [ui_arg_2]  
00A01053  mov         dword ptr [ui_result],ecx

		ui_result = ui_arg_1 * ui_arg_2;
00A01056  mov         edx,dword ptr [ui_arg_1]  
00A01059  imul        edx,dword ptr [ui_arg_2]  
00A0105D  mov         dword ptr [ui_result],edx  

		ui_result = ui_arg_1 / ui_arg_2;
00A01060  mov         eax,dword ptr [ui_arg_1]  
00A01063  xor         edx,edx  
00A01065  div         eax,dword ptr [ui_arg_2]  
00A01068  mov         dword ptr [ui_result],eax  

		ui_result = ui_arg_1 % ui_arg_2;
00A0106B  mov         eax,dword ptr [ui_arg_1]  
00A0106E  xor         edx,edx  
00A01070  div         eax,dword ptr [ui_arg_2]  
00A01073  mov         dword ptr [ui_result],edx 

		///////////////////////////////////////////////////
		// the signed integer operations
		si_arg_1 = -10;
00A01076  mov         dword ptr [si_arg_1],0FFFFFFF6h  

		si_arg_2 = -5;
00A0107D  mov         dword ptr [si_arg_2],0FFFFFFFBh 

		si_result = si_arg_1 + si_arg_2;
00A01084  mov         eax,dword ptr [si_arg_1]  
00A01087  add         eax,dword ptr [si_arg_2]  
00A0108A  mov         dword ptr [si_result],eax  

		si_result = si_arg_1 - si_arg_2;
00A0108D  mov         ecx,dword ptr [si_arg_1]  
00A01090  sub         ecx,dword ptr [si_arg_2]  
00A01093  mov         dword ptr [si_result],ecx  

		si_result = si_arg_1 * si_arg_2;
00A01096  mov         edx,dword ptr [si_arg_1]  
00A01099  imul        edx,dword ptr [si_arg_2]  
00A0109D  mov         dword ptr [si_result],edx  

		si_result = si_arg_1 / si_arg_2;
00A010A0  mov         eax,dword ptr [si_arg_1]  
00A010A3  cdq  
00A010A4  idiv        eax,dword ptr [si_arg_2]  
00A010A7  mov         dword ptr [si_result],eax  

		si_result = si_arg_1 % si_arg_2;
00A010AA  mov         eax,dword ptr [si_arg_1]  
00A010AD  cdq  
00A010AE  idiv        eax,dword ptr [si_arg_2]  
00A010B1  mov         dword ptr [si_result],edx  

		// the floating point number operations
		f_arg_1 = 2.43E+7; // 2.43 times 10 to plus 7
00A010B4  fld         dword ptr [__real@4bb964f0 (0A020E8h)]  ; f0 64 b9 4b
00A010BA  fstp        dword ptr [f_arg_1]  

		f_arg_2 = 1.62E-5; // 1.62 times 10 to minus 5
00A010BD  fld         dword ptr [__real@3787e53c (0A020E4h)]  ;3c e5 87 37
00A010C3  fstp        dword ptr [f_arg_2]  

		f_result = f_arg_1 + f_arg_2;
00A010C6  fld         dword ptr [f_arg_1]  
00A010C9  fadd        dword ptr [f_arg_2]  
00A010CC  fstp        dword ptr [f_result]  

		f_result = f_arg_1 - f_arg_2;
00A010CF  fld         dword ptr [f_arg_1]  
00A010D2  fsub        dword ptr [f_arg_2]  
00A010D5  fstp        dword ptr [f_result]  

		f_result = f_arg_1 * f_arg_2;
00A010D8  fld         dword ptr [f_arg_1]  
00A010DB  fmul        dword ptr [f_arg_2]  
00A010DE  fstp        dword ptr [f_result]  

		f_result = f_arg_1 / f_arg_2;
00A010E1  fld         dword ptr [f_arg_1]  
00A010E4  fdiv        dword ptr [f_arg_2]  
00A010E7  fstp        dword ptr [f_result]  

		// the others types operations
		li_test = 0xFFFFffffFFFFffff;
00EF10EA  mov         dword ptr [li_test],0FFFFFFFFh  

		lli_test = 0xFFFFffffFFFFffff;
00EF10F1  mov         dword ptr [lli_test],0FFFFFFFFh  
00EF10F8  mov         dword ptr [ebp-1Ch],0FFFFFFFFh 

		b_test = 0;
00A010FF  mov         byte ptr [b_test],0  

		b_test = 1;
00A01103  mov         byte ptr [b_test],1  

		c_test = 'A';
00A01107  mov         byte ptr [c_test],41h  

		return 0;
00A0110B  xor         eax,eax  

	}
00A0110D  mov         esp,ebp  
00A0110F  pop         ebp  
00A01110  ret  
-------------------------------
*/