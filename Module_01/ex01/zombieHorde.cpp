#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {
	Zombie*	zombies;
	Zombie*	ptr;

	if (N <= 0) {
		std::cout << "Invalid N of zombieHorde, it must be a positive non zero number" << std::endl;
		return (NULL);
	}
	try {
		zombies = new Zombie[N];
	} catch (std::bad_alloc& ba) {
		std::cout << "Bad alloc caught: " << ba.what() << std::endl;
		return (NULL);
	}
	ptr = zombies;
	for (int i = 0; i < N; i++)
		*ptr++ = Zombie(name);
	return (zombies);
}
