#include <foo.h>

namespace example
{
	void func(Foo& fref)
	{
		fref.age++;		// Can't NORMALLY do this, but the friend statement 
						// allows it.
	}
}


int main(int argc, char** argv)
{
	example::Foo f("Bob", 23);
	//f.age++;			// can't do b/c its private
	//::weird_func(f);

	example::Foo g = f + 2;
	example::Foo h = 2 + f;
	example::func(g);
	return 0;
}