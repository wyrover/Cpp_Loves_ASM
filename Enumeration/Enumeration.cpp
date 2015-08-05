//
//   Enumeration.cpp
//
//   Demonstrate How to use & implement the "Enumeration" in C/C++
//
//   19:30, August 05, 2015, by Mighten Dai<mighten.dai@gmail.com>
//

enum  Colors{ red, orange, yellow, blue, violet, indigo, ultraviolet };

int main( void )
{
	Colors flower_color;

	flower_color = red;
//	01211004  mov         dword ptr [flower_color],0 

	flower_color = orange;
//	0121100B  mov         dword ptr [flower_color],1  

	flower_color = yellow;
//	01211012  mov         dword ptr [flower_color],2

	flower_color = blue;
//	01211019  mov         dword ptr [flower_color],3  

	flower_color = violet;
//	01211020  mov         dword ptr [flower_color],4

	flower_color = indigo;
//	01211027  mov         dword ptr [flower_color],5  

	flower_color = ultraviolet;
//	0121102E  mov         dword ptr [flower_color],6  
	return 0;
}

//   Conclusion: 
//			"enumeration" is just a serial number sequence 
//	which begins with 0, regardless its detailed symbolic name inside itself. 
//