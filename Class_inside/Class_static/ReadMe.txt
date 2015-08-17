# Class static

static variable
static function 


==============================================================
class    DEMO_static
{
private:
    static unsigned int    m_obj_counter;

public:
	DEMO_static() { ++DEMO_static::m_obj_counter; }
	static unsigned int    get_counter();
};

// It is rather important,
//   without it will trigger an :
//  error LNK2001: unresolved external symbol "private: static unsigned int DEMO_static::m_obj_counter" 
unsigned int DEMO_static::m_obj_counter = 0;

==============================================================