#pragma once
#include <string>

// A "forward declaration" to a function defined elsewhere.


namespace example
{
	void func();

	class Foo
	{
	private:
		std::string name;
		unsigned int age;
	public:
		Foo(std::string n, unsigned a);
		Foo();
		~Foo();

		// Called when the user does this:
		// some_foo + i, and that it returns a Foo object
		Foo operator+(int i);


		void some_method();

		friend void func(Foo& fref);	// We are giving this function (in the
										// example namespace) normally unauthorized
										// access to our attributes


		friend class AnotherClass;		// This class is defined
										// elsewhere and in all methods,attributes,
										// etc. IT has access to private things
										// declared here.
		
		// This one is "weird" in that we're making the function here in the
		// class, but it's considered to be OUTSIDE the class for access rules
		// BUT we're making it a friend.  Weird also in that it's put in the
		// GLOBAL NAMESPACE
		friend void weird_func(Foo& a_foo)
		{
			a_foo.age += 2;
		}


		// This is making a function (like below) that is outside the
		// class, but has ALL access.
		friend Foo operator+(int i, Foo& right_foo)
		{
			Foo return_val;
			// We wouldn't be able to do the following line if we were a 
			// normal function, but can since we're a friend
			return_val.age = right_foo.age + i;
			return return_val;
		}
	};


	// Make a FUNCTION to do "reverse subtract"
	Foo operator-(int i, Foo right_foo);
}