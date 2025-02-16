#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <person.h>

int main(int argc, char** argv)
{
	std::vector<std::string> slist;
	slist.push_back("abe");
	slist.push_back("bob");
	slist.push_back("carl");
	slist.push_back("diane");

	std::cout << "iterating without an iterator\n";
	for (int i = 0; i < slist.size(); i++)
	{
		std::cout << "\t" << slist[i] << "\n";		// Most containers don't have
												    // this!  What do we do in that
													// case?  std::maps, std::sets
													// for example.
	}


	// An iterator is a way to access all values in a data struture
	// in some predictable fashion.  
	std::cout << "iterating with an iterator\n";
	std::vector<std::string>::iterator my_iterator;
	my_iterator = slist.begin();		// Make the iterator "point" to the 
										// first item (if any)
	while (my_iterator != slist.end())		// Keep going until we've reached
											// the end of slist
	{
		std::string cur = *my_iterator;		// Make a copy of current value
		std::cout << "\t" << cur << "\n";

		++my_iterator;						// Advance to the next item.  If
											// we are on the last item, this
											// makes my_iterator a special 
											// null-like "end" value.
	}


	// To erase an item, you must use iterators
	my_iterator = slist.begin() + 1;		// my_itertor referring to bob
	std::cout << "iterator at " << *my_iterator << "\n";
	slist.erase(my_iterator);
	std::cout << "slist is now\n";
	for (int i = 0; i < slist.size(); i++)
		std::cout << "\t" << slist[i] << "\n";

	// Find (in algorithm) -- this is not custom to vectors, it works
	// for any data structure
	my_iterator = std::find(slist.begin(), slist.end(), "diane");
	if (my_iterator != slist.end())
		std::cout << "Found diane\n";
	else
		std::cout << "Couldn't find diane";
	my_iterator = std::find(slist.begin(), slist.end(), "xxx");
	if (my_iterator != slist.end())
		std::cout << "Found xxx";
	else
		std::cout << "Couldn't find xxx\n";

	// **IF** we have an iterator for a data structure, we can
	// use a for-each loop
	std::cout << "for-each loop\n";
	for (std::string s : slist)				// like for s in slist (in python)
		std::cout << "\t" << s << "\n";


	std::vector<example::Person> plist = { example::Person("Bob", "Smith", 101, 15.0f),
										  example::Person("Joe", "Young", 102, 16.0f),
										  example::Person("Deb", "East", 103, 13.5f) };
	for (example::Person& p : plist)
	{
		std::cout << p.get_id() << "\n";
	}
	std::vector<example::Person>::iterator p_it = plist.begin();
	while (p_it != plist.end())
	{
		std::cout << p_it->get_id() << "\n";
		++p_it;
	}
}