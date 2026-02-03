#include "Array.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	Array<int> intArray(5);
	Array<std::string> strArray(5);

	for (size_t i = 0; i < intArray.size(); i++)
		intArray[i] = i * 10;

	strArray[0] = "CPP";
	strArray[1] = "Module";
	strArray[2] = "07";
	strArray[3] = "Exercise";
	strArray[4] = "02";

	cout << "Integer Array:" << endl;
	for (size_t i = 0; i < intArray.size(); i++)
		cout << intArray[i] << " ";
	cout << endl;

	cout << "String Array:" << endl;
	for (size_t i = 0; i < strArray.size(); i++)
		cout << strArray[i] << " ";
	cout << endl;

	try
	{
		cout << "Accessing out of bounds index:" << endl;
		cout << intArray[10] << endl;
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << e.what() << endl;
	}

	return 0;
}