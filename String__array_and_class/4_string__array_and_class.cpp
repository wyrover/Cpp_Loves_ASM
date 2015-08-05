//
//     4_string__array_and_class.cpp
//
//  Part 4: String representation: array and class
//
//  TODO: Illustrate The implification of string representation.
//
//  * Notion: The Disassembly is arranged according to executing sequence,
//				instead of the memory space.
//
//		Begin:   11:49, July 16, 2015     Signed-off-by: Mighten Dai <mighten.dai@gmail.com>
//    Latest Modification:   19:03, July 16, 2015     Signed-off-by: Mighten Dai <mighten.dai@gmail.com>
//
//
#include <iostream>
#include <string>

using namespace std;

int main( void )
{
////////////////////////////////////////////////////////////////////////
// Address From 00DE1140 to 00DE1167(Codes), compiler's initialization,
//			Some information was summed up as following,
//			May it is useful later     :)
//				in understanding how & why compiler did so
//
//   Current fs = 0x003B, or (111_0_11) in Binary, 
//				Index = 0x7, Table Indicator = 0x0(in GDT), RPL = 0x3
//     The fs is not set by the compiler
//			it specifies the Windows 7's sepcial segment descriptor in GDT 

/////////////////////////////////////////////////////////////////////////
	unsigned int index = 0;
// 00DE1168  mov         dword ptr [ebp-30h],0  

/////////////////////////////////////////////////////////////////////////
	char	str_array[] = "Hello, C++ and ASM";
//    This is done by MSVS2010 C++ compiler
//		The main work of the following codes is to copy string to stack
//		By looking the memory space, knows  "Hello, C++ and ASM" 
//						are stored between 0x33316C and 0x33317E
//
//		But, eh.....
//		It is really hard to grasp the following questions:
//			1> How [type_info::`vftable'+0Ch (0DE316Ch)] is declared ?
//			2> Why this work is done separately by 3 CPU registers,
//					or rather, EAX, ECX, EDX
// 00DE116F  mov         eax,dword ptr [type_info::`vftable'+0Ch (0DE316Ch)]  
// 00DE1174  mov         dword ptr [ebp-44h],eax  
// 00DE1177  mov         ecx,dword ptr [type_info::`vftable'+10h (0DE3170h)]  
// 00DE117D  mov         dword ptr [ebp-40h],ecx  
// 00DE1180  mov         edx,dword ptr [type_info::`vftable'+14h (0DE3174h)]  
// 00DE1186  mov         dword ptr [ebp-3Ch],edx  
// 00DE1189  mov         eax,dword ptr [type_info::`vftable'+18h (0DE3178h)]  
// 00DE118E  mov         dword ptr [ebp-38h],eax  
// 00DE1191  mov         cx,word ptr [type_info::`vftable'+1Ch (0DE317Ch)]  
// 00DE1198  mov         word ptr [ebp-34h],cx  
// 00DE119C  mov         dl,byte ptr [type_info::`vftable'+1Eh (0DE317Eh)]  
// 00DE11A2  mov         byte ptr [ebp-32h],dl  

/////////////////////////////////////////////////////////////////////////
	string	str_class("Hello, C++ and ASM");
//   By using constructor( ctor for short), it is really smart and neat !!
//   0x0DE3180 is the string "Hello, C++ and ASM"
//      But,  it's really hard to know why:
//				# 02 # | lea	ecx, [ ebp - 0x2C ] 
//				# 04 # | mov    dword ptr [ebp-4],0
//
//      Maybe it is a argument of the function call
//		   Now record its current value of dword [ebp-20c]: 10 2c 26 00
//     
// 00DE11A5  push        offset type_info::`vftable'+20h (0DE3180h)  
// 00DE11AA  lea         ecx,[ebp-2Ch]	      ?????????????			   ; [ebp-2Ch] is [0022F8C0]
// 00DE11AD  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::basic_string<char,std::char_traits<char>,std::allocator<char> > (0DE12A0h)  
// 00DE11B2  mov         dword ptr [ebp-4],0  ????????????????


	// Reset the value inside array
	for ( index = 0;
// 012611B9  mov         dword ptr [ebp-30h],0  

		    index < strlen(str_array) && 
			str_array[index] ;
// 012611C0  jmp         main+8Bh (12611CBh) 
// 012611CB  lea         ecx,[ebp-44h]  
// 012611CE  mov         dword ptr [ebp-4Ch],ecx  
// 012611D1  mov         edx,dword ptr [ebp-4Ch]  
// 012611D4  add         edx,1  

// 012611D7  mov         dword ptr [ebp-50h],edx  
// 012611DA  mov         eax,dword ptr [ebp-4Ch]  
// 012611DD  mov         cl,byte ptr [eax]  
// 012611DF  mov         byte ptr [ebp-51h],cl  
// 012611E2  add         dword ptr [ebp-4Ch],1  
// 012611E6  cmp         byte ptr [ebp-51h],0  
// 012611EA  jne         main+9Ah (12611DAh)  ; 0 != str_array[index], continue the condition check.

// 012611EC  mov         edx,dword ptr [ebp-4Ch]  
// 012611EF  sub         edx,dword ptr [ebp-50h]  
// 012611F2  mov         dword ptr [ebp-58h],edx  
// 012611F5  mov         eax,dword ptr [ebp-30h]  
// 012611F8  cmp         eax,dword ptr [ebp-58h]  
// 012611FB  jae         main+0D3h (1261213h)    ; index >= strlen(str_array), exit the "for" loop

// 012611FD  mov         ecx,dword ptr [ebp-30h]   ;  variable index; 
// 01261200  movsx       edx,byte ptr [ebp+ecx-44h]  
// 01261205  test        edx,edx  
// 01261207  je          main+0D3h (1261213h)      ; index != 0 , exit
	      ++index 
)
	{
		// As shown in the following,
		//    possibly [ebp-44h] is the base address of the string array.
		//     Immediately check over the memory , YEAH!!!!
		//    -------------------------------------------------------------------------
		//   | 0x002FF824 | 48 65 6c 6c 6f 2c 20 43 2b 2b 20 61 6e 64 | Hello, C++ and |
        //   | 0x002FF832 | 20 41 53 4d 00                            |  ASM.          |
		//   ---------------------------------------------------------------------------
		str_array[index] = 'A';  // The ASCII code of 'A' is 0x41
// 01261209  mov         eax,dword ptr [ebp-30h]  ;  get array's index
// 0126120C  mov         byte ptr [ebp+eax-44h],41h  
	}
// 01261211  jmp         main+82h (12611C2h)  
// 012612C2  mov         eax,dword ptr [ebp-30h]  
// 012611C5  add         eax,1  
// 012611C8  mov         dword ptr [ebp-30h],eax 

	// There is no need in analyzing the following statement,
	//   which is merely a deliberate to output some info. on screen.
	printf( "%s\n", str_array );
	cout << str_array << endl;
	cout << str_class << endl;

	return 0;
}


/*
Output on Console Windows:
--------------------------
AAAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAA
Hello, C++ and ASM
Press any key to continue...
--------------------------
*/