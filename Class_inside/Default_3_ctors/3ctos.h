//
//  3ctors.h
//
//   It is necessary to create the 3 ctors
//        especially when operator new/delete under use.
//
//   11:01 AM, Aug 18, 2015, by Mighten Dai <mighten.dai@gmail.com>
//

class   XXX
{
private:
    // TODO: private member definition here.

public:
    XXX();
	XXX( XXX & xxx );
	XXX & operator = ( XXX & xxx);
	
};