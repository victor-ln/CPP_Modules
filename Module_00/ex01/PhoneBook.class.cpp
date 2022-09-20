#include "PhoneBook.class.hpp"
#include "utils.hpp"

#define INDEX_INPUT_MESSAGE	"Enter an index for details"

PhoneBook::PhoneBook(void) {
	this->contactsAdded = 0;
	this->last = 0;
}

void	PhoneBook::getString(const char *info, std::string& to) {
	std::string			message;

	message.append("Enter contact ").append(info);
	while (!std::cin.fail() && to.empty()) {
		std::cout << message;
		std::cout << std::right << std::setfill('.') << std::setw(35 - message.length());
		std::cout << " : ";
		std::cin >> to;
		strtrim(to);
	}
}

void	PhoneBook::getNumber(const char *info, std::string& to) {
	std::string			message;

	message.append("Enter contact ").append(info);
	while (!std::cin.fail() && to.empty()) {
		std::cout << message;
		std::cout << std::right << std::setfill('.') << std::setw(35 - message.length());
		std::cout << " : ";
		std::cin >> to;
		strtrim(to);
		for (auto c : to) {
			if (!std::isdigit(c) && c != '-' && c != ' ') {
				std::cout << "Invalid input" << std::endl;
				to.clear();
				break ;
			}
		}
	}
}

void	PhoneBook::add(void) {
	Contact	*lastContact = this->getLastContact();

	lastContact->clearContactData();
	this->getString("First name ", lastContact->firstName);
	this->getString("Last name ", lastContact->lastName);
	this->getString("Nickname ", lastContact->nickName);
	this->getString("Darkest secret ", lastContact->darkestSecret);
	this->getNumber("Phone Number ", lastContact->phoneNumber);
	if (!std::cin.fail()) {
		std::cout << "Contact added successfully" << std::endl;
		if (this->contactsAdded < 8)
			this->contactsAdded++;
	}
}

static inline void	displayLine(void) {
	std::cout << std::setw(1) << "|";
	std::cout << std::setfill(' ') << std::setw(10);
}

void	displayTableBorder(void) {
	static	std::string	border;

	if (!border.length())
		border.insert(0, 45, '_');
	std::cout << border << std::endl;
}

void	displayTableHead(void) {
	displayLine();
	std::cout << std::right << "Index";
	displayLine();
	std::cout << std::right << "Firstname";
	displayLine();
	std::cout << std::right << "Lastname";
	displayLine();
	std::cout << std::right << "Nickname";
	displayLine();
	std::cout << std::endl;
}

void	displayTableContent(std::string s) {
	if (s.length() > 10)
		std::cout << std::left << std::setfill('.') << std::setw(10) << s.substr(0, 9);
	else
		std::cout << std::right << s;
}

int	PhoneBook::getContactIndexInput(void) {
	static std::string	message(INDEX_INPUT_MESSAGE);
	std::string			input;
	int					index;

	while (!std::cin.fail() && input.empty()) {
		std::cout << message;
		std::cout << std::right << std::setfill('.') << std::setw(35 - message.length());
		std::cout << " : ";
		std::cin >> input;
		strtrim(input);
		if (input.empty())
			continue ;
		try {
			index = std::stoi(input);
		} catch (const std::out_of_range & e) {
			std::cout << "Invalid input, index out of range" << std::endl;
			input.clear();
			continue ;
		} catch (const std::invalid_argument & e) {
			std::cout << "Invalid input" << std::endl;
			input.clear();
			continue ;
		}
		if (index < 0 || index >= this->contactsAdded) {
			std::cout << "Invalid input, index out of range" << std::endl;
			input.clear();
		}
	}
	return (index);
}

void	PhoneBook::displayContactInfo(void) {
	Contact	*contact = this->getContactByIndex(this->getContactIndexInput());

	if (std::cin.fail())
		return ;
	std::cout << "Firstname\t\t: " << contact->firstName << std::endl;
	std::cout << "Lastname\t\t: " << contact->lastName << std::endl;
	std::cout << "Nickname\t\t: " << contact->nickName << std::endl;
	std::cout << "Darkest Secret\t\t: " << contact->darkestSecret << std::endl;
	std::cout << "Phone number\t\t: " << contact->phoneNumber << std::endl;
}

void	PhoneBook::search(void) {
	Contact *contact;

	if (!this->contactsAdded) {
		std::cout << "There's no contacts added yet" << std::endl;
		return ;
	}
	displayTableBorder();
	displayTableHead();
	for (int index = 0; index < 8; index++)
	{
		contact = this->getContactByIndex(index);
		if (contact->firstName.empty())
			continue ;
		displayLine();
		std::cout << std::right << index;
		displayLine();
		displayTableContent(contact->firstName);
		displayLine();
		displayTableContent(contact->lastName);
		displayLine();
		displayTableContent(contact->nickName);
		displayLine();
		std::cout << std::setw(0);
		std::cout << std::endl;
	}
	displayTableBorder();
	std::cout << std::endl;
	std::cout << std::setw(0);
	this->displayContactInfo();
}

inline Contact *PhoneBook::getLastContact(void) {
	if (this->last == 8)
		this->last = 0;
	return (this->contacts + this->last++);
}

inline Contact *PhoneBook::getContactByIndex(int index) {
	if (index < 0 || index > 7)
		index = 0;
	return (this->contacts + index);
}
