#include "PhoneBook.hpp"

int	stringdigit(std::string str)
{
	for (int i = 0; str[i]; i++)
		if (!isdigit(str[i]))
			return 0;
	return 1;
}

std::string	trim(std::string raw)
{
	int left = 0;
	int right = 0;
	if (raw.empty())
		return raw;
	for (int i = 0; raw[i] <= 32 || raw[i] == 127; i++)
		left++;
	for (int k = raw.size() - 1; raw[k] <= 32 || raw[k] == 127; k--)
		right++;
	if (!left && !right)
		return raw;
	return raw.substr(left, right - left + 1);
}

std::string	filldata(std::string str)
{
	std::string output;
	while (1)
	{
		cout << str;
		getline(std::cin, output);
		output = trim(output);
		if (output.empty())
		{
			cout << "Your input should be not empty" << std::endl;
			continue ; 
		}
		else
			break ;
	}
	return output;
}

void	PhoneBook::createcontact(int i)
{
	std::string input;
	if (i > 7)
		i = 7;
	contact[i].setId(i + 1);
	contact[i].setFN(filldata("Enter first name: "));
	contact[i].setLN(filldata("Enter last name: "));
	contact[i].setNN(filldata("Enter nickname: "));
	while (1)
	{
		cout << "Enter phone number: ";
		getline(std::cin, input);
		input = trim(input);
		if (input.empty())
		{
			cout << "Your input should be not empty" << std::endl;
			continue;
		}
		else if(!stringdigit(input))
		{
			cout << "Phone number should contain only digits" << std::endl;
			continue;
		}
		else
		{
			contact[i].setPN(input);
			break;
		}
	}
	contact[i].setDS(filldata("Enter darkest secret: "));
}

void	PhoneBook::replacecontact()
{
	for (int i = 0; i < 7; i++)
	{
		contact[i].setFN(contact[i + 1].getFN());
		contact[i].setLN(contact[i + 1].getLN());
		contact[i].setNN(contact[i + 1].getNN());
		contact[i].setPN(contact[i + 1].getPN());
		contact[i].setDS(contact[i + 1].getDS());
	}
}

void	PhoneBook::showcontacts()
{
	int k = 0;
	for (int i = 7; i >= 0; i--)
	{
		if (contact[i].getFN().empty())
			continue ;
		else
		{
			cout << "        │   "<< i - (i - k) + 1 << "   │"
				<< Centered(contact[i].getFN(), 10) << "│"
				<< Centered(contact[i].getLN(), 10) << "│"
				<< Centered(contact[i].getNN(), 10) << "│" << std::endl;
			if (i && !contact[i - 1].getFN().empty())
				cout << "        ├───────┼──────────┼──────────┼──────────┤" << std::endl;
			else
				cout << "        └───────┴──────────┴──────────┴──────────┘" << std::endl;
			k++;
		}
	}
}

void	PhoneBook::searchcontact()
{
	int index;
	cout << "Please write ID of contact you want to choose" << std::endl;
	std::cin >> index;
	if (std::isdigit(index))
	{
		cout << "Your request should contain only digits" << std::endl;
		return ;
	}
	else if (index <= 0 || index >= 8)
	{
		cout << "Invalid index, please choose contact from 1 to 8 inclusive" << std::endl;
		return ;
	}
	cout << "First name :\t\t" << contact[index - 1].getFN() << std::endl;
	cout << "Last name :\t\t" << contact[index - 1].getLN() << std::endl;
	cout << "Nickname :\t\t" << contact[index - 1].getNN() << std::endl;
	cout << "Phone number :\t\t" << contact[index - 1].getPN() << std::endl;
	cout << "Darkest secret :\t" << contact[index - 1].getDS() << std::endl;
}
