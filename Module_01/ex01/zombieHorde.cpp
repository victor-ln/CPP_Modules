#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {
	if (N <= 0) {
		std::cout << "Invalid N of zombieHorde, it must be a positive non zero number" << std::endl;
		return (NULL);
	}
	Zombie*	zombieHorde;
	try {
		zombieHorde = new Zombie[N];
	} catch (std::bad_alloc& ba) {
		std::cout << "Bad alloc caught: " << ba.what() << std::endl;
		return (NULL);
	}
	Zombie*	ptr = zombieHorde;
	Zombie	zombie(name);
	for (int i = 0; i < N; i++)
		*ptr++ = zombie;
	return (zombieHorde);
}
