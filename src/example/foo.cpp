#include <foo.h>
#include <iostream>


// This new sytax assigns a value as the thing is created.  This is 
// mandatory for references.  Also mandatory often when doing inheritance
// (and your base class has no default constructors).  This syntax only
// makes sense in constructors
example::Foo::Foo(std::string n, unsigned a) : name(n), age(a)
{
	// The above is an alternative to this
	//name = n;
	//age = a;
}


example::Foo::Foo() : name("???"), age(0)
{
	// Intentionally empty
}


example::Foo::~Foo()
{

}

void example::Foo::some_method()
{
	std::cout << "A foo with name=" << name << " and age=" << age << "\n";
}


example::Foo example::Foo::operator+(int i)
{
	Foo new_foo(name, age + i);
	return new_foo;
}



// This is a FUNCTION, not a method!
example::Foo example::operator-(int i, example::Foo right_foo)
{
	// We want to do something like this, but we don't have access
	// to the private memebers of right_foo, so can't
	//Foo return_value;
	//return_value.name = right_foo.name;
	//return_value.age = right_foo.age + i;
	//return return_value;

	// We can, however, use any public methods of right_foo, like the *other*
	// plus operator, like this: 
	return right_foo + (-i);
}