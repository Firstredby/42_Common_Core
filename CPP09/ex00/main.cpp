#include "BitcoinExchange.hpp"

int main(int ac, char* av[])
{
	if (ac == 1)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	BitcoinExchange btc;
	btc.execute(av[1]);
	return 0;
}