#pragma once
#include <string>

namespace example
{
	class Foo
	{
	private:
		std::string name;
		unsigned int age;
	public:
		Foo(std::string n, unsigned int i);
		Foo();
		void set_name(std::string n);
		void set_age(unsigned int i);
		std::string get_name();
		unsigned int get_age();

		void add_a_year();

		// This makes the some_func function a "friend"
		friend void some_func(Foo& fref);

		// This makes ALL of the Person class a friend
		friend class Person;

		// An operator overload
		Foo operator+ (int v);

		// The parameter is the thing on the right hand side of the + from caller's view
		Foo operator+ (Foo& other_foo);


	};


	// An operator FUNCTION -- the int is on the left, Foo on the right
	Foo operator+(int v, Foo& fref);


	// A function
	void some_func(Foo& fref);
}
