#include <foo.h>

example::Foo::Foo(std::string n, unsigned int i) : name(n), age(i)
{
	// Now the variables have their constructors run, values assigned
	// when we create the Foo object.  If we had a reference for example,
	// it would have to be initialized this way.  Also often used
	// in inheritance.

	// The variable is already created (the string constructor has run,
	// the integer doesn't have a constructor).  We're here, over-writing
	// those values with new ones.  We can be faster way by doing the above
	//name = n;
	///age = i;
}


example::Foo::Foo() : name("???"), age(0)
{
	// Empty, on purpose.
}


void example::Foo::set_name(std::string n)
{
	name = n;
}


void example::Foo::set_age(unsigned int i)
{
	age = i;
}


std::string example::Foo::get_name()
{
	return name;
}


unsigned int example::Foo::get_age()
{
	return age;
}

void example::Foo::add_a_year()
{
	age++;
}

example::Foo example::Foo::operator+(int v)
{
	Foo new_foo(name, age + v);
	return new_foo;
}

example::Foo example::Foo::operator+ (Foo& other_foo)
{
	Foo new_foo(name + "-" + other_foo.name, (age + other_foo.age) / 2);
	return new_foo;
}



// Body of the FUNCTIONS
example::Foo example::operator+(int v, example::Foo& fref)
{
	// I want this to be commutative, so I do this
	return fref + v;
}

void example::some_func(example::Foo& fref)
{
	// This is a function, an "outside entity".  Until we add
	// the friend statement, we can't do this.
	fref.age++;
}