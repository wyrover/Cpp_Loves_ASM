//
// and_or_not.cpp
//
//     1> The difference between "||" / "|" as well as "&&" / "&"
//
//    10:58, Aug 06, 2015, by Mighten Dai <mighten.dai@gmail.com>
//
int main(void)
{
	unsigned int   con1=0xF0F0, con2=0000;

	unsigned int	temp = false;
	
	temp  = con1 || con2;
// 012E101B  cmp         dword ptr [con1],0  
// 012E101F  jne         main+30h (12E1030h)------------\
// 012E1021  cmp         dword ptr [con2],0             |
// 012E1025  jne         main+30h (12E1030h)------------|
// 012E1027  mov         dword ptr [ebp-10h],0          |
// 012E102E  jmp         main+37h (12E1037h)-----\      |
//                                                |     |
// 012E1030  mov         dword ptr [ebp-10h],1----|-----/ 
// 012E1037  mov         eax,dword ptr [ebp-10h]  |      
// 012E103A  mov         dword ptr [temp],eax ---/       
	
	temp  = con1  | con2;
// 012E103D  mov         ecx,dword ptr [con1]  
// 012E1040  or          ecx,dword ptr [con2]  
// 012E1043  mov         dword ptr [temp],ecx 

	temp  = con1 && con2;
// 012E1046  cmp         dword ptr [con1],0  
// 012E104A  je          main+5Bh (12E105Bh)----------\
// 012E104C  cmp         dword ptr [con2],0            |
// 012E1050  je          main+5Bh (12E105Bh)-----------|
// 012E1052  mov         dword ptr [ebp-14h],1         |
// 012E1059  jmp         main+62h (12E1062h)-----\     |
//                                               |     |
// 012E105B  mov         dword ptr [ebp-14h],0---|-----/
// 012E1062  mov         edx,dword ptr [ebp-14h]-/
// 012E1065  mov         dword ptr [temp],edx  

	temp  = con1  & con2;
// 012E1068  mov         eax,dword ptr [con1]  
// 012E106B  and         eax,dword ptr [con2]  
// 012E106E  mov         dword ptr [temp],eax  

	temp  = ~con1;
// 012E1071  mov         ecx,dword ptr [con1]  
// 012E1074  not         ecx  
// 012E1076  mov         dword ptr [temp],ecx  

	temp  = ~con2;
// 012E1079  mov         edx,dword ptr [con2]  
// 012E107C  not         edx  
// 012E107E  mov         dword ptr [temp],edx  

	return 0;
}