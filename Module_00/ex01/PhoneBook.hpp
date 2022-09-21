#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <cstdlib>

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
		bool	_getInput(std::wstring message, std::wstring& to);
		void	_getString(const wchar_t *info, std::wstring& to);
		void	_getNumber(const wchar_t *info, std::wstring& to);
		void	_displayContactInfo(void);
		int		_getContactIndexInput(void);
		void	_displayPipe(void);
		void	_displayTableBorder(void);
		void	_displayTableHead(void);
		void	_displayTableContent(std::wstring s);
};

bool	getInput(std::wstring message, std::wstring& to);

#endif
