#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	_name;
		Weapon*		_weapon;

	public:
		HumanA(std::string, Weapon&);
		HumanA(std::string, Weapon*);
		~HumanA();

		void	attack(void) const;
		void	setWeapon(Weapon&);
		void	setWeapon(Weapon*);
};

#endif
