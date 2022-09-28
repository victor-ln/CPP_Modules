#if !defined(FRAGTRAP_HPP_)
#define FRAGTRAP_HPP_

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(std::string);
		FragTrap(FragTrap&);
		~FragTrap(void);

		FragTrap&	operator=(const FragTrap&);
		void		highFivesGuys(void);
};

#endif // FRAGTRAP_HPP_
