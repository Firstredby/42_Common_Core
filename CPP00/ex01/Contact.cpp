#include "Contact.hpp"

int	Contact::getId()
{
	return index;
}

std::string Contact::getFN()
{
	return first_name;
}

std::string Contact::getLN()
{
	return last_name;
}

std::string Contact::getPN()
{
	return phone_number;
}

std::string Contact::getNN()
{
	return nick_name;
}

std::string Contact::getDS()
{
	return darkest_secret;
}

void	Contact::setId(int i)
{
	index = i;
}

void	Contact::setFN(std::string firstname)
{
	first_name = firstname;
}

void	Contact::setLN(std::string lastname)
{
	last_name = lastname;
}

void	Contact::setNN(std::string nickname)
{
	nick_name = nickname;
}
void	Contact::setPN(std::string phonenumber)
{
	phone_number = phonenumber;
}
void	Contact::setDS(std::string secret)
{
	darkest_secret = secret;
}