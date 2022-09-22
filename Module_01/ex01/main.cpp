#include "Zombie.hpp"

int	main(void) {
	Zombie*			zombies;
	std::string		zombieName;
	int				numberOfZombies;

	std::cout << "Enter the zombie name: " << std::endl;
	std::cin >> zombieName;
	numberOfZombies = 0;
	while (numberOfZombies <= 0) {
		std::cout << "Enter the number of Zombies: " << std::endl;
		std::cin >> numberOfZombies;
		if (numberOfZombies <= 0)
			std::cout << "Invalid input" << std::endl;
	}
	zombies = zombieHorde(numberOfZombies, zombieName);
	if (zombies == nullptr)
		return (errno);
	for (int i = 0; i < numberOfZombies; i++)
		zombies[i].announce();
	delete [] zombies;
	return (0);
}
