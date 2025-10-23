#include <iostream>

class Contact
{
	private:
		int	index;
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;
	public:
		void	setId(int i);
		void	setFN(std::string firstname);
		void	setLN(std::string lastname);
		void	setNN(std::string nickname);
		void	setPN(std::string phonenumber);
		void	setDS(std::string secret);

		int			getId();
		std::string	getFN();
		std::string	getLN();
		std::string	getNN();
		std::string	getPN();
		std::string	getDS();
};