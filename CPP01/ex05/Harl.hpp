#ifndef HARL_H
#define HARL_H

#include <iostream>
#include <map>

#define cout std::cout
#define endl std::endl

enum	elevel
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	UNKNOWN
};

class Harl
{
	private:
		void	Debug(void);
		void	Info(void);
		void	Warning(void);
		void	Error(void);
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
		void	Undefined(void);
};

typedef void	(Harl::*func)(void);

#endif