#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "Contact.class.hpp"
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
		void	getString(const char *info, std::string& to);
		void	getNumber(const char *info, std::string& to);
		void	displayContactInfo(void);
		int		getContactIndexInput(void);
};

#endif
