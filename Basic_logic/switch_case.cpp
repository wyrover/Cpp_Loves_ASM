//
// switch_case.cpp
// Demonstrate how it works with switch...case.
//
//  --- Details to remember ---
//   1> 

#define    TraceMark1()    __asm  mov  eax, 0x11111111;
#define    TraceMark2()    __asm  mov  eax, 0x22222222;
#define    TraceMark3()    __asm  mov  eax, 0x33333333;
#define    TraceMark4()    __asm  mov  eax, 0x44444444;
#define    TraceMark5()    __asm  mov  eax, 0x55555555;
#define    TraceMark6()    __asm  mov  eax, 0x66666666;
#define    TraceMark7()    __asm  mov  eax, 0x77777777;
#define    TraceMark8()    __asm  mov  eax, 0x88888888;
#define    TraceMark9()    __asm  mov  eax, 0x99999999;
#define    TraceMarkA()    __asm  mov  eax, 0xAAAAAAAA;
#define    TraceMarkB()    __asm  mov  eax, 0xBBBBBBBB;

#include <iostream>

using namespace std;

#define   flush_input()   { while( '\n' != ( getchar( ) ) ) continue; }

int judge( char ch );

//////////////////////
int main(void)
{
	char   c = NULL;
	
	for ( ; ; )
	{
		cin >> c;
		judge(c);
		flush_input();
	}
	
	return 0;
}


int judge( char ch )
{
	TraceMark1();
	TraceMark1();
	TraceMark1();

	switch (ch)
//   Address existed a leap
//        refer to the EOF see the complete version.
// 011110F3  movsx       eax,byte ptr [ch]  
// 011110F7  mov         dword ptr [ebp-4],eax  
// 011110FA  mov         ecx,dword ptr [ebp-4]  
// 011110FD  sub         ecx,2Dh  
// 01111100  mov         dword ptr [ebp-4],ecx  
// 01111103  cmp         dword ptr [ebp-4],51h  
// 01111107  ja          $LN2+29h (11112A4h)  
// 0111110D  mov         edx,dword ptr [ebp-4]  
// 01111110  movzx       eax,byte ptr  (1111308h)[edx]  
// 01111117  jmp         dword ptr  (11112E0h)[eax*4] 
	{
	case '1': 
		cout << "\n    1 got." << endl;
		TraceMark2();
		break;

	case '.': 
		cout << "\n    . got." << endl;
		TraceMark3();
		break;

	case '-':
		cout << "\n    - got." << endl;
		TraceMark4();
		break;

	case '=':
		cout << "\n    = got." << endl;
		TraceMark5();
		break;

	case '\/':
		cout << "\n    \/ got." << endl;
		TraceMark6();
		break;

	case '\\':
		cout << "\n    \\ got." << endl;
		TraceMark7();
		break;

	case 'A':
		cout << "\n    A got." << endl;
		TraceMark8();
		break;

	case '9':
		cout << "\n    9 got." << endl;
		TraceMark9();
		break;

	case '~':
		cout << "\n    ~ got." << endl;
		TraceMarkA();
		break;

	default:  TraceMarkB(); 
		cout << "\n    Nothing matched." << endl;
	}

	TraceMark1();
	TraceMark1();
	TraceMark1();
}
/*
-------------------------------
010210E0 55                   push        ebp  
010210E1 8B EC                mov         ebp,esp  
010210E3 51                   push        ecx  
010210E4 B8 11 11 11 11       mov         eax,11111111h  
010210E9 B8 11 11 11 11       mov         eax,11111111h  
010210EE B8 11 11 11 11       mov         eax,11111111h  
010210F3 0F BE 45 08          movsx       eax,byte ptr [ebp+8]  
010210F7 89 45 FC             mov         dword ptr [ebp-4],eax  
010210FA 8B 4D FC             mov         ecx,dword ptr [ebp-4]  
010210FD 83 E9 2D             sub         ecx,2Dh  
01021100 89 4D FC             mov         dword ptr [ebp-4],ecx  
01021103 83 7D FC 51          cmp         dword ptr [ebp-4],51h  
01021107 0F 87 97 01 00 00    ja          010212A4  
0102110D 8B 55 FC             mov         edx,dword ptr [ebp-4]  
01021110 0F B6 82 08 13 02 01 movzx       eax,byte ptr [edx+01021308h]  
01021117 FF 24 85 E0 12 02 01 jmp         dword ptr [eax*4+010212E0h]  
$LN10:
0102111E 8B 0D 50 30 02 01    mov         ecx,dword ptr ds:[01023050h]  
01021124 51                   push        ecx  
01021125 68 44 31 02 01       push        1023144h  
0102112A 8B 15 78 30 02 01    mov         edx,dword ptr ds:[01023078h]  
01021130 52                   push        edx  
01021131 E8 BA 04 00 00       call        010215F0  
01021136 83 C4 08             add         esp,8  
01021139 8B C8                mov         ecx,eax  
0102113B FF 15 5C 30 02 01    call        dword ptr ds:[0102305Ch]  
01021141 B8 22 22 22 22       mov         eax,22222222h  
01021146 E9 81 01 00 00       jmp         010212CC  
$LN9:
0102114B A1 50 30 02 01       mov         eax,dword ptr ds:[01023050h]  
01021150 50                   push        eax  
01021151 68 50 31 02 01       push        1023150h  
01021156 8B 0D 78 30 02 01    mov         ecx,dword ptr ds:[01023078h]  
0102115C 51                   push        ecx  
0102115D E8 8E 04 00 00       call        010215F0  
01021162 83 C4 08             add         esp,8  
01021165 8B C8                mov         ecx,eax  
01021167 FF 15 5C 30 02 01    call        dword ptr ds:[0102305Ch]  
0102116D B8 33 33 33 33       mov         eax,33333333h  
01021172 E9 55 01 00 00       jmp         010212CC  
$LN8:
01021177 8B 15 50 30 02 01    mov         edx,dword ptr ds:[01023050h]  
0102117D 52                   push        edx  
0102117E 68 5C 31 02 01       push        102315Ch  
01021183 A1 78 30 02 01       mov         eax,dword ptr ds:[01023078h]  
01021188 50                   push        eax  
01021189 E8 62 04 00 00       call        010215F0  
0102118E 83 C4 08             add         esp,8  
01021191 8B C8                mov         ecx,eax  
01021193 FF 15 5C 30 02 01    call        dword ptr ds:[0102305Ch]  
01021199 B8 44 44 44 44       mov         eax,44444444h  
0102119E E9 29 01 00 00       jmp         010212CC  
$LN7:
010211A3 8B 0D 50 30 02 01    mov         ecx,dword ptr ds:[01023050h]  
010211A9 51                   push        ecx  
010211AA 68 68 31 02 01       push        1023168h  
010211AF 8B 15 78 30 02 01    mov         edx,dword ptr ds:[01023078h]  
010211B5 52                   push        edx  
010211B6 E8 35 04 00 00       call        010215F0  
010211BB 83 C4 08             add         esp,8  
010211BE 8B C8                mov         ecx,eax  
010211C0 FF 15 5C 30 02 01    call        dword ptr ds:[0102305Ch]  
010211C6 B8 55 55 55 55       mov         eax,55555555h  
010211CB E9 FC 00 00 00       jmp         010212CC  
$LN6:
010211D0 A1 50 30 02 01       mov         eax,dword ptr ds:[01023050h]  
010211D5 50                   push        eax  
010211D6 68 74 31 02 01       push        1023174h  
010211DB 8B 0D 78 30 02 01    mov         ecx,dword ptr ds:[01023078h]  
010211E1 51                   push        ecx  
010211E2 E8 09 04 00 00       call        010215F0  
010211E7 83 C4 08             add         esp,8  
010211EA 8B C8                mov         ecx,eax  
010211EC FF 15 5C 30 02 01    call        dword ptr ds:[0102305Ch]  
010211F2 B8 66 66 66 66       mov         eax,66666666h  
010211F7 E9 D0 00 00 00       jmp         010212CC  
$LN5:
010211FC 8B 15 50 30 02 01    mov         edx,dword ptr ds:[01023050h]  
01021202 52                   push        edx  
01021203 68 80 31 02 01       push        1023180h  
01021208 A1 78 30 02 01       mov         eax,dword ptr ds:[01023078h]  
0102120D 50                   push        eax  
0102120E E8 DD 03 00 00       call        010215F0  
01021213 83 C4 08             add         esp,8  
01021216 8B C8                mov         ecx,eax  
01021218 FF 15 5C 30 02 01    call        dword ptr ds:[0102305Ch]  
0102121E B8 77 77 77 77       mov         eax,77777777h  
01021223 E9 A4 00 00 00       jmp         010212CC  
$LN4:
01021228 8B 0D 50 30 02 01    mov         ecx,dword ptr ds:[01023050h]  
0102122E 51                   push        ecx  
0102122F 68 8C 31 02 01       push        102318Ch  
01021234 8B 15 78 30 02 01    mov         edx,dword ptr ds:[01023078h]  
0102123A 52                   push        edx  
0102123B E8 B0 03 00 00       call        010215F0  
01021240 83 C4 08             add         esp,8  
01021243 8B C8                mov         ecx,eax  
01021245 FF 15 5C 30 02 01    call        dword ptr ds:[0102305Ch]  
0102124B B8 88 88 88 88       mov         eax,88888888h  
01021250 EB 7A                jmp         010212CC  
$LN3:
01021252 A1 50 30 02 01       mov         eax,dword ptr ds:[01023050h]  
01021257 50                   push        eax  
01021258 68 98 31 02 01       push        1023198h  
0102125D 8B 0D 78 30 02 01    mov         ecx,dword ptr ds:[01023078h]  
01021263 51                   push        ecx  
01021264 E8 87 03 00 00       call        010215F0  
01021269 83 C4 08             add         esp,8  
0102126C 8B C8                mov         ecx,eax  
0102126E FF 15 5C 30 02 01    call        dword ptr ds:[0102305Ch]  
01021274 B8 99 99 99 99       mov         eax,99999999h  
01021279 EB 51                jmp         010212CC  
$LN2:
0102127B 8B 15 50 30 02 01    mov         edx,dword ptr ds:[01023050h]  
01021281 52                   push        edx  
01021282 68 A4 31 02 01       push        10231A4h  
01021287 A1 78 30 02 01       mov         eax,dword ptr ds:[01023078h]  
0102128C 50                   push        eax  
0102128D E8 5E 03 00 00       call        010215F0  
01021292 83 C4 08             add         esp,8  
01021295 8B C8                mov         ecx,eax  
01021297 FF 15 5C 30 02 01    call        dword ptr ds:[0102305Ch]  
0102129D B8 AA AA AA AA       mov         eax,0AAAAAAAAh  
010212A2 EB 28                jmp         010212CC  
010212A4 B8 BB BB BB BB       mov         eax,0BBBBBBBBh  
010212A9 8B 0D 50 30 02 01    mov         ecx,dword ptr ds:[01023050h]  
010212AF 51                   push        ecx  
010212B0 68 B0 31 02 01       push        10231B0h  
010212B5 8B 15 78 30 02 01    mov         edx,dword ptr ds:[01023078h]  
010212BB 52                   push        edx  
010212BC E8 2F 03 00 00       call        010215F0  
010212C1 83 C4 08             add         esp,8  
010212C4 8B C8                mov         ecx,eax  
010212C6 FF 15 5C 30 02 01    call        dword ptr ds:[0102305Ch]  
010212CC B8 11 11 11 11       mov         eax,11111111h  
010212D1 B8 11 11 11 11       mov         eax,11111111h  
010212D6 B8 11 11 11 11       mov         eax,11111111h  
010212DB 8B E5                mov         esp,ebp  
010212DD 5D                   pop         ebp  
010212DE C3                   ret  

; >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
010212E0  db          77h  
010212E1  db          11h  
010212E2  db          02h  
010212E3  db          01h  

010212E4  db          4bh  
010212E5  db          11h  
010212E6  db          02h  
010212E7  db          01h  

010212E8  db          d0h  
010212E9  db          11h  
010212EA  db          02h  
010212EB  db          01h  

010212EC  db          1eh  
010212ED  db          11h  
010212EE  db          02h  
010212EF  db          01h  

010212F0  db          52h  
010212F1  db          12h  
010212F2  db          02h  
010212F3  db          01h  

010212F4  db          a3h  
010212F5  db          11h  
010212F6  db          02h  
010212F7  db          01h  

010212F8  db          28h  
010212F9  db          12h  
010212FA  db          02h  
010212FB  db          01h  

010212FC  db          fch  
010212FD  db          11h  
010212FE  db          02h  
010212FF  db          01h  

01021300  db          7bh  
01021301  db          12h  
01021302  db          02h  
01021303  db          01h  

01021304  db          a4h  
01021305  db          12h  
01021306  db          02h  
01021307  db          01h  

-------------------------------
*/