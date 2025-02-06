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
	};


	// A function
	void some_func(Foo& fref);
}
