//
//     function_OL.cpp
//
//     Function Overloading in C++.
//           C++'s Feature:  Polymorphism
//
//   Latest Version: 07:01 PM, August 09, 2015, by Mighten Dai
//
////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////////
int  increase( int & target, const int increment );
int  decrease( int & target, const int increment );

double  increase( double & target, const double increment );
double  decrease( double & target, const double increment );

////////////////////////////////////////////////////////////////////
int main( void )
{
    int     iTarget = 0;
    double  fTarget = 0;
	
	// Initialize the executing environment.
	cout.setf( ios::fixed, ios::floatfield );

    cout << increase( iTarget, 2 ) << endl;  // increase (1061130h)
    cout << decrease( iTarget, 1 ) << endl;  // decrease (1061150h)
    cout << increase( fTarget, (double)2.0 ) << endl;  // increase (1061170h)
    cout << decrease( fTarget, (double)1.0 ) << endl;  // decrease (1061190h)

    ///////////////////////////////////
    //   special match experiment
//  increase( iTarget, 2.0 ); // warning C4244: 'argument' : conversion from 'double' to 'const int', possible loss of data
    increase( fTarget, 2.0 );
//  decrease( iTarget, 2.0 ); //  warning C4244: 'argument' : conversion from 'double' to 'const int', possible loss of data
    decrease( fTarget, 2.0 );

    return 0;
}

////////////////////////////////////////////////////////////////////
// integer version
int  increase( int & target, const int increment )
{
    return ( target += increment);
// 01061130  push        ebp  
// 01061131  mov         ebp,esp  
// 01061133  mov         eax,dword ptr [target]  
// 01061136  mov         ecx,dword ptr [eax]  
// 01061138  add         ecx,dword ptr [increment]  
// 0106113B  mov         edx,dword ptr [target]  
// 0106113E  mov         dword ptr [edx],ecx  
// 01061140  mov         eax,dword ptr [target]  
// 01061143  mov         eax,dword ptr [eax]  
// 01061145  pop         ebp  
// 01061146  ret  
}
// ------------------------------------------
int  decrease( int & target, const int decrement )
{
    return ( target -= decrement);
// 01061150  push        ebp  
// 01061151  mov         ebp,esp  
// 01061153  mov         eax,dword ptr [target]  
// 01061156  mov         ecx,dword ptr [eax]  
// 01061158  sub         ecx,dword ptr [decrement]  
// 0106115B  mov         edx,dword ptr [target]  
// 0106115E  mov         dword ptr [edx],ecx  
// 01061160  mov         eax,dword ptr [target]  
// 01061163  mov         eax,dword ptr [eax]  
// 01061165  pop         ebp  
// 01061166  ret  
}

////////////////////////////////////////////////////////////////////
// floating-point version
double  increase( double & target, const double increment )
{
    return ( target += increment);
// 01061170  push        ebp  
// 01061171  mov         ebp,esp  
// 01061173  mov         eax,dword ptr [target]  
// 01061176  fld         qword ptr [eax]  
// 01061178  fadd        qword ptr [increment]  
// 0106117B  mov         ecx,dword ptr [target]  
// 0106117E  fstp        qword ptr [ecx]  
// 01061180  mov         edx,dword ptr [target]  
// 01061183  fld         qword ptr [edx]  
// 01061185  pop         ebp  
// 01061186  ret  
}
// ------------------------------------------
double  decrease( double & target, const double decrement )
{
    return ( target -= decrement);
// 01061190  push        ebp  
// 01061191  mov         ebp,esp  
// 01061193  mov         eax,dword ptr [target]  
// 01061196  fld         qword ptr [eax]  
// 01061198  fsub        qword ptr [decrement]  
// 0106119B  mov         ecx,dword ptr [target]  
// 0106119E  fstp        qword ptr [ecx]  
// 010611A0  mov         edx,dword ptr [target]  
// 010611A3  fld         qword ptr [edx]  
// 010611A5  pop         ebp  
// 010611A6  ret  
}

/*
Portray onscreen
-------------------
2
3
2.000000
3.000000
-------------------
*/