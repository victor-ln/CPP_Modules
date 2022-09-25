#include "PhoneBook.hpp"

#define UNDERLINES			L"_____________________________________________"
#define OVERLINES			L"‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾"
#define MIDDLELINES			L"|----------+----------+----------+----------|"
#define PHONE_DIGITS		L"0123456789 -"
#define DIGITS				L"0123456789"

PhoneBook::PhoneBook(void) {
	this->_contactsAdded = 0;
	this->_last = 0;
}

void	PhoneBook::add(void) {
	Contact	*lastContact = this->_getLastContact();

	lastContact->clearContactData();
	this->_getString(L"Enter contact First name ", lastContact->firstName);
	this->_getString(L"Enter contact Last name ", lastContact->lastName);
	this->_getString(L"Enter contact Nickname ", lastContact->nickName);
	this->_getString(L"Enter contact Darkest secret ", lastContact->darkestSecret);
	this->_getPhoneNumber(L"Enter contact Phone Number ", lastContact->phoneNumber);
	if (!std::wcin.eof()) {
		std::wcout << L"✅ Contact added successfully" << std::endl;
		if (this->_contactsAdded < 8)
			this->_contactsAdded++;
	}
}

void	PhoneBook::search(void) {
	if (!this->_contactsAdded) {
		std::wcout << L"💥 There's no contacts added yet" << std::endl;
		return ;
	}
	this->_displayTableUnderlines();
	this->_displayTableHead();
	Contact	*contact;
	int		index = 0;
	while (index < this->_contactsAdded) {
		contact = this->_getContactByIndex(index);
		this->_displayPipe();
		std::wcout << std::right << index;
		this->_displayTableContent(contact->firstName);
		this->_displayTableContent(contact->lastName);
		this->_displayTableContent(contact->nickName);
		this->_displayPipe();
		std::wcout << std::endl;
		if (++index < this->_contactsAdded)
			this->_displayTableMiddleLines();
	}
	this->_displayTableOverlines();
	this->_displayContactInfo();
}

inline Contact *PhoneBook::_getLastContact(void) {
	if (this->_last == 8)
		this->_last = 0;
	return (this->_contact + this->_last++);
}

inline Contact *PhoneBook::_getContactByIndex(int index) {
	return (this->_contact + index);
}

inline void	PhoneBook::_displayPipe(void) {
	std::wcout << std::setw(1) << L"|";
	std::wcout << std::setfill(L' ') << std::setw(10);
}

inline void	PhoneBook::_displayTableUnderlines(void) {
	std::wcout << UNDERLINES << std::endl;
}

inline void	PhoneBook::_displayTableOverlines(void) {
	std::wcout << OVERLINES << std::endl;
}

inline void	PhoneBook::_displayTableMiddleLines(void) {
	std::wcout << MIDDLELINES << std::endl;
}

void	PhoneBook::_getString(std::wstring message, std::wstring& to) {
	while (!std::wcin.eof() && !getInput(message, to))
		;
}

void	PhoneBook::_getPhoneNumber(std::wstring message, std::wstring& to) {
	while (!std::wcin.eof() && to.empty()) {
		if (getInput(message, to)) {
			if (to.find_first_not_of(PHONE_DIGITS) != std::wstring::npos || \
				to.find_first_of(DIGITS) == std::wstring::npos) {
				std::wcout << L"💥 Invalid input" << std::endl;
				to.clear();
			}
		}
	}
}

inline void	PhoneBook::_leftZerosTrim(std::wstring& input) {
	if (input.find_first_not_of(L"0") != std::wstring::npos)
		if (input.find_first_of(L"0") < input.find_first_not_of(L"0"))
			input.erase(0, input.find_first_not_of(L"0"));
}

int	PhoneBook::_convertStrIndexToIntIndex(std::wstring input) {
	char	tmp[input.length() + 1];
	size_t	i = 0;

	while (i < input.length()) {
		tmp[i] = (char)input.at(i);
		i++;
	}
	tmp[i] = 0;
	return (atoi(tmp));
}

int	PhoneBook::_getContactIndexInput(void) {
	std::wstring		input;
	int					index = 0;

	while (!std::wcin.eof() && input.empty()) {
		if (!getInput(L"Enter an index for details ", input))
			continue ;
		if (input.find_first_not_of(DIGITS) != std::wstring::npos) {
			std::wcout << L"💥 Invalid input" << std::endl;
			input.clear();
			continue ;
		}
		this->_leftZerosTrim(input);
		index = this->_convertStrIndexToIntIndex(input);
		if (index < 0 || index >= this->_contactsAdded) {
			std::wcout << L"💥 Invalid input, index out of range" << std::endl;
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
	this->_displayTableMiddleLines();
}

void	PhoneBook::_displayTableContent(std::wstring s) {
	this->_displayPipe();
	if (s.length() > 10)
		std::wcout << s.substr(0, 9) + L".";
	else
		std::wcout << std::right << s;
}

void	PhoneBook::_displayContactInfo(void) {
	Contact	*contact = this->_getContactByIndex(this->_getContactIndexInput());

	if (std::wcin.eof())
		return ;
	std::wcout << std::setw(0) << std::endl;
	std::wcout << L"Firstname\t\t: " << contact->firstName << std::endl;
	std::wcout << L"Lastname\t\t: " << contact->lastName << std::endl;
	std::wcout << L"Nickname\t\t: " << contact->nickName << std::endl;
	std::wcout << L"Darkest Secret\t\t: " << contact->darkestSecret << std::endl;
	std::wcout << L"Phone number\t\t: " << contact->phoneNumber << std::endl;
	std::wcout << std::endl;
}
