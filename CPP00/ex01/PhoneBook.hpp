#include "Contact.hpp"
#include <iomanip>
#include <cstdlib>
#include <sstream>

#define cout std::cout
#define endl std::endl
#define align(len) std::setfill(' ') << std::setw(len)
#define cut(str) ((str.size() <= 10) ? str : str.substr(0, 9) + ".")

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