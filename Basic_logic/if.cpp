//
// if.cpp

#define    TraceMark1()    __asm  mov  eax, 0x11111111;
#define    TraceMark2()    __asm  mov  eax, 0x22222222;
#define    TraceMark3()    __asm  mov  eax, 0x33333333;
#define    TraceMark4()    __asm  mov  eax, 0x44444444;

int main(void)
{
	bool   con = false;
	
	TraceMark1();
	TraceMark1();

	if ( con )
// 011A1012  movzx       eax,byte ptr [con]  
// 011A1016  test        eax,eax  
// 011A1018  je          main+26h (11A1026h)
	{
		TraceMark2();
		TraceMark2();
	}
// 011A1024  jmp         main+48h (11A1048h) 

	else if (!con - 1)
// 011A1026  movzx       ecx,byte ptr [con]  
// 011A102A  neg         ecx  
// 011A102C  sbb         ecx,ecx  
// 011A102E  test        ecx,ecx  
// 011A1030  je          main+3Eh (11A103Eh) 
	{
		TraceMark3();
		TraceMark3();
	}
// 011A103C  jmp         main+48h (11A1048h)  
	else
	{
		TraceMark4();
		TraceMark4();
	}

// 11A1048h:
	TraceMark1();
	TraceMark1();
	
	return 0;
}

/*
Pure assembly:

main:
--------------------
011A1000 55                   push        ebp  
011A1001 8B EC                mov         ebp,esp  
011A1003 51                   push        ecx  
011A1004 C6 45 FF 00          mov         byte ptr [ebp-1],0  
011A1008 B8 11 11 11 11       mov         eax,11111111h  
011A100D B8 11 11 11 11       mov         eax,11111111h  
011A1012 0F B6 45 FF          movzx       eax,byte ptr [ebp-1]  
011A1016 85 C0                test        eax,eax  
011A1018 74 0C                je          011A1026  
011A101A B8 22 22 22 22       mov         eax,22222222h  
011A101F B8 22 22 22 22       mov         eax,22222222h  
011A1024 EB 22                jmp         011A1048  
011A1026 0F B6 4D FF          movzx       ecx,byte ptr [ebp-1]  
011A102A F7 D9                neg         ecx  
011A102C 1B C9                sbb         ecx,ecx  
011A102E 85 C9                test        ecx,ecx  
011A1030 74 0C                je          011A103E  
011A1032 B8 33 33 33 33       mov         eax,33333333h  
011A1037 B8 33 33 33 33       mov         eax,33333333h  
011A103C EB 0A                jmp         011A1048  
011A103E B8 44 44 44 44       mov         eax,44444444h  
011A1043 B8 44 44 44 44       mov         eax,44444444h  
011A1048 B8 11 11 11 11       mov         eax,11111111h  
011A104D B8 11 11 11 11       mov         eax,11111111h  
011A1052 33 C0                xor         eax,eax  
011A1054 8B E5                mov         esp,ebp  
011A1056 5D                   pop         ebp  
011A1057 C3                   ret  
--------------------
*/