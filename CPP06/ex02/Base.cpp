#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::~Base()
{
}

Base * Base::generate()
{
	int	rand = std::rand() % 3 + 1;

	if (rand == 1)
		return new A();
	else if (rand == 2)
		return new B();
	else
		return new C();
}

void	Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		cout << "It's A!" << endl;
	else if (dynamic_cast<B*>(p))
		cout << "It's B!" << endl;
	else if (dynamic_cast<C*>(p))
		cout << "It's C!" << endl;
	else
		cout << "Unknown Type :(" << endl;
}

void	Base::identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		cout << "It's A!" << endl;
		return ;
	}
	catch (std::exception& e)
	{
	}

	try
	{
		(void)dynamic_cast<B&>(p);
		cout << "It's B!" << endl;
		return ;
	}
	catch (std::exception& e)
	{
	}

	try
	{
		(void)dynamic_cast<C&>(p);
		cout << "It's C!" << endl;
		return ;
	}
	catch (std::exception& e)
	{
	}

	cout << "Unknown Type :(" << endl;
}