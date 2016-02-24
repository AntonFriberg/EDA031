#ifndef TAGREMOVER_H
#define TAGREMOVER_H

#include <string>
#include <iostream>

class TagRemover {
public:
	TagRemover(std::istream& cin);
	void print(std::ostream& cout);

private:
	std::string input;
};

#endif
