#include "PhoneBook.hpp"
#include "utils.hpp"

#define INDEX_INPUT_MESSAGE	L"Enter an index for details "
#define BORDER	L"_____________________________________________"

PhoneBook::PhoneBook(void) {
	this->contactsAdded = 0;
	this->last = 0;
}

void	PhoneBook::getString(const wchar_t *info, std::wstring& to) {
	std::wstring			message;

	message.append(L"Enter contact ").append(info);
	while (!std::wcin.eof() && to.empty()) {
		std::wcout << message;
		std::wcout << std::right << std::setfill(L'.') << std::setw(35 - message.length());
		std::wcout << L" : " << std::endl;
		std::wcin.clear();
		std::wcin.sync();
		std::getline(std::wcin, to);
		strtrim(to);
	}
}

void	PhoneBook::getNumber(const wchar_t *info, std::wstring& to) {
	std::wstring			message;

	message.append(L"Enter contact ").append(info);
	while (!std::wcin.eof() && to.empty()) {
		std::wcout << message;
		std::wcout << std::right << std::setfill(L'.') << std::setw(35 - message.length());
		std::wcout << L" : " << std::endl;
		std::wcin.clear();
		std::wcin.sync();
		std::getline(std::wcin, to);
		strtrim(to);
		for (auto c : to) {
			if (!std::isdigit(c) && c != '-' && c != ' ') {
				std::wcout << L"Invalid input" << std::endl;
				to.clear();
				break ;
			}
		}
	}
}

void	PhoneBook::add(void) {
	Contact	*lastContact = this->getLastContact();

	lastContact->clearContactData();
	this->getString(L"First name ", lastContact->firstName);
	this->getString(L"Last name ", lastContact->lastName);
	this->getString(L"Nickname ", lastContact->nickName);
	this->getString(L"Darkest secret ", lastContact->darkestSecret);
	this->getNumber(L"Phone Number ", lastContact->phoneNumber);
	if (!std::wcin.eof()) {
		std::wcout << L"Contact added successfully" << std::endl;
		if (this->contactsAdded < 8)
			this->contactsAdded++;
	}
}

static inline void	displayLine(void) {
	std::wcout << std::setw(1) << L"|";
	std::wcout << std::setfill(L' ') << std::setw(10);
}

static inline void	displayTableBorder(void) {
	static	std::wstring	border(BORDER);

	std::wcout << border << std::endl;
}

void	displayTableHead(void) {
	displayLine();
	std::wcout << std::right << L"Index";
	displayLine();
	std::wcout << std::right << L"Firstname";
	displayLine();
	std::wcout << std::right << L"Lastname";
	displayLine();
	std::wcout << std::right << L"Nickname";
	displayLine();
	std::wcout << std::endl;
}

void	displayTableContent(std::wstring s) {
	displayLine();
	if (s.length() > 10)
		std::wcout << std::left << std::setfill(L'.') << std::setw(10) << s.substr(0, 9);
	else
		std::wcout << std::right << s;
}

int	PhoneBook::getContactIndexInput(void) {
	static std::wstring	message(INDEX_INPUT_MESSAGE);
	std::wstring		input;
	int					index;

	while (!std::wcin.eof() && input.empty()) {
		std::wcout << std::endl << message;
		std::wcout << std::right << std::setfill(L'.') << std::setw(35 - message.length());
		std::wcout << L" : " << std::endl;
		std::wcin.clear();
		std::wcin.sync();
		std::getline(std::wcin, input);
		strtrim(input);
		if (input.empty())
			continue ;
		try {
			index = std::stoi(input);
		} catch (const std::out_of_range & e) {
			std::wcout << "Invalid input, index out of range" << std::endl;
			input.clear();
			continue ;
		} catch (const std::invalid_argument & e) {
			std::wcout << "Invalid input" << std::endl;
			input.clear();
			continue ;
		}
		if (index < 0 || index >= this->contactsAdded) {
			std::wcout << "Invalid input, index out of range" << std::endl;
			input.clear();
		}
	}
	return (index);
}

void	PhoneBook::displayContactInfo(void) {
	Contact	*contact = this->getContactByIndex(this->getContactIndexInput());

	if (std::wcin.eof())
		return ;
	std::wcout << std::setw(0);
	std::wcout << std::endl;
	std::wcout << L"Firstname\t\t: " << contact->firstName << std::endl;
	std::wcout << L"Lastname\t\t: " << contact->lastName << std::endl;
	std::wcout << L"Nickname\t\t: " << contact->nickName << std::endl;
	std::wcout << L"Darkest Secret\t\t: " << contact->darkestSecret << std::endl;
	std::wcout << L"Phone number\t\t: " << contact->phoneNumber << std::endl;
	std::wcout << std::endl;
}

void	PhoneBook::search(void) {
	Contact *contact;

	if (!this->contactsAdded) {
		std::wcout << L"There's no contacts added yet" << std::endl;
		return ;
	}
	displayTableBorder();
	displayTableHead();
	for (int index = 0; index < this->contactsAdded; index++) {
		contact = this->getContactByIndex(index);
		displayLine();
		std::wcout << std::right << index;
		displayTableContent(contact->firstName);
		displayTableContent(contact->lastName);
		displayTableContent(contact->nickName);
		displayLine();
		std::wcout << std::setw(0);
		std::wcout << std::endl;
	}
	displayTableBorder();
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
