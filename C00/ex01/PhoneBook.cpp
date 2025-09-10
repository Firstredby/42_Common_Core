#include "PhoneBook.hpp"

int	stringdigit(std::string str)
{
	for (int i = 0; str[i]; i++)
		if (!isdigit(str[i]))
			return 0;
	return 1;
}

void	PhoneBook::createcontact()
{
	std::string input;
	std::cout << "Enter first name: ";
	while (1)
	{
		std::cin >> input;
		if (input.empty() || input[0] <= 32 || input[0] == 127)
			continue; 
		else
		{
			contact->first_name = input;
			break;
		}
	}
	std::cout << "Enter last name: ";
	while (1)
	{
		std::cin >> input;
		if (input.empty() || input[0] <= 32 || input[0] == 127)
			continue; 
		else
			break;
	}
	std::cout << "Enter nickname: ";
	while (1)
	{
		std::cin >> input;
		if (input.empty() || input[0] <= 32 || input[0] == 127)
			continue; 
		else
			break;
	}
	std::cout << "Enter phone number: ";
	while (1)
	{
		std::cin >> input;
		if (input.empty() || !stringdigit(input))
			continue;
		else
			break;
	}
	std::cout << std::endl;
	std::cout << "Enter darkest secret: ";
	while (1)
	{
		std::cin >> input;
		if (input.empty() || input[0] <= 32 || input[0] == 127)
			continue; 
		else
			break;
	}
	std::cout << std::endl;
}


void	PhoneBook::searchcontact()
{
	
}

int main()
{
	PhoneBook phonebook;
	(void)phonebook;
	std::string input;
	int	exit = 0;
	std::cout << "      ____  __                     __                __  " << std::endl
			  << "     / __ \\/ /_  ____  ____  ___  / /_  ____  ____  / /__" << std::endl
			  << "    / /_/ / __ \\/ __ \\/ __ \\/ _ \\/ __ \\/ __ \\/ __ \\/ //_/" << std::endl
			  << "   / ____/ / / / /_/ / / / /  __/ /_/ / /_/ / /_/ / ,<   " << std::endl
			  << "  /_/   /_/ /_/\\____/_/ /_/\\___/_.___/\\____/\\____/_/|_|  " << std::endl;
	while (!exit)
	{
		std::cout << "┌─────────────────────────────────────────────────────────┐" << std::endl
				  << "│   index   |   first name   |   last name   |  nickname  │" << std::endl
				  << "└─────────────────────────────────────────────────────────┘" << std::endl;
		// std::cout << arr;
		std::cout << "Enter the command please : ";
		while (1)
		{
			std::cin >> input;
			if (input.compare("ADD") == 0)
			{
				phonebook.createcontact();
				break;
			}
			else if (input.compare("SEARCH") == 0)
			{
				phonebook.searchcontact();
				break;
			}
			else if (input.compare("EXIT") == 0)
			{
				exit = 1;
				break;
			}
			else
				continue;
		}
	}
}