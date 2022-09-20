#include <iostream>

int	main(void) {
	char	buffer[512];

	std::cout << "Hello World !" << std::endl;
	std::cout << "Type something:";
	std::cin >> buffer;
	std::cout << "You typed: [" << buffer << "]" << std::endl;
	return (0);
}
