#include "PhoneBook.hpp"

int	stringdigit(std::string str)
{
	for (int i = 0; str[i]; i++)
		if (!isdigit(str[i]))
			return 0;
	return 1;
}

bool strprintable(std::string str)
{
	for (int i = 0; str[i]; i++)
		if ((unsigned char)str[i] > 126 || (unsigned char)str[i] < 33)
			return 1;
	return 0;
}

std::string	trim(std::string raw)
{
	int left = 0;
	int right = 0;
	if (raw.empty())
		return raw;
	for (int i = 0; (raw[i] <= 32 || raw[i] == 127) && raw[i] != 0; i++)
		left++;
	for (int k = raw.size() - 1; (raw[k] <= 32 || raw[k] == 127) && raw[k] != 0; k--)
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
		if (!std::cin)
			return "";
		output = trim(output);
		if (output.empty())
			cout << "Your input should be not empty" << endl;
		else if (strprintable(output))
			cout << "Invalid input" << endl;
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
	if (!std::cin)
			return;
	contact[i].setLN(filldata("Enter last name: "));
	if (!std::cin)
			return;
	contact[i].setNN(filldata("Enter nickname: "));
	if (!std::cin)
			return;
	while (1)
	{
		cout << "Enter phone number: ";
		getline(std::cin, input);
		if (!std::cin)
			return;
		input = trim(input);
		if (input.empty())
			cout << "Your input should be not empty" << endl;
		else if(!stringdigit(input))
			cout << "Phone number should contain only digits" << endl;
		else
		{
			contact[i].setPN(input);
			break;
		}
	}
	contact[i].setDS(filldata("Enter darkest secret: "));
	if (!std::cin)
			return;
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
	for (int i = 0; i < 8; i++)
	{
		if (contact[i].getFN().empty())
			break ;
		else
		{
			cout << "\t│" << align(7) <<  i + 1 << "│";
			cout << align(10) << cut(contact[i].getFN());
			cout << "│" << align(10) << cut(contact[i].getLN());
			cout << "│" << align(10) << cut(contact[i].getNN());
			cout << "│" << endl;
			if (i + 1 != 8 && contact[i + 1].getFN() != "")
				cout << "\t├───────┼──────────┼──────────┼──────────┤" << endl;
			else
				cout << "\t└───────┴──────────┴──────────┴──────────┘" << endl;
			k++;
		}
	}
}

void	PhoneBook::searchcontact()
{
	std::string index;
	int val;
	cout << "Please write ID of contact you want to choose" << endl;
	getline(std::cin, index);
	std::stringstream ss(index);
	ss >> val;
	if (!std::cin)
		return ;
	if (ss.fail())
	{
		cout << "Your request should contain only digits" << endl;
		return ;
	}
	else if (val <= 0 || val > 8)
	{
		cout << "Invalid index, please choose contact from 1 to 8 inclusive" << endl;
		return ;
	}
	if (contact[val - 1].getFN() == "")
	{
		cout << "Contact is empty!" << endl;
		return ;
	}
	cout << "First name :\t\t" << contact[val - 1].getFN() << endl;
	cout << "Last name :\t\t" << contact[val - 1].getLN() << endl;
	cout << "Nickname :\t\t" << contact[val - 1].getNN() << endl;
	cout << "Phone number :\t\t" << contact[val - 1].getPN() << endl;
	cout << "Darkest secret :\t" << contact[val - 1].getDS() << endl;
}
