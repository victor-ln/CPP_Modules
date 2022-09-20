#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>

class Contact {

	public:
		std::string		phoneNumber;
		std::string		firstName;
		std::string		lastName;
		std::string		nickName;
		std::string		darkestSecret;

		void	clearContactData(void);
};

#endif
