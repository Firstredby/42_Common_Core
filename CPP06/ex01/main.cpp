#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	Data		data;
	Data*		dataPtr;
	uintptr_t	raw;

	data.str = "Hello World!";
	data.name = "John Doe";
	data.age = 30;
	data.number = 42;

	cout << "Original Data address: " << &data << endl;
	cout << "Original Data content:" << endl;
	cout << "  str: " << data.str << endl;
	cout << "  name: " << data.name << endl;
	cout << "  age: " << data.age << endl;
	cout << "  number: " << data.number << endl;

	raw = Serializer::serialize(&data);
	cout << "\nSerialized Data (uintptr_t): " << raw << endl;

	dataPtr = static_cast<Data*>(Serializer::deserialize(raw));
	cout << "\nDeserialized Data address: " << dataPtr << endl;
	cout << "Deserialized Data content:" << endl;
	cout << "  str: " << dataPtr->str << endl;
	cout << "  name: " << dataPtr->name << endl;
	cout << "  age: " << dataPtr->age << endl;
	cout << "  number: " << dataPtr->number << endl;

	return 0;
}