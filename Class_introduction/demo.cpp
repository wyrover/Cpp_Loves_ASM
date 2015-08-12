//
//    demo.cpp
//
//    The codes contain main()
//
//    10:23 PM, Aug 12, 2015, by Mighten Dai <mighten.dai@gmail.com>
//
#include <string>
#include <iostream>

#include "stock.h"
#include "..\00000_Coding_suggestion\trace_mark.h"

using namespace std;

int main()
{
    {
        Stock    Mr_Tom;
// 00F110F5  push        0  
// 00F110F7  lea         ecx,[Mr_Tom]  
// 00F110FA  call        Stock::Stock (0F11080h)  // ECX as Class Pointer
// 00F110FF  mov         dword ptr [ebp-4],0  

        Stock    Mr_Jerry(123L);
// 00F11106  push        7Bh  
// 00F11108  lea         ecx,[Mr_Jerry]  
// 00F1110B  call        Stock::Stock (0F11080h)    // ECX as Class Pointer
// 00F11110  mov         byte ptr [ebp-4],1  

        Stock    Mr_Ray = Mr_Jerry;
// 00F11114  mov         eax,dword ptr [Mr_Jerry]  
// 00F11117  mov         dword ptr [Mr_Ray],eax  
// 00F1111A  mov         byte ptr [ebp-4],2  

        // Share numbers tests
        Mr_Tom.set_num( 0L );   // Poor Mr. Tom
// 00F1111E  push        0  
// 00F11120  lea         ecx,[Mr_Tom]             // ECX as Class Pointer
// 00F11123  call        Stock::set_num (0F110B0h)  

        cout << "Now, Mr. Tom has " << Mr_Tom.get_num() << " shares of stocks." << endl;
// 00F11134  lea         ecx,[Mr_Tom]  
// 00F11137  call        Stock::get_num (0F11070h)  
        Mr_Tom.set_num( 100000L );   // Rich Mr. Tom
// 00F1116A  push        186A0h  
// 00F1116F  lea         ecx,[Mr_Tom]  
// 00F11172  call        Stock::set_num (0F110B0h)  

        cout << "Now, Mr. Tom has " << Mr_Tom.get_num() << " shares of stocks." << endl;
// 00F11182  lea         ecx,[Mr_Tom]  
// 00F11185  call        Stock::get_num (0F11070h)

	TraceMark(0x22222222);
	TraceMark(0x22222222);
	TraceMark(0x22222222);
	TraceMark(0x22222222);
	TraceMark(0x22222222);
	}
//   Local Scope auto variable
// 003B11D1  mov         byte ptr [ebp-4],1  
// 003B11D5  lea         ecx,[Mr_Ray]  
// 003B11D8  call        Stock::~Stock (3B10A0h)  
// 003B11DD  mov         byte ptr [ebp-4],0  
// 003B11E1  lea         ecx,[Mr_Jerry]  
// 003B11E4  call        Stock::~Stock (3B10A0h)  
// 003B11E9  mov         dword ptr [ebp-4],0FFFFFFFFh  
// 003B11F0  lea         ecx,[Mr_Tom]  
// 003B11F3  call        Stock::~Stock (3B10A0h)  

	TraceMark(0x22222222);
	TraceMark(0x22222222);
	TraceMark(0x22222222);
	TraceMark(0x22222222);



	////////////////////////////////////////////
	//   External experiment -- using new/delete
	//
	TraceMark(0xAAAAAAAA);
	TraceMark(0xBBBBBBBB);
	TraceMark(0xCCCCCCCC);
	TraceMark(0xCCCCCCCC);

	Stock     *p_stock = NULL;
// 00A61220  mov         dword ptr [ebp-10h],0

	TraceMark(0xCCCCCCCC);
	TraceMark(0xCCCCCCCC);

	p_stock = new Stock;
// 00A61231  push        4  
// 00A61233  call        dword ptr [__imp_operator new (0A630E4h)]  
// 00A61239  add         esp,4  
// 00A6123C  mov         dword ptr [ebp-24h],eax  
// 00A6123F  cmp         dword ptr [ebp-24h],0  
// 00A61243  je          main+184h (0A61254h)  ------\
// 00A61245  push        0                            |
// 00A61247  mov         ecx,dword ptr [ebp-24h]      |
// 00A6124A  call        Stock::Stock (0A61080h)      |
//                                                    |
// 00A6124F  mov         dword ptr [ebp-30h],eax      |
// 00A61252  jmp         main+18Bh (0A6125Bh) ---\    |
// 00A61254  mov         dword ptr [ebp-30h],0  -|---/
// 00A6125B  mov         edx,dword ptr [ebp-30h]-/
// 00A6125E  mov         dword ptr [ebp-20h],edx  
// 00A61261  mov         eax,dword ptr [ebp-20h]  
// 00A61264  mov         dword ptr [ebp-10h],eax 

	TraceMark(0xCCCCCCCC);
	TraceMark(0xCCCCCCCC);

	delete p_stock;
// 00A61271  mov         ecx,dword ptr [ebp-10h] ;; *p_stock
// 00A61274  mov         dword ptr [ebp-2Ch],ecx  
// 00A61277  mov         edx,dword ptr [ebp-2Ch] ;; *p_stock
// 00A6127A  mov         dword ptr [ebp-28h],edx  
// 00A6127D  cmp         dword ptr [ebp-28h],0  
// 00A61281  je          main+1C2h (0A61292h)  -------------------------\
// 00A61283  push        1                                              |
// 00A61285  mov         ecx,dword ptr [ebp-28h]                        |
// 00A61288  call        Stock::`scalar deleting destructor' (0A612C0h) | ;; Not Stock::~Stock();
// 00A6128D  mov         dword ptr [ebp-34h],eax                        |
// 00A61290  jmp         main+1C9h (0A61299h)                           |
// 00A61292  mov         dword ptr [ebp-34h],0  ------------------------/
	p_stock = NULL;

	TraceMark(0xBBBBBBBB);
	TraceMark(0xAAAAAAAA);

    return 0;
// 003B120C  xor         eax,eax
}
// 003B120E  mov         ecx,dword ptr [ebp-0Ch]  
// 003B1211  mov         dword ptr fs:[0],ecx  
// 003B1218  pop         ecx  
// 003B1219  mov         esp,ebp  
// 003B121B  pop         ebp  
// 003B121C  ret