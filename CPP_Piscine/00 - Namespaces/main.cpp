#include <iostream>

int		g_number = 1;

int		f(void) {
	return (2);
}

/*
	Microsoft:
	A namespace is a declarative region that provides a scope to the 
	identifiers (the names of types, functions, variables, etc) inside it. 
	Namespaces are used to organize code into logical groups and to prevent 
	name collisions that can occur especially 
	when your code base includes multiple libraries.
	Link: https://learn.microsoft.com/en-us/cpp/cpp/namespaces-cpp?view=msvc-170
*/

namespace Foo {
	int		g_number = 3;
	int		f(void) {
		return (4);
	}
}

namespace Bar {
	int		g_number = 5;
	int		f(void) {
		return (6);
	}
}

namespace B = Bar;

int	main(void) {
	std::cout << "Global = " << g_number << " Function = " << f() << std::endl;
	std::cout << "Global = " << Foo::g_number << " Function = " << Foo::f() << std::endl;
	std::cout << "Global = " << Bar::g_number << " Function = " << Bar::f() << std::endl;
	std::cout << "Global = " << B::g_number << " Function = " << B::f() << std::endl;
	std::cout << "Global = " << ::g_number << " Function = " << ::f() << std::endl;
	return (0);
}
