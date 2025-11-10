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
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};

#endif