#include "Contact.hpp"

#define cout std::cout

class PhoneBook
{
	private:
		Contact contact[8];
	public:
		void	createcontact(int i);
		void	showcontacts();
		void	searchcontact();
		void	replacecontact();
};

std::string Centered(const std::string& text, size_t tableWidth);