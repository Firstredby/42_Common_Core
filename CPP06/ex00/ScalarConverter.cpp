#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(/* args */)
{
}

ScalarConverter::ScalarConverter(ScalarConverter&)
{
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter&)
{
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

bool	isInt(const std::string& value)
{
    size_t i = 0;

    if (value.empty())
        return false;

    if (value[i] == '+' || value[i] == '-')
        i++;

    if (i == value.length())
        return false;

    for (; i < value.length(); i++)
        if (!std::isdigit(value[i]))
            return false;

    return true;
}

bool	isFloat(const std::string& value)
{
    size_t i = 0;

    if (value.empty())
        return false;

    if (value[i] == '+' || value[i] == '-')
        i++;

    if (i == value.length())
	{
        return false;
	}

	bool dot = false;
    for (; i < value.length(); i++)
        if (!std::isdigit(value[i]))
		{
			if (value[i] == 'f' && i == value.length())
				continue;
			else if (value[i] == '.' && !dot)
			{
				dot = true;
				continue;
			}
			else
				return false;
		}

    return true;
}

void	toInt(const std::string& value)
{
	std::stringstream ss(value);
	int	num;
	ss >> num;
	double cast = static_cast<double>(num);
	cout << "char: ";
	if (cast < 0 || cast > 127)
		cout << "impossible\n";
	else if (!std::isprint(static_cast<int>(cast)))
		cout << "Non displayable\n";
	else
		cout << "'" << static_cast<char>(cast) << "'\n";
	cout << "int: ";
	cout << static_cast<int>(num) << endl;
	cout << "float: ";
	cout << std::fixed << std::setprecision(1)
			<< static_cast<float>(num) << "f" << endl;
	cout << "double: ";
	cout << std::fixed << std::setprecision(1)
			<< cast << endl;
}

void	toChar(const std::string& value)
{
	double cast = static_cast<double>(value[0]);
	cout << "char: ";
	if (cast < 0 || cast > 127)
		cout << "impossible\n";
	else if (!std::isprint(static_cast<int>(cast)))
		cout << "Non displayable\n";
	else
		cout << "'" << static_cast<char>(cast) << "'\n";
	cout << "int: ";
	cout << static_cast<int>(cast) << endl;
	cout << "float: ";
	cout << std::fixed << std::setprecision(1)
			<< static_cast<float>(cast) << "f" << endl;
	cout << "double: ";
	cout << std::fixed << std::setprecision(1)
			<< cast << endl;
}

void	toFloat(const std::string& value)
{
	char *end;
	double cast = std::strtod(value.c_str(), &end);
	cout << "char: ";
	if (cast < 0 || cast > 127)
		cout << "impossible\n";
	else if (!std::isprint(static_cast<int>(cast)))
		cout << "Non displayable\n";
	else
		cout << "'" << static_cast<char>(cast) << "'\n";
	cout << "int: ";
	cout << static_cast<int>(cast) << endl;
	cout << "float: ";
	cout << std::fixed << std::setprecision(1)
			<< static_cast<float>(cast) << "f" << endl;
	cout << "double: ";
	cout << std::fixed << std::setprecision(1)
			<< cast << endl;
}

void	toDouble(const std::string& value)
{
	char *end;
	double cast = std::strtod(value.c_str(), &end);
	cout << "char: ";
	if (cast < 0 || cast > 127)
		cout << "impossible\n";
	else if (!std::isprint(static_cast<int>(cast)))
		cout << "Non displayable\n";
	else
		cout << "'" << static_cast<char>(cast) << "'\n";
	cout << "int: ";
	cout << static_cast<int>(cast) << endl;
	cout << "float: ";
	cout << std::fixed << std::setprecision(1)
			<< static_cast<float>(cast) << "f" << endl;
	cout << "double: ";
	cout << std::fixed << std::setprecision(1)
			<< cast << endl;
}

void	noType(const std::string& value)
{
	if (value == "+inf" || value == "+inff")
	{
		cout << "char: impossible\n"
			 << "int: impossible\n"
			 << "float: +inff\n"
			 << "double: +inf\n";
	}
	else if (value == "-inf" || value == "-inff")
	{
		cout << "char: impossible\n"
			 << "int: impossible\n"
			 << "float: -inff\n"
			 << "double: -inf\n";
	}
	else if (value == "nan" || value == "nanf")
	{
		cout << "char: impossible\n"
			 << "int: impossible\n"
			 << "float: nanf\n"
			 << "double: nan\n";
	}
	else
		cout << "Error: cannot convert to any variable\n";
}

void ScalarConverter::convert(const std::string& value)
{
	std::string strToConvert = value.substr(value.find_first_not_of(" \t\n\r\f\v"), 
									value.find_last_not_of(" \t\n\r\f\v") + 1);
	
	if (strToConvert.size() == 1 && !std::isdigit(strToConvert[0]))
		toChar(strToConvert);
	else if (isInt(value))
		toInt(strToConvert);
	else if (value.find_first_of('.') != std::string::npos
			&& value.find_first_of('.') == value.find_last_of('.'))
		toDouble(strToConvert);
	else if (isFloat(strToConvert))
	{
		strToConvert =  strToConvert.substr(0, strToConvert.size() - 1);
		toFloat(strToConvert);
	}
	else
		noType(strToConvert);
}