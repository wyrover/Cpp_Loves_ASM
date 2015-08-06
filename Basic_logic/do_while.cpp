//
// do_while.cpp

#define    TraceMark1()    __asm  mov  eax, 0x11111111;
#define    TraceMark2()    __asm  mov  eax, 0x22222222;

int main(void )
{
	bool    once = false;
	
	TraceMark1();
	TraceMark1();
	do
	{
		TraceMark2();
		TraceMark2();
	}
	while (++once);

	TraceMark1();
	TraceMark1();
	
	return 0;
}