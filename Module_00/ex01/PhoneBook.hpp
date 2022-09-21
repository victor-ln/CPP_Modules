#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

class PhoneBook {

	public:

		PhoneBook(void);

		void	add(void);
		void	search(void);

	private:
		Contact		contacts[8];
		int			last;
		int			contactsAdded;

		Contact	*getLastContact(void);
		Contact	*getContactByIndex(int index);
		void	getString(const wchar_t *info, std::wstring& to);
		void	getNumber(const wchar_t *info, std::wstring& to);
		void	displayContactInfo(void);
		int		getContactIndexInput(void);
};

#endif
