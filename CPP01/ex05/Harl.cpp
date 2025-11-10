#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << endl;
}
void	Harl::info(void)
{
	cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << endl;
}
void	Harl::warning(void)
{
	cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << endl;
}
void	Harl::error(void)
{
	cout << "This is unacceptable! I want to speak to the manager now." << endl;
}

elevel	strToEnum(std::string level)
{
	static std::map<std::string, elevel> table;
	table["INFO"] = INFO; 
	table["DEBUG"] = DEBUG;
	table["WARNING"] = WARNING;
	table["ERROR"] = ERROR;
	std::map<std::string, elevel>::const_iterator it = table.find(level);
	if(it != table.end())
		return it->second;
	return UNKNOWN;
}

void	Harl::complain(std::string level)
{
	switch (strToEnum(level))
	{
		case DEBUG:
			debug();
			break;
		case INFO:
			info();
			break;
		case WARNING:
			warning();
			break;
		case ERROR:
			error();
			break;
		default:
			cout << "I don't understand what you want from me >:(" << endl;
			break;
	}
}