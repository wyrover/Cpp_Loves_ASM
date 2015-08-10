//
//     template_OL.cpp
//
//     Template Overloading in C++.
//           C++'s Feature:  Polymorphism
//
//   Latest Version: 07:01 PM, August 09, 2015, by Mighten Dai
//
////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include"..\00000_Coding_suggestion\trace_mark.h"    
using namespace std;

/////////////////////////////////////////////////////
struct  type_location
{
    double x;
    double y;
};

/////////////////////////////////////////////////////
// Implicit instantiation
template< class T > int  do_swap(T & a, T & b);

// Implicit instantiation / Template overloading
template< class T > int  do_swap(T * a, T * b,  const unsigned int common_length );

// Explicit specialization
template<>         int  do_swap<type_location>( type_location & a, type_location & b );

//////////////////////////////////////////////////
//     Poly-function Address Table
//
// do_swap<char>           (0B2140h)
// do_swap<type_location>  (0B18A0h)
// do_swap<char>           (0B2140h) // This should be "<bool>", regardless of compiler optimization
// do_swap<int>            (0B2170h)
// do_swap<double>         (0B21A0h)

/////////////////////////////////////////////////////
//
int main(void )
{
    //  This is used to avoid type-casting by force.
    double   point_a_x = 1.0f;
    double   point_a_y = 2.0f;
    double   point_b_x = 5.0f;
    double   point_b_y = 2.3f;
    type_location     point_a = { point_a_x, point_a_y };
    type_location     point_b = { point_b_x, point_b_y };
    char    char_A = 'A', char_B = 'B';
    bool    bool_t = true, bool_f = false;
    int     int_a = 0xFFFFFFFF, int_b = 0x00000000;

    /////////////////////////////////////////
    //   Get prepared, now start !!!!!

    // A char-typed instantiation of the template
    cout << "Before swap, char_A = " << char_A << endl;
    cout << "    whereas, char_B = " << char_B << endl;
    TraceMark(0xAAAAAAAA);
    TraceMark(0xAAAAAAAA);
    TraceMark(0xBBBBBBBB);
    TraceMark(0xBBBBBBBB);
    do_swap<char>( char_A, char_B ); // Explicit instantiation
    TraceMark(0xBBBBBBBB);
    TraceMark(0xBBBBBBBB);
    TraceMark(0xAAAAAAAA);
    TraceMark(0xAAAAAAAA);
    cout << "After  swap, char_A = " << char_A << endl;
    cout << "    whereas, char_B = " << char_B << endl << endl;

    // --------------------------------------
    // A struct_type_location-typed instantiation of the template
    cout << "Before swap, point_a.x = " << point_a.x << endl;
    cout << "             point_a.y = " << point_a.y << endl;
    cout << "    whereas, point_b.x = " << point_b.x << endl;
    cout << "             point_b.y = " << point_b.y << endl;
    TraceMark(0xAAAAAAAA);
    TraceMark(0xAAAAAAAA);
    TraceMark(0xBBBBBBBB);
    TraceMark(0xBBBBBBBB);
    do_swap( point_a, point_b );
    TraceMark(0xBBBBBBBB);
    TraceMark(0xBBBBBBBB);
       TraceMark(0xAAAAAAAA);
    TraceMark(0xAAAAAAAA);
    cout << "Before swap, point_a.x = " << point_a.x << endl;
    cout << "             point_a.y = " << point_a.y << endl;
    cout << "    whereas, point_b.x = " << point_b.x << endl;
    cout << "             point_b.y = " << point_b.y << endl;

    // --------------------------------------
    // A bool-typed instantiation of the template
    cout << "Before swap, bool_t = " << bool_t << endl;
    cout << "    whereas, bool_f = " << bool_f << endl;
    TraceMark(0xAAAAAAAA);
    TraceMark(0xAAAAAAAA);
    TraceMark(0xBBBBBBBB);
    TraceMark(0xBBBBBBBB);
    do_swap( bool_t, bool_f );
    TraceMark(0xBBBBBBBB);
    TraceMark(0xBBBBBBBB);
       TraceMark(0xAAAAAAAA);
    TraceMark(0xAAAAAAAA);
    cout << "After  swap, bool_t = " << bool_t << endl;
    cout << "    whereas, bool_f = " << bool_f << endl << endl;

    // --------------------------------------
    // An int-typed instantiation of the template
    cout << "Before swap, int_a = " << int_a << endl;
    cout << "    whereas, int_b = " << int_b << endl;
    TraceMark(0xAAAAAAAA);
    TraceMark(0xAAAAAAAA);
    TraceMark(0xBBBBBBBB);
    TraceMark(0xBBBBBBBB);
    do_swap( int_a, int_b );
    TraceMark(0xBBBBBBBB);
    TraceMark(0xBBBBBBBB);
       TraceMark(0xAAAAAAAA);
    TraceMark(0xAAAAAAAA);
    cout << "After  swap, int_a = " << int_a << endl;
    cout << "    whereas, int_b = " << int_b << endl << endl;

    // --------------------------------------
    // A double-typed instantiation of the template
    cout << "Before swap, point_a_x = " << point_a_x << endl;
    cout << "    whereas, point_b_x = " << point_b_x << endl;
    TraceMark(0xAAAAAAAA);
    TraceMark(0xAAAAAAAA);
    TraceMark(0xBBBBBBBB);
    TraceMark(0xBBBBBBBB);
    do_swap( point_a_x, point_b_x );
    TraceMark(0xBBBBBBBB);
    TraceMark(0xBBBBBBBB);
       TraceMark(0xAAAAAAAA);
    TraceMark(0xAAAAAAAA);
    cout << "After  swap, point_a_x = " << point_a_x << endl;
    cout << "    whereas, point_b_x = " << point_b_x << endl << endl;
    
    //////////////////////////////////////////////////////////////////////
    // Template overloading ( Polymorphism )
    //  Char array -- string
    char pchars_1[] = "The first  one";
    char pchars_2[] = "The second one";
    cout << "Before swap, pchars_1[] = " << pchars_1 << endl;
    cout << "    whereas, pchars_2[] = " << pchars_2 << endl;
    TraceMark(0xAAAAAAAA);
    TraceMark(0xAAAAAAAA);
    TraceMark(0xBBBBBBBB);
    TraceMark(0xBBBBBBBB);
// 000B1793  mov         eax,0AAAAAAAAh  
// 000B1798  mov         eax,0AAAAAAAAh  
// 000B179D  mov         eax,0BBBBBBBBh  
// 000B17A2  mov         eax,0BBBBBBBBh  

    do_swap( pchars_1, pchars_2, (unsigned)strlen(pchars_1) );
// 000B17A7  lea         eax,[ebp-24h]  
// 000B17AA  mov         dword ptr [ebp-8Ch],eax  
// 000B17B0  mov         ecx,dword ptr [ebp-8Ch]  
// 000B17B6  add         ecx,1  
// 000B17B9  mov         dword ptr [ebp-90h],ecx

//  Compiler's optimization
// 000B17BF  mov         edx,dword ptr [ebp-8Ch] -\
// 000B17C5  mov         al,byte ptr [edx]        |
// 000B17C7  mov         byte ptr [ebp-91h],al    |
// 000B17CD  add         dword ptr [ebp-8Ch],1    |
// 000B17D4  cmp         byte ptr [ebp-91h],0     |
// 000B17DB  jne         000B17BF      -----------/

// 000B17DD  mov         ecx,dword ptr [ebp-8Ch]  
// 000B17E3  sub         ecx,dword ptr [ebp-90h]  
// 000B17E9  mov         dword ptr [ebp-98h],ecx  
// 000B17EF  mov         edx,dword ptr [ebp-98h]  
// 000B17F5  push        edx  
// 000B17F6  lea         eax,[ebp-64h]  
// 000B17F9  push        eax  
// 000B17FA  lea         ecx,[ebp-24h]  
// 000B17FD  push        ecx  
// 000B17FE  call        do_swap<char> (0B21D0h)  
// 000B1803  add         esp,0Ch  

    TraceMark(0xBBBBBBBB);
    TraceMark(0xBBBBBBBB);
    TraceMark(0xAAAAAAAA);
    TraceMark(0xAAAAAAAA);
// 000B1806  mov         eax,0BBBBBBBBh  
// 000B180B  mov         eax,0BBBBBBBBh  
// 000B1810  mov         eax,0AAAAAAAAh  
// 000B1815  mov         eax,0AAAAAAAAh  

    cout << "After  swap, pchars_1[] = " << pchars_1 << endl;
    cout << "    whereas, pchars_2[] = " << pchars_2 << endl << endl;

    return 0;    
}

/////////////////////////////////////////////////////
// Implicit instantiation
template< class T >
int  do_swap(T & a, T & b)
{
    T temp = a;
    a = b;
    b = temp;

    return 0;
}

// Template overloading
template< class T > int  do_swap(T * a, T * b, const unsigned int common_length )
{
    // Ensure Nonzero
    unsigned counter = common_length ? common_length : 1;

    T *p = new T[counter];


    if( !a || !b )
    {
        return -1;
    }

    for (unsigned int index = 0; index < counter; index++ )
    {
        p[index] = a[index];
        a[index] = b[index];
        b[index] = p[index];
    }

    if ( p && counter > 1 )
    {
        delete [] p;
    }
    else if ( p )
    {
        delete p;
    }

    return 0;
}

/////////////////////////////////////////////////////
//  Explicit Specialization
template< >
int    do_swap<type_location>( type_location & a, type_location & b )
{
    type_location    *temp = new type_location;

    temp->x = a.x;
    temp->y = a.y;

    a.x = b.x;
    a.y = b.y;
    
    b.x = temp->x;
    b.y = temp->y;

    delete temp;
    
    return 0;
}

/*
Portray onscreen
---------------------
Before swap, char_A = A
    whereas, char_B = B
After  swap, char_A = B
    whereas, char_B = A

Before swap, point_a.x = 1
             point_a.y = 2
    whereas, point_b.x = 5
             point_b.y = 2.3
Before swap, point_a.x = 5
             point_a.y = 2.3
    whereas, point_b.x = 1
             point_b.y = 2
Before swap, bool_t = 1
    whereas, bool_f = 0
After  swap, bool_t = 0
    whereas, bool_f = 1

Before swap, int_a = -1
    whereas, int_b = 0
After  swap, int_a = 0
    whereas, int_b = -1

Before swap, point_a_x = 1
    whereas, point_b_x = 5
After  swap, point_a_x = 5
    whereas, point_b_x = 1

Before swap, pchars_1[] = The first  one
    whereas, pchars_2[] = The second one
After  swap, pchars_1[] = The second one
    whereas, pchars_2[] = The first  one
---------------------
*/


//////////////////////////////////////////////////
/*
>>>>>>>  do_swap<char>:(000B2140)
000B2140  push        ebp  
000B2141  mov         ebp,esp  
000B2143  push        ecx  
000B2144  mov         eax,dword ptr [a]  
000B2147  mov         cl,byte ptr [eax]  
000B2149  mov         byte ptr [temp],cl  
000B214C  mov         edx,dword ptr [a]  
000B214F  mov         eax,dword ptr [b]  
000B2152  mov         cl,byte ptr [eax]  
000B2154  mov         byte ptr [edx],cl  
000B2156  mov         edx,dword ptr [b]  
000B2159  mov         al,byte ptr [temp]  
000B215C  mov         byte ptr [edx],al  
000B215E  xor         eax,eax  
000B2160  mov         esp,ebp  
000B2162  pop         ebp  
000B2163  ret  
*/

//////////////////////////////////////////////////
// do_swap<type_location>   (000B18A0)
/*
>>>>>>>  do_swap<type_location>:
000B18A0  push        ebp  
000B18A1  mov         ebp,esp  
000B18A3  sub         esp,0Ch  
000B18A6  push        10h  
000B18A8  call        dword ptr [__imp_operator new (0B30ECh)]  
000B18AE  add         esp,4  
000B18B1  mov         dword ptr [ebp-8],eax  
000B18B4  mov         eax,dword ptr [ebp-8]  
000B18B7  mov         dword ptr [temp],eax  
000B18BA  mov         ecx,dword ptr [temp]  
000B18BD  mov         edx,dword ptr [a]  
000B18C0  fld         qword ptr [edx]  
000B18C2  fstp        qword ptr [ecx]  
000B18C4  mov         eax,dword ptr [temp]  
000B18C7  mov         ecx,dword ptr [a]  
000B18CA  fld         qword ptr [ecx+8]  
000B18CD  fstp        qword ptr [eax+8]  
000B18D0  mov         edx,dword ptr [a]  
000B18D3  mov         eax,dword ptr [b]  
000B18D6  fld         qword ptr [eax]  
000B18D8  fstp        qword ptr [edx]  
000B18DA  mov         ecx,dword ptr [a]  
000B18DD  mov         edx,dword ptr [b]  
000B18E0  fld         qword ptr [edx+8]  
000B18E3  fstp        qword ptr [ecx+8]  
000B18E6  mov         eax,dword ptr [b]  
000B18E9  mov         ecx,dword ptr [temp]  
000B18EC  fld         qword ptr [ecx]  
000B18EE  fstp        qword ptr [eax]  
000B18F0  mov         edx,dword ptr [b]  
000B18F3  mov         eax,dword ptr [temp]  
000B18F6  fld         qword ptr [eax+8]  
000B18F9  fstp        qword ptr [edx+8]  
000B18FC  mov         ecx,dword ptr [temp]  
000B18FF  mov         dword ptr [ebp-0Ch],ecx  
000B1902  mov         edx,dword ptr [ebp-0Ch]  
000B1905  push        edx  
000B1906  call        dword ptr [__imp_operator delete (0B30F0h)]  
000B190C  add         esp,4  
000B190F  xor         eax,eax  
000B1911  mov         esp,ebp  
000B1913  pop         ebp  
000B1914  ret  
*/

// do_swap<char>            (000B2140) // This should be "<bool>", regardless of compiler optimization

// do_swap<int>             (000B2170)
/*
>>>>>>>  do_swap<int>:
000B2170  push        ebp  
000B2171  mov         ebp,esp  
000B2173  push        ecx  
000B2174  mov         eax,dword ptr [a]  
000B2177  mov         ecx,dword ptr [eax]  
000B2179  mov         dword ptr [temp],ecx  
000B217C  mov         edx,dword ptr [a]  
000B217F  mov         eax,dword ptr [b]  
000B2182  mov         ecx,dword ptr [eax]  
000B2184  mov         dword ptr [edx],ecx  
000B2186  mov         edx,dword ptr [b]  
000B2189  mov         eax,dword ptr [temp]  
000B218C  mov         dword ptr [edx],eax  
000B218E  xor         eax,eax  
000B2190  mov         esp,ebp  
000B2192  pop         ebp  
000B2193  ret  
*/

// do_swap<double>          (000B21A0)
/*
do_swap<double>:
000B21A0  push        ebp  
000B21A1  mov         ebp,esp  
000B21A3  sub         esp,8  
000B21A6  mov         eax,dword ptr [a]  
000B21A9  fld         qword ptr [eax]  
000B21AB  fstp        qword ptr [temp]  
000B21AE  mov         ecx,dword ptr [a]  
000B21B1  mov         edx,dword ptr [b]  
000B21B4  fld         qword ptr [edx]  
000B21B6  fstp        qword ptr [ecx]  
000B21B8  mov         eax,dword ptr [b]  
000B21BB  fld         qword ptr [temp]  
000B21BE  fstp        qword ptr [eax]  
000B21C0  xor         eax,eax  
000B21C2  mov         esp,ebp  
000B21C4  pop         ebp  
000B21C5  ret  
*/