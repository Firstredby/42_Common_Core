#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


int	main()
{
	Base*	base;

	srand(std::time(0));
	for (int i = 0; i < 10; i++)
	{
		base = base->generate();
		cout << "Identifying pointer: ";
		base->identify(base);
		cout << "Identifying reference: ";
		base->identify(*base);
		cout << "------------------------" << endl;
		delete base;
	}
	return (0);
}