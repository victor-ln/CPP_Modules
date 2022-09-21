#include "utils.hpp"

#define SPACE	L" \t\n\r\f\v"

std::wstring&	strtrim(std::wstring& s) {
	s.erase(s.find_last_not_of(SPACE) + 1);
	s.erase(0, s.find_first_not_of(SPACE));
	return (s);
}

void unknownCmd(void) {
	std::wcout << L"Unknown command." << std::endl;
	help();
}

void	help(void) {
	std::wcout << L"Available commands are ";
	std::wcout << std::right << std::setfill(L'.') << std::setw(12);
	std::wcout << L" : " << std::endl << std::endl;
	std::wcout << L"ADD\t- Add a contact to the phone book (It can store a maximum of 8 contacts)." << std::endl;
	std::wcout << L"SEARCH\t- Display contacts information in a table, then you can choose a specific one for more details." << std::endl;
	std::wcout << L"EXIT\t- Exits the program (all contacts are lost)." << std::endl;
}
