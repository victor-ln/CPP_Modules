#if !defined(DIAMONDTRAP_HPP_)
#define DIAMONDTRAP_HPP_

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	public:
		DiamondTrap(void);
		DiamondTrap(std::string);
		DiamondTrap(DiamondTrap&);
		~DiamondTrap(void);

		DiamondTrap&	operator=(const DiamondTrap&);
		void			whoAmI(void);

	private:
		std::string		_name;
};

#endif // DIAMONDTRAP_HPP_
