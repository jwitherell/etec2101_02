#include <vector>
#include <iostream>
#include <string>
#include <algorithm>			// contains find

int main(int argc, char** argv)
{
	std::vector<std::string> slist = { "abe", "bob", "carl", "diane", "erin" };
	slist.push_back("frank");

	// Output all values without assuming anything about the length
	std::cout << "for loop\n";
	for (int i = 0; i < slist.size(); i++)
		std::cout << "\t" << slist.at(i) << "\n";

	// But...some data structures (sets, maps) that don't have an at method
	// An iterator is the way to "traverse" all the data in that container.  
	std::cout << "iterator loop\n";
	std::vector<std::string>::iterator slist_iterator;		// an iterator
											// object, and it refers to a value
											// (a lot like a pointer does)
	slist_iterator = slist.begin();	//we're here attaching our iterator to 
									// slist and making it refer to the first value
									// value (or if it's empty, or the null-type
									// value if the list were empty.
	while (slist_iterator != slist.end())	// Is our iterator pointing to 
											// end, which is kind of like a null
											// iterator value
	{
		std::string cur_string = *slist_iterator;	// Looks like a de-reference
													//  but is actually an operator
													//  method in iterator class
		std::cout << "\t" << cur_string << "\n";
		++slist_iterator;			// Advances to the next spot in the vector,
									// or if we're now at the end, sets our
									// iterator to the special null-type value.
	}

	// If you have an iterator like the vector class has, we can do this.  This only
	// works if you have a class with an associated iterator like vector.
	std::cout << "???\n";
	for (std::string s : slist)				// # like     for s in slist:    in python
		std::cout << "\t" << s << "\n";


	// The find algorithm doesn't tie itself to the vector class b/c it uses
	// iterators (works 100% the same for sets, maps, linked_lists, etc.)
	slist_iterator = std::find(slist.begin(), slist.end(), "danger");
	if (slist_iterator != slist.end())
		std::cout << "we found danger\n";
	else
		std::cout << "we didn't find danger\n";
	slist_iterator = std::find(slist.begin(), slist.end(), "carl");
	if (slist_iterator != slist.end())
		std::cout << "we found carl\n";
	else
		std::cout << "we didn't find carl\n";

	// An example of addition
	slist_iterator = slist.begin() + 2;		// now referring to carl

	// We remove (from ANY std:: data structure like this)
	slist_iterator = slist.erase(slist_iterator);
	std::cout << "carl was erased and now the iterator refers to " << *slist_iterator << "\n";

	// We'll resume @ 12:40pm

	return 0;
}