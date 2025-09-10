#include <iostream>
#include <cstring>

class Contact
{
	public:
		int	index;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

class PhoneBook : Contact
{
	private:
		Contact contact[8];
	public:
		void	createcontact();
		void	searchcontact();
};
