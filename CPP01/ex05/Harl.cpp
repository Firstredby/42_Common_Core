#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::Debug(void)
{
	cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << endl;
}
void	Harl::Info(void)
{
	cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << endl;
}
void	Harl::Warning(void)
{
	cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << endl;
}
void	Harl::Error(void)
{
	cout << "This is unacceptable! I want to speak to the manager now." << endl;
}

void	Harl::Undefined(void)
{
	cout << "I don't know what you want from me! >:(" << endl;
}

void	Harl::complain(std::string level)
{
	static std::string table[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	func a[] = { &Harl::Debug, &Harl::Info, &Harl::Warning, &Harl::Error, &Harl::Undefined };
	size_t res = 0;
	while (!table[res].empty() && table[res].compare(level))
		res++;
	(this->*a[res])();
}