//
//  Operator_OL.h
//
//      Operator Overloading
//
//  10:11 PM, Aug 14, 2015, by Mighten Dai<mighten.dai@gmail.com>
//
//  ******** This file requires supplement of <iostream>
//
#ifndef    MACRO_PROTECTION_INCLUDE_OPERATOR_OL_H__
#define    MACRO_PROTECTION_INCLUDE_OPERATOR_OL_H__

// Time
class   Time
{
private:
	int m_hour;
	int m_minute;
	int m_second;

public:
	Time( int hour = 0, int minute = 0, int second = 0)
	{
		m_hour   = hour;
		m_minute = minute;
		m_second = second;
	}

	~Time(){ }

	//  Display
	void show( void ){ cout << '#'<< m_hour << ':' << m_minute << ':' << m_second << endl;}

	// Polymorphism: Operator Overloading
	Time & operator ++();
	Time & operator --();
};

//////////////////////////////////////////////////
Time &  Time::operator ++()
{
	this->m_second++;

	if ( m_second > 59)
	{
		m_second = 0;
		m_minute++;
	}

	if ( m_minute > 59)
	{
		m_minute = 0;
		m_hour++;
	}

	if ( m_hour > 23)
	{
		m_hour = 0;
	}

	return  *this;
}

//////////////////////////////////////////////////
Time &  Time::operator-- ()
{
	m_second--;

	if ( m_second < 0) 
	{
		m_second = 59;
		m_minute--;
	}

	if ( m_minute < 0)
	{
		 m_minute = 59;
		 m_hour--;
	}
	
	if ( m_hour < 0) m_hour = 23;
	
	return  *this;
}
//////////////////////////////////////////////////

#endif //#ifndef    MACRO_PROTECTION_INCLUDE_OPERATOR_OL_H__