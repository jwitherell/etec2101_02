#include <foo.h>

int main(int argc, char** argv)
{
	example::Foo a_foo("Bob", 15);
	example::some_func(a_foo);
	
	example::Foo b_foo = a_foo + 5;
	example::Foo d_foo = 5 + a_foo;
	example::Foo c_foo = a_foo + b_foo;

	return 0;
}