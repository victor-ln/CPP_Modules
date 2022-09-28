#if !defined(SCAVTRAP_HPP_)
#define SCAVTRAP_HPP_

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(void);
		ScavTrap(std::string);
		ScavTrap(const ScavTrap&);
		~ScavTrap(void);

		ScavTrap&	operator=(const ScavTrap&);
		void		guardGate(void);
		void		attack(const std::string& target);
};

#endif // SCAVTRAP_HPP_
