#include "PhoneBook.hpp"

void	title(int i)
{
	cout << "      ____  __                     __                __  " << std::endl
			  << "     / __ \\/ /_  ____  ____  ___  / /_  ____  ____  / /__" << std::endl
			  << "    / /_/ / __ \\/ __ \\/ __ \\/ _ \\/ __ \\/ __ \\/ __ \\/ //_/" << std::endl
			  << "   / ____/ / / / /_/ / / / /  __/ /_/ / /_/ / /_/ / ,<   " << std::endl
			  << "  /_/   /_/ /_/\\____/_/ /_/\\___/_.___/\\____/\\____/_/|_|  " << std::endl;
	cout << "        ┌───────┬──────────┬──────────┬──────────┐" << std::endl
			  << "        │ index │first name│last name │ nickname │" << std::endl;
	if (!i)
		cout << "        └───────┴──────────┴──────────┴──────────┘" << std::endl;
	else
		cout << "        ├───────┼──────────┼──────────┼──────────┤" << std::endl;
}

std::string Centered(const std::string& text, size_t tableWidth) {
    if (text.length() > tableWidth) {
        if (tableWidth > 3) {
            return text.substr(0, tableWidth - 3) + "...";
        } else {
            return std::string(tableWidth, '.');
        }
    } else {
        size_t totalPadding = tableWidth - text.length();
        size_t paddingLeft = totalPadding / 2;
        size_t paddingRight = totalPadding - paddingLeft;
        return std::string(paddingLeft, ' ') + text + std::string(paddingRight, ' ');
    }
}

int main()
{
	PhoneBook phonebook;
	(void)phonebook;
	std::string input;
	int order = 0;
	int	exit = 0;
	title(0);
	while (!exit)
	{
		while (1) //std::cin
		{
			cout << "Enter the command please (ADD/SEARCH/EXIT): ";
			std::cin >> input;
			std::cin.ignore();
			if (input.compare("ADD") == 0) //check phone number for spaces
			{ //when last name starts with space is invalid smh
				if (order > 7)
					phonebook.replacecontact();
				phonebook.createcontact(order);
				title(1);
				phonebook.showcontacts();
				order++;
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