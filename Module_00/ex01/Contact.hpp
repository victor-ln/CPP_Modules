#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {

	public:
		std::wstring		phoneNumber;
		std::wstring		firstName;
		std::wstring		lastName;
		std::wstring		nickName;
		std::wstring		darkestSecret;

		void	clearContactData(void);
};

#endif
