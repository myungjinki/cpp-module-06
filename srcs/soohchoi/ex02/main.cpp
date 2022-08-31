#include "Identify.hpp"

int main()
{
	srand(clock());
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;

	return (0);
}