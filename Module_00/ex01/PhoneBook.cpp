#include "PhoneBook.hpp"

#define INDEX_INPUT_MESSAGE	L"Enter an index for details "
#define BORDER				L"_____________________________________________"
#define PHONE_DIGITS		L"0123456789 -"
#define DIGITS				L"0123456789"

PhoneBook::PhoneBook(void) {
	this->_contactsAdded = 0;
	this->_last = 0;
}

void	PhoneBook::add(void) {
	Contact	*lastContact = this->_getLastContact();

	lastContact->clearContactData();
	this->_getString(L"First name ", lastContact->firstName);
	this->_getString(L"Last name ", lastContact->lastName);
	this->_getString(L"Nickname ", lastContact->nickName);
	this->_getString(L"Darkest secret ", lastContact->darkestSecret);
	this->_getNumber(L"Phone Number ", lastContact->phoneNumber);
	if (!std::wcin.eof()) {
		std::wcout << L"Contact added successfully" << std::endl;
		if (this->_contactsAdded < 8)
			this->_contactsAdded++;
	}
}

void	PhoneBook::search(void) {
	Contact *contact;

	if (!this->_contactsAdded) {
		std::wcout << L"There's no contacts added yet" << std::endl;
		return ;
	}
	this->_displayTableBorder();
	this->_displayTableHead();
	for (int index = 0; index < this->_contactsAdded; index++) {
		contact = this->_getContactByIndex(index);
		this->_displayPipe();
		std::wcout << std::right << index;
		this->_displayTableContent(contact->firstName);
		this->_displayTableContent(contact->lastName);
		this->_displayTableContent(contact->nickName);
		this->_displayPipe();
		std::wcout << std::setw(0);
		std::wcout << std::endl;
	}
	this->_displayTableBorder();
	this->_displayContactInfo();
}

inline Contact *PhoneBook::_getLastContact(void) {
	if (this->_last == 8)
		this->_last = 0;
	return (this->_contact + this->_last++);
}

inline Contact *PhoneBook::_getContactByIndex(int index) {
	if (index < 0 || index > 7)
		index = 0;
	return (this->_contact + index);
}

inline void	PhoneBook::_displayPipe(void) {
	std::wcout << std::setw(1) << L"|";
	std::wcout << std::setfill(L' ') << std::setw(10);
}

inline void	PhoneBook::_displayTableBorder(void) {
	static	std::wstring	border(BORDER);

	std::wcout << border << std::endl;
}

void	PhoneBook::_getString(const wchar_t *info, std::wstring& to) {
	std::wstring			message;

	message.append(L"Enter contact ").append(info);
	while (!std::wcin.eof() && !getInput(message, to))
		;
}

void	PhoneBook::_getNumber(const wchar_t *info, std::wstring& to) {
	std::wstring			message;

	message.append(L"Enter contact ").append(info);
	while (!std::wcin.eof() && to.empty()) {
		if (getInput(message, to)) {
			if (to.find_first_not_of(PHONE_DIGITS) != std::string::npos) {
				std::wcout << L"Invalid input" << std::endl;
				to.clear();
			}
		}
	}
}

int	PhoneBook::_getContactIndexInput(void) {
	static std::wstring	message(INDEX_INPUT_MESSAGE);
	std::wstring		input;
	int					index;

	index = 0;
	while (!std::wcin.eof() && input.empty()) {
		if (!getInput(message, input))
			continue ;
		if (input.find_first_not_of(DIGITS) != std::string::npos) {
			std::wcout << "Invalid input" << std::endl;
			input.clear();
			continue ;
		}
		if (input.find_first_of(L"0") < input.find_first_not_of(L"0") && \
			input.find_first_not_of(L"0") != std::wstring::npos)
			input.erase(0, input.find_first_not_of(L"0"));
		index = atoi((char *)input.c_str());
		if (index < 0 || index >= this->_contactsAdded) {
			std::wcout << "Invalid input, index out of range" << std::endl;
			input.clear();
		}
	}
	return (index);
}

void	PhoneBook::_displayTableHead(void) {
	this->_displayTableContent(L"Index");
	this->_displayTableContent(L"Firstname");
	this->_displayTableContent(L"Lastname");
	this->_displayTableContent(L"Nickname");
	this->_displayPipe();
	std::wcout << std::endl;
}

void	PhoneBook::_displayTableContent(std::wstring s) {
	this->_displayPipe();
	if (s.length() > 10)
		std::wcout << std::left << std::setfill(L'.') << std::setw(10) << s.substr(0, 9);
	else
		std::wcout << std::right << s;
}

void	PhoneBook::_displayContactInfo(void) {
	Contact	*contact = this->_getContactByIndex(this->_getContactIndexInput());

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
