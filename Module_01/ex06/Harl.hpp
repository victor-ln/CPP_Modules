#if !defined(HARL_HPP_)
#define HARL_HPP_

#include <iostream>

class Harl
{
	private:
		std::string	funcNames[5];

		void	debug(void) const;
		void	info(void) const;
		void	warning(void) const;
		void	error(void) const;

	public:
		Harl();

		void complain(std::string level);
};

#endif // HARL_HPP_
