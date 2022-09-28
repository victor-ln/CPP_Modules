#if !defined(CLAPTRAP_HPP_)
#define CLAPTRAP_HPP_

#include <iostream>

class ClapTrap {
	public:
		ClapTrap(void);
		ClapTrap(std::string);
		ClapTrap(const ClapTrap&);
		~ClapTrap(void);

		ClapTrap&	operator=(const ClapTrap&);

		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;

	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

};

#endif // CLAPTRAP_HPP_
