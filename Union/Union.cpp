//
//   Union.cpp
//
//    It is said that "Union" are used for reducing memory requirement.
//


/////////////////////////////////////////////////////
// Only 4 bytes in length, rather than 8 bytes.
union   test_union_storage
{
	bool   test_flag;
	char   place_holder[3];
	int    test_value;
}test_union;

// Compiler's optimization makes variable "temp" global, but this is illusive.
unsigned int temp = 0; // And therefore, I move the declaration to here.


int main(void)
{
	temp = sizeof(union test_union_storage);
// 001F1003  mov         dword ptr [temp (1F3370h)],4

	test_union.test_value = 0xFFFFFFFF;
// 001F100D  mov         dword ptr [test_union (1F336Ch)],0FFFFFFFFh

	temp = test_union.place_holder[0];
// 001F1017  movsx       eax,byte ptr [test_union (1F336Ch)]  
// 001F101E  mov         dword ptr [temp (1F3370h)],eax  

	temp = test_union.test_flag;
// 001F1023  movzx       ecx,byte ptr [test_union (1F336Ch)]  
// 001F102A  mov         dword ptr [temp (1F3370h)],ecx  

	test_union.test_value = 0x00000000;
// 001F1030  mov         dword ptr [test_union (1F336Ch)],0  

	temp = test_union.place_holder[0];
// 001F103A  movsx       edx,byte ptr [test_union (1F336Ch)]  
// 001F1041  mov         dword ptr [temp (1F3370h)],edx  

	temp = test_union.test_flag;
// 001F1047  movzx       eax,byte ptr [test_union (1F336Ch)]  
// 001F104E  mov         dword ptr [temp (1F3370h)],eax 

	////////////////////////////////////////////////////
	//  How about read the place_holder[1], place_holder[2]
	//     I mean its offset relative to "test_union"
	//  External testing are as following, if you see the leap of address,
	//           please easy, don't be surprised.
	temp = test_union.place_holder[1];
// 00811053  movsx       ecx,byte ptr [test_union+1 (81336Dh)]  
// 0081105A  mov         dword ptr [temp (813370h)],ecx  

	temp = test_union.place_holder[2];
// 00811060  movsx       edx,byte ptr [test_union+2 (81336Eh)]  
// 00811067  mov         dword ptr [temp (813370h)],edx  

	return 0;
}