//
//  5_Read_Structure.cpp
//  This shows the brief process of operating the structures.
//
//  20:21, Aug 04, 2015
// Singed-off-by: Mighten Dai<mighten.dai@gmail.com>
//
///////////////////////////////////////////////////////////////////////////////


// Define the Disassembly trace mark. -- triple "mov eax, eax"
#define    MACRO_DEMO_Disasm_trace_mark()   __asm mov  eax, 0x0123ABCD;

// Special Alignment in accordance with 32-bit Boundary.
struct test_32_alignment
{
	//  Finally result of running
	int    test_read_write;  // aa 55 aa 55
	char   some_info[4];     // 48 69 7e 00   | 'H', 'i', '~', '\0'
} test_a32;

// Non-aligned structure
struct test_nonaligned
{
	//  Finally result of running
	int    test_read_write;  // ff ff ff ff
	char   place_holder_0;   // 00 00 00 00   <=====> Auto alignment.
	int    place_holder_1;   // 00 00 00 00
	bool   AVL_flag;         // 01
}test_na;


// Entry
int main(void)
{
	int		temp = 0;

	MACRO_DEMO_Disasm_trace_mark();

	struct test_32_alignment    *p_a32 = &test_a32;
	struct test_nonaligned		*p_na  = &test_na;

	test_a32.test_read_write = 0xAA55AA55;
	temp = p_a32->test_read_write;

	test_a32.test_read_write = 0x55AA55AA;
	temp = p_a32->test_read_write;

	test_a32.some_info[0] = 'H';
	test_a32.some_info[1] = 'i';
	test_a32.some_info[2] = '~';
	test_a32.some_info[3] = '\0';

	test_na.AVL_flag = false;
	test_na.test_read_write = 0x00000000;
	p_na->test_read_write = 0xFFFFFFFF;
	test_na.AVL_flag = true;

	MACRO_DEMO_Disasm_trace_mark();

	return 0;
}

// Disassembler Output from Trace mark:

//  01341012  mov         dword ptr [p_a32],offset test_a32 (1343374h)  
//  01341019  mov         dword ptr [p_na],offset test_na (134336Ch)  


//  01341020  mov         dword ptr [test_a32 (1343374h)],0AA55AA55h  

//  ====>  temp = p_a32->test_read_write;
//  0134102A  mov         eax,dword ptr [p_a32]  
//  0134102D  mov         ecx,dword ptr [eax]  
//  0134102F  mov         dword ptr [temp],ecx  

//  01341032  mov         dword ptr [test_a32 (1343374h)],55AA55AAh  

//  ===>  temp = p_a32->test_read_write;
//  0134103C  mov         edx,dword ptr [p_a32]  
//  0134103F  mov         eax,dword ptr [edx]  
//  01341041  mov         dword ptr [temp],eax  

//  01341044  mov         byte ptr [test_a32+4 (1343378h)],48h  ; = 'H'
//  0134104B  mov         byte ptr [test_a32+5 (1343379h)],69h  ; = 'i'
//  01341052  mov         byte ptr [test_a32+6 (134337Ah)],7Eh  ; = '~'
//  01341059  mov         byte ptr [test_a32+7 (134337Bh)],0    ; = '\0'
//  >>>>>>>>> Goto here, respected memory space is :
//                            aa 55 aa 55 48 69 7e 00

//  01341060  mov         byte ptr [test_na+0Ch (1343378h)],0  // AVL_flag = false;
//  01341067  mov         dword ptr [test_na (134336Ch)],0   // test_read_write
//  01341071  mov         ecx,dword ptr [p_na]     ; ECX = &test_na 
//  01341074  mov         dword ptr [ecx],0FFFFFFFFh  
//  0134107A  mov         byte ptr [test_na+0Ch (1343378h)],1  // AVL_flag = true;
//  >>>>>>>>> Goto here, respected memory space is :
//                            ff ff ff ff 00 00 00 00 00 00 00 00 01

//