#include <iostream>
#define cout std::cout
#define endl std::endl

int main()
{
	std::string Brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &Brain;
	std::string &stringREF = Brain;


	cout << "Value of each variable" << endl;
	cout << "OG : " << Brain << endl
		 << "PTR : " << *stringPTR << endl
		 << "REF : " << stringREF << endl << endl;
	cout << "Address of each variable" << endl;
	cout << "OG : " << &Brain << endl
		 << "PTR : " << stringPTR << endl
		 << "REF : " << &stringREF << endl << endl;
	Brain = "New info";
	cout << "Value of new variables" << endl;
	cout << "OG : " << Brain << endl
		 << "PTR : " << *stringPTR << endl
		 << "REF : " << stringREF << endl;
	// cout << "Address of new variables" << endl;
	// cout << "OG : " << &Brain << endl
	// 	<< "PTR : " << stringPTR << endl
	// 	<< "REF : " << &stringREF << endl << endl;
}