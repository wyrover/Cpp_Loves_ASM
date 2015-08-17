//
//   Class_constant.cpp
//
//   The method of defining constant inside class definition.
//
//    06:37 PM, Aug 17, 2015, by Mighten Dai<mighten.dai@gmail.com>
//
////////////////////////////////////////////////////////////////////////////

class  const_class
{
private:
//    error C2864: 'const_class::const_int_var' : only static const integral data members can be initialized within a class
//  const int   const_int_var = 5;
    enum{ A=0, B=25};

public:
    const_class(){}
    ~const_class(){}

	int get_enum_A() { return A; }
	int get_enum_B() { return B; }
};

////////////////////////////////////////////////////////////////////////////
int  main( void )
{
    const_class     test_class;

    test_class.get_enum_A();
    test_class.get_enum_B();

    return 0;
}