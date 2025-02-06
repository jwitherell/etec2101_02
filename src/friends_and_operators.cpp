#include <foo.h>

int main(int argc, char** argv)
{
	example::Foo a_foo("Bob", 15);
	example::some_func(a_foo);

	return 0;
}