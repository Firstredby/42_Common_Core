#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: exchangeRates(other.exchangeRates)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		exchangeRates = other.exchangeRates;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

bool isValidDate(const std::string& date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (size_t i = 0; i < date.size(); ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return false;
	}
	if (date.substr(0, 4) < "2009" || date.substr(0, 4) > "2024"
		|| date.substr(5, 2) < "01" || date.substr(5, 2) > "12"
		|| date.substr(8, 2) < "01" || date.substr(8, 2) > "31")
		return false;
	return true;
}

bool headerchecker(const std::string& line)
{
	std::string expectedHeader = "date | value";
	return line == expectedHeader;
}

void BitcoinExchange::loadExchangeRates()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
	{
		std::cerr << ERR_FOPEN << "data.csv" << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line); // Skip header
	while (std::getline(file, line))
	{
		line.replace(line.find(','), 1, " ");
		std::stringstream ss(line);
		std::string date;
		float rate;
		ss >> date >> rate;
		exchangeRates[date] = rate;
	}
	file.close();
}

float BitcoinExchange::getExchangeRate(const std::string& date) const
{
	std::map<std::string, float>::const_iterator it = exchangeRates.lower_bound(date);
	if (it != exchangeRates.end() && it->first == date)
		return it->second;
	if (it != exchangeRates.begin())
	{
		--it;
		return it->second;
	}
	return 0.0f;
}

bool validateLineFormat(const std::string& line)
{
	char* end;
	double value = std::strtod(line.substr(line.find(" | ") + 3).c_str(), &end);
	if (line.empty() || !isdigit(line[0])
		|| !isdigit(line[line.length() - 1])
		|| line.find(" | ") == std::string::npos
		|| !isdigit(line[line.find(" | ") + 4])
		|| !isdigit(line[line.find(" | ") - 1])
		|| end == line.substr(line.find(" | ") + 3).c_str())
	{
		std::cerr << ERR_LFORMAT << line << std::endl;
		return false;
	}
	if (!isValidDate(line.substr(0, 10)))
	{
		std::cerr << ERR_INVDATE << line.substr(0, 10) << std::endl;
		return false;
	}
	if (value < 0)
	{
		std::cerr << ERR_NVAL << value << std::endl;
		return false;
	}
	else if (value > 1000.0)
	{
		std::cerr << ERR_UNREALVAL << value << std::endl;
		return false;
	}
	return true;
}

void	BitcoinExchange::processInputFile(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << ERR_FOPEN << filename << std::endl;
		return;
	}

	std::string line;
	if (!std::getline(file, line) || !headerchecker(line))
	{
		std::cerr << ERR_LFORMAT << "Missing or invalid header in input file." << std::endl;
		return;
	}
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		float value;
		char delimiter;
		if (!validateLineFormat(line))
			continue;
		ss >> date >> delimiter >> value;
		std::cout << date << " => " << value << " = " << value * getExchangeRate(date) << std::endl;
	}
	file.close();
}

void BitcoinExchange::execute(const std::string& filename)
{
	loadExchangeRates();
	processInputFile(filename);
}