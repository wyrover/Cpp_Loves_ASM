# Class_introduction

Getting start programming with OOP -- Class

Some disassembling experience:

1. The class method is, no matter how many copies of objects remain in memory,
     only one method is invoked, 
   but require class pointer stored in ECX to identity which object is operated.

2. this pointer is actually a copy of ECX value in stack, a pointer refer to a object.

3. the private member -- variable are actuall share the same memory location with 
    its corresponding object variable;
    In this sample, you will see the following section in "Stock.h":

    32:     Stock(const long sum = 0)
    33:     {
    34:         m_share_num = sum;
    46:     }

008C1080  push        ebp  
008C1081  mov         ebp,esp  
008C1083  push        ecx  
008C1084  mov         dword ptr [ebp-4],ecx  
008C1087  mov         eax,dword ptr [this]   ;; [ebp-4]
008C108A  mov         ecx,dword ptr [sum]    ;; outside variable.
008C108D  mov         dword ptr [eax],ecx   ;; modify the variable
008C108F  mov         eax,dword ptr [this]  ;;;; Maybe the return value, but remains undefined 
                                            ;;;;   in return value of ctors( constructors )
008C1092  mov         esp,ebp  
008C1094  pop         ebp  
008C1095  ret         4  

4. When using dynamic memory allocation, after invoking the new, it automatically do the construction,
   Whereas expiring a object by using delete, it doesn't do the same thing as normal delete,
       The following module will give you some essential feeling:
//
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
//
--> it seems that it is a build-in action. -->  Stock::`scalar deleting destructor' (0A612C0h)


5. It is better to define declaration & definition in a same Header file, or easily causes an 
     error "LNK2001: unresolved external symbol ..."





BTW:
-------------------------------------
I got an PDF documentation by google, which contains  several pages,
    where it gives a thorough representation of C++'s disassembly on MSVS & Windows platform.

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    Corresponding Webpage, please feel free to download.
---------------------------------------------------------------

  URL= https://www.blackhat.com/presentations/bh-dc-07/Sabanal_Yason/Paper/bh-dc-07-Sabanal_Yason-WP.pdf
  ReNamed =  Reversing_Cpp.PDF

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

It will be uploaded onto my GitHub.
 It relative path is
          /Cpp_Loves_ASM/00000_Manual/Reversing_Cpp.pdf