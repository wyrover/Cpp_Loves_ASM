//
// for.cpp

#define    TraceMark1()    __asm  mov  eax, 0x11111111;
#define    TraceMark2()    __asm  mov  eax, 0x22222222;

int main(void)
{
	int index;
	
	TraceMark1();
	TraceMark1();

	for ( index = 0; index < 10; index++ )
// 013D100E  mov         dword ptr [index],0  
// 013D1015  jmp         main+20h (13D1020h) --\
// 013D1017  mov         eax,dword ptr [index]  |
// 013D101A  add         eax,1                  |
// 013D101D  mov         dword ptr [index],eax  |
// 013D1020  cmp         dword ptr [index],0Ah -/
// 013D1024  jge         main+32h (13D1032h)  
	{
		TraceMark2();
		TraceMark2();
	}
// 013D1030  jmp         main+17h (13D1017h)

// 013D1032:
	TraceMark1();
	TraceMark1();
	
	return 0;
}
/*
Pure code
----------------------------
013D1000 55                   push        ebp  
013D1001 8B EC                mov         ebp,esp  
013D1003 51                   push        ecx  
013D1004 B8 11 11 11 11       mov         eax,11111111h  
013D1009 B8 11 11 11 11       mov         eax,11111111h  
013D100E C7 45 FC 00 00 00 00 mov         dword ptr [ebp-4],0  
013D1015 EB 09                jmp         013D1020  
013D1017 8B 45 FC             mov         eax,dword ptr [ebp-4]  
013D101A 83 C0 01             add         eax,1  
013D101D 89 45 FC             mov         dword ptr [ebp-4],eax  
013D1020 83 7D FC 0A          cmp         dword ptr [ebp-4],0Ah  
013D1024 7D 0C                jge         013D1032  
013D1026 B8 22 22 22 22       mov         eax,22222222h  
013D102B B8 22 22 22 22       mov         eax,22222222h  
013D1030 EB E5                jmp         013D1017  
013D1032 B8 11 11 11 11       mov         eax,11111111h  
013D1037 B8 11 11 11 11       mov         eax,11111111h  
013D103C 33 C0                xor         eax,eax  
013D103E 8B E5                mov         esp,ebp  
013D1040 5D                   pop         ebp  
013D1041 C3                   ret  
----------------------------
*/