#include <iostream>

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; av[i]; i++)
			for (int j = 0; av[i][j]; j++)
				if ((unsigned char)av[i][j] > 127)
				{
					std::cout << "Why tf you use unicode man?" << std::endl;
					return 1;
				}
		for (int i = 1; av[i]; i++)
			for (int j = 0; av[i][j]; j++)
				std::cout << (char)toupper(av[i][j]);
	}
	std::cout << std::endl;
	return 0;
}