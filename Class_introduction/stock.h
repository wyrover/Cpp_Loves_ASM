//
// stock.h
//
// Demonstrate how to use Class
//    10:23 PM, Aug 12, 2015, by Mighten Dai <mighten.dai@gmail.com>
//

#ifndef   MACRO_PROTECTION__INCLUDE_STOCK_H__
#define   MACRO_PROTECTION__INCLUDE_STOCK_H__

class  Stock
{
private:
	long    m_share_num;

public:
	void    set_num( long share_num );
	long    get_num(                ) 
	{ 
		return m_share_num; 
// 00A61070  push        ebp  
// 00A61071  mov         ebp,esp  
// 00A61073  push        ecx  
// 00A61074  mov         dword ptr [ebp-4],ecx  
// 00A61077  mov         eax,dword ptr [this]  
// 00A6107A  mov         eax,dword ptr [eax]  
// 00A6107C  mov         esp,ebp  
// 00A6107E  pop         ebp  
// 00A6107F  ret 
	}

	Stock(const long sum = 0)
	{
		m_share_num = sum;
// 00A61080  push        ebp  
// 00A61081  mov         ebp,esp  
// 00A61083  push        ecx  
// 00A61084  mov         dword ptr [ebp-4],ecx  
// 00A61087  mov         eax,dword ptr [this]  ;; [ebp-4]
// 00A6108A  mov         ecx,dword ptr [sum]   ;; [ebp-4]
// 00A6108D  mov         dword ptr [eax],ecx  
// 00A6108F  mov         eax,dword ptr [this]  ;; [ebp-4] 
// 00A61092  mov         esp,ebp  
// 00A61094  pop         ebp  
// 00A61095  ret         4  
	}

	~Stock(){}
};

///////////////////////////////////////////////////
inline void   Stock::set_num( long share_num )
{
    m_share_num = share_num;
// 00A610B0  push        ebp  
// 00A610B1  mov         ebp,esp  
// 00A610B3  push        ecx          // Class pointer
// 00A610B4  mov         dword ptr [ebp-4],ecx  
// 00A610B7  mov         eax,dword ptr [this]  
// 00A610BA  mov         ecx,dword ptr [share_num]  
// 00A610BD  mov         dword ptr [eax],ecx  
// 00A610BF  mov         esp,ebp  
// 00A610C1  pop         ebp  
// 00A610C2  ret         4  
}

///////////////////////////////////////////////////

#endif // #ifndef MACRO_PROTECTION__INCLUDE_STOCK_H__