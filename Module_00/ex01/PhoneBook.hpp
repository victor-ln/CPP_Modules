#ifndef PHONEBOOK_HPP_
# define PHONEBOOK_HPP_

#include <cstdlib>
#include <iomanip>
#include <iostream>

#include "Contact.hpp"

class PhoneBook {

	public:

		PhoneBook(void);

		void	add(void);
		void	search(void);

	private:
		Contact		_contact[8];
		int			_last;
		int			_contactsAdded;

		Contact	*_getLastContact(void);
		Contact	*_getContactByIndex(int index);
		void	_getString(const wchar_t *info, std::wstring& to);
		void	_getPhoneNumber(const wchar_t *info, std::wstring& to);
		void	_displayContactInfo(void);
		int		_getContactIndexInput(void);
		void	_leftZerosTrim(std::wstring& input);
		void	_displayPipe(void);
		void	_displayTableUnderlines(void);
		void	_displayTableOverlines(void);
		void	_displayTableMiddleLines(void);
		void	_displayTableHead(void);
		void	_displayTableContent(std::wstring s);
};

bool	getInput(std::wstring message, std::wstring& to);

#endif /* PHONEBOOK_HPP_ */
