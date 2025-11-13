#include "PhoneBook.hpp"

void	title()
{
	cout << "      ____  __                     __                __  " << endl
		 << "     / __ \\/ /_  ____  ____  ___  / /_  ____  ____  / /__" << endl
		 << "    / /_/ / __ \\/ __ \\/ __ \\/ _ \\/ __ \\/ __ \\/ __ \\/ //_/" << endl
		 << "   / ____/ / / / /_/ / / / /  __/ /_/ / /_/ / /_/ / ,<   " << endl
		 << "  /_/   /_/ /_/\\____/_/ /_/\\___/_.___/\\____/\\____/_/|_|  " << endl;
}

void grid(int i)
{
	cout << "        ┌──────────┬──────────┬──────────┬──────────┐" << endl
		 << "        │   index  │first name│last name │ nickname │" << endl;
	if (!i)
		cout << "        └──────────┴──────────┴──────────┴──────────┘" << endl;
	else
		cout << "        ├──────────┼──────────┼──────────┼──────────┤" << endl;
}

int main()
{
	PhoneBook phonebook;
	(void)phonebook;
	std::string input;
	int order = 0;
	title();
	while (1)
	{
		
		if (!std::cin)
		{
			cout << "Unexpected EOL. Process terminated" << endl;
			std::exit(1);
		}
		cout << "Enter the command please (ADD/SEARCH/EXIT): ";
		getline(std::cin, input);
		if (input.compare("ADD") == 0)
		{
			if (order > 7)
				phonebook.replacecontact();
			phonebook.createcontact(order);
			order++;
		}
		else if (input.compare("SEARCH") == 0)
		{
			grid(order);
			phonebook.showcontacts();
			phonebook.searchcontact();
		}
		else if (input.compare("EXIT") == 0)
			std::exit(0);
		else
			continue;
	}
}