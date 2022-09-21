#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "utils.hpp"

int	main(void)
{
	PhoneBook		phoneBookInstance;
	std::wstring	userInput;

	std::ios_base::sync_with_stdio(false);
	std::wcin.imbue(std::locale("en_US.UTF-8"));
	std::wcout.imbue(std::locale("en_US.UTF-8"));
	help();
	while (!std::wcin.eof()) {
		std::wcout << std::endl << L"Enter a command : ";
		std::wcout << std::right << std::setfill(L'.') << std::setw(17);
		std::wcout << L" : " << std::endl;
		std::wcin.clear();
		std::wcin.sync();
		std::getline(std::wcin, userInput);
		userInput = strtrim(userInput);
		if (userInput.empty())
			continue ;
		if (!userInput.compare(L"ADD"))
			phoneBookInstance.add();
		else if (!userInput.compare(L"SEARCH"))
			phoneBookInstance.search();
		else if (!userInput.compare(L"EXIT"))
			break ;
		else if (!std::wcin.eof())
			unknownCmd();
		userInput.clear();
	}
}
