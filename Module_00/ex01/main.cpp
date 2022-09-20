#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"
#include "utils.hpp"

int	main(void)
{
	PhoneBook		phoneBookInstance;
	std::string		userInput;

	while (!std::cin.fail()) {
		std::cout << "# ";
		std::cin >> userInput;
		if (!userInput.compare("ADD"))
			phoneBookInstance.add();
		else if (!userInput.compare("SEARCH"))
			phoneBookInstance.search();
		else if (!userInput.compare("EXIT"))
			break ;
		else if (!std::cin.fail())
			unknownCmd();
		userInput.clear();
	}
}
