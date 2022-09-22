#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string		_name;

	public:
		Zombie(void);
		Zombie(std::string);
		~Zombie();

		void	announce( void );
};

Zombie*	zombieHorde(int N, std::string name);

#endif
