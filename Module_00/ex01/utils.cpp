#include "PhoneBook.class.hpp"

#define SPACE	" \t\n\r\f\v"

std::string&	strtrim(std::string& s) {
	s.erase(s.find_last_not_of(SPACE) + 1);
	s.erase(0, s.find_first_not_of(SPACE));
	return (s);
}

void unknownCmd(void) {
	std::cout << "Unknown command." << std::endl << \
		"Available commands are: " << std::endl << \
		"ADD, SEARCH and EXIT." << std::endl;
}
