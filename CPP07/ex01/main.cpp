#include "iter.hpp"
#include <iostream>
#include <cctype>

using std::cout;
using std::endl;

void addTen(int &n)
{
	n += 10;
}
void toUpper(char &c)
{
	c = toupper(c);
}
void addComma(std::string &s)
{
	s += ",";
}

int main()
{
	int         intArray[] = {1, 2, 3, 4, 5};
	char        charArray[] = {'a', 'b', 'c', 'd', 'e'};
	std::string strArray[] = {"CPP", "Module", "07", "Exercise", "01"};

	iter(intArray, 5, addTen);
	iter(charArray, 5, toUpper);
	iter(strArray, 5, addComma);

	for (int i = 0; i < 5; i++)
		cout << intArray[i] << " ";
	cout << endl;

	for (int i = 0; i < 5; i++)
		cout << charArray[i] << " ";
	cout << endl;
	for (int i = 0; i < 5; i++)
		cout << strArray[i] << " ";
	cout << endl;

	return 0;
}