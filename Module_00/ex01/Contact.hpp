#ifndef CONTACT_HPP_
# define CONTACT_HPP_

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

#endif /* CONTACT_HPP_ */
