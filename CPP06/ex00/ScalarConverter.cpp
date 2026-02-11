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

bool	nonAlphaStr(const std::string& value)
{
	size_t i = 0;
	if (value.size() == 1)
		return false;
	while (value[i] && !isalpha(value[i]))
		i++;
	if (i <= value.size() - 1)
	{
		if (value[i] == 'e' || value[i] == 'f')
			return false;
		return true;
	}
	return false;
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

bool isFloat(const std::string& value)
{
    if (value.empty())
        return false;

    size_t i = 0;
    bool hasDigit = false;
    bool hasDot = false;
    bool hasExp = false;

    if (value[i] == '+' || value[i] == '-')
        i++;

    for (; i < value.length(); i++)
    {
        if (std::isdigit(value[i]))
            hasDigit = true;
        else if (value[i] == '.' && !hasDot && !hasExp)
            hasDot = true;
        else if ((value[i] == 'e') && !hasExp && hasDigit)
        {
            hasExp = true;
            hasDigit = false;

            if (i + 1 < value.length() &&
                (value[i + 1] == '+' || value[i + 1] == '-'))
                i++;
        }
        else if (value[i] == 'f' && i == value.length() - 1)
            return hasDigit;
        else
            return false;
    }

    return false;
}

void	toInt(const std::string& value)
{
	std::stringstream ss(value);
	long	num;
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
	if (num < -2147483648 || num > 2147483647)
		cout << "impossible\n";
	else
		cout << static_cast<int>(num) << endl;
	cout << "float: ";
	cout << std::fixed << std::setprecision(3)
			<< static_cast<float>(num) << "f" << endl;
	cout << "double: ";
	cout << std::fixed << std::setprecision(3)
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
	cout << std::fixed << std::setprecision(3)
			<< static_cast<float>(cast) << "f" << endl;
	cout << "double: ";
	cout << std::fixed << std::setprecision(3)
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
	if (cast < -2147483648 || cast > 2147483647)
		cout << "impossible\n";
	else
		cout << static_cast<int>(cast) << endl;
	cout << "float: ";
	cout << std::fixed << std::setprecision(3)
			<< static_cast<float>(cast) << "f" << endl;
	cout << "double: ";
	cout << std::fixed << std::setprecision(3)
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
	if (cast < -2147483648 || cast > 2147483647)
		cout << "impossible\n";
	else
		cout << static_cast<int>(cast) << endl;
	cout << "float: ";
	cout << std::fixed << std::setprecision(3)
			<< static_cast<float>(cast) << "f" << endl;
	cout << "double: ";
	cout << std::fixed << std::setprecision(3)
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
	if ((value.find_first_of(" \t\b\n\v") != std::string::npos && value.size() > 1)
		|| nonAlphaStr(value)) return noType(value);
	if (value.size() == 1 && !std::isdigit(value[0]))
		toChar(value);
	else if (isInt(value))
		toInt(value);
	else if (isFloat(value))
		toFloat(value.substr(0, value.size() - 1));
	else if ((value.find_first_of('.') != std::string::npos
		&& value.find_first_of('.') == value.find_last_of('.')
		&& value[value.find('.') + 1] != '\0')
		|| (value.find_first_of('.') == std::string::npos
			&& !nonAlphaStr(value)))
		toDouble(value);
	else
		noType(value);
}