//
// while.cpp
//
//    11:11, Aug 06, 2015, by Mighten Dai <mighten.dai@gmail.com>
//
#define    TraceMark1()    __asm  mov  eax, 0x11111111;
#define    TraceMark2()    __asm  mov  eax, 0x22222222;

int main(void)
{
	bool	loop_only_one = false;

	TraceMark1();
	TraceMark1();

	while ( loop_only_one++ )
	{
// 008B1012  mov         al,byte ptr [loop_only_one]  
// 008B1015  mov         byte ptr [ebp-2],al        ;; Backup old variable
// 008B1018  mov         byte ptr [loop_only_one],1 ;; Update the variable
// 008B101C  movzx       ecx,byte ptr [ebp-2]       ;; the old variable
// 008B1020  test        ecx,ecx                    ;; test the old value
// 008B1022  je          main+30h (8B1030h)  

		TraceMark2();
		TraceMark2();
	}
// 008B102E  jmp         main+12h (8B1012h) 
	
	// Vir-Address = 008B1030 is here:
	TraceMark1();
	TraceMark1();
	
	return 0;
}

/*
Pure ASM code:

main:
-------------------------------------------------
008B1000 55                   push        ebp  
008B1001 8B EC                mov         ebp,esp  
008B1003 51                   push        ecx  
008B1004 C6 45 FF 00          mov         byte ptr [ebp-1],0    // [loop_only_one]
008B1008 B8 11 11 11 11       mov         eax,11111111h  
008B100D B8 11 11 11 11       mov         eax,11111111h  
008B1012 8A 45 FF             mov         al,byte ptr [ebp-1]  // [loop_only_one]
008B1015 88 45 FE             mov         byte ptr [ebp-2],al  
008B1018 C6 45 FF 01          mov         byte ptr [ebp-1],1  // [loop_only_one]
008B101C 0F B6 4D FE          movzx       ecx,byte ptr [ebp-2]  
008B1020 85 C9                test        ecx,ecx  
008B1022 74 0C                je          008B1030  
008B1024 B8 22 22 22 22       mov         eax,22222222h  // while-loop body
008B1029 B8 22 22 22 22       mov         eax,22222222h  // while-loop body  
008B102E EB E2                jmp         008B1012  
008B1030 B8 11 11 11 11       mov         eax,11111111h  
008B1035 B8 11 11 11 11       mov         eax,11111111h  
008B103A 33 C0                xor         eax,eax  
008B103C 8B E5                mov         esp,ebp  
008B103E 5D                   pop         ebp  
008B103F C3                   ret  
-------------------------------------------------
*/