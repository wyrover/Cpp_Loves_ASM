//
// stock.h
//
// Demonstrate how to use Class
// 09:27 PM, Aug 11, 2015, by Mighten Dai <mighten.dai@gmail.com>
//

#ifndef   MACRO_PROTECTION__INCLUDE_STOCK_H__
#define   MACRO_PROTECTION__INCLUDE_STOCK_H__

class  Stock
{
private:
	long    m_share_num;

public:
	void    set_num( long share_num );
	long    get_num(                ) { return m_share_num; }
};


#endif // #ifndef MACRO_PROTECTION__INCLUDE_STOCK_H__