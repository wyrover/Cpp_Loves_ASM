//
//  Various_Pointers.cpp
//
//  Info concerned with pointers
//  20:43, August 05, 2015, by Mighten Dai<mighten.dai@gmail.com>
//

typedef		int		NONE_PARAM_FUNCTION();

typedef  struct tag_struct
{
	char    place_holder[512];
}
TEST_STRUCT;

NONE_PARAM_FUNCTION    *p_f;

int test_f(void)
{
	__asm  mov eax, 0x11111111;
	__asm  mov eax, 0x22222222;
	__asm  mov eax, 0x33333333;
	__asm  mov eax, 0x44444444;
	__asm  mov eax, 0x55555555;

	return 0;
}


int main(void )
{
// 003E1000  push        ebp  
// 003E1001  mov         ebp,esp  
// 003E1003  sub         esp,23Ch  
// 003E1009  mov         eax,dword ptr [___security_cookie (3E3000h)]  
// 003E100E  xor         eax,ebp  
// 003E1010  mov         dword ptr [ebp-34h],eax  

	TEST_STRUCT   s_test;
	TEST_STRUCT   *ps = &s_test;
// 003E1013  lea         eax,[ebp-238h]  
// 003E1019  mov         dword ptr [ebp-10h],eax  

	char     c_test;
	char     *pc = &c_test;
// 003E101C  lea         ecx,[ebp-25h]  
// 003E101F  mov         dword ptr [ebp-1Ch],ecx

	int      i_test;
	int      *pi = &i_test;
// 003E1022  lea         edx,[ebp-8]  
// 003E1025  mov         dword ptr [ebp-24h],edx  

	float    f_test;
	float    *pf = &f_test;
// 003E1028  lea         eax,[ebp-23Ch]  
// 003E102E  mov         dword ptr [ebp-20h],eax  

	double   d_test;
	double   *pd = &d_test;
// 003E1031  lea         ecx,[ebp-18h]  
// 003E1034  mov         dword ptr [ebp-4],ecx  

	long long int lli_test;
	long long int *plli = &lli_test;
// 003E1037  lea         edx,[ebp-30h]  
// 003E103A  mov         dword ptr [ebp-0Ch],edx 
	
	/////////////////////////////////
	//   External experiment:
	//      Pointer point to function.
	p_f = test_f;
// 008D105D  mov         dword ptr [p_f (8D336Ch)],offset test_f (8D1000h) 

	p_f();
// 008D1067  call        dword ptr [p_f (8D336Ch)]

	return 0;
}