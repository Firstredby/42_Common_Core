#pragma once

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sstream>
#include <map>
#include <stdexcept>

#define ERR_INVDATE "Error: Invalid date: "
#define ERR_INVVAL "Error: Invalid value: "
#define ERR_FOPEN "Error: Could not open file: "
#define ERR_LFORMAT "Error: Invalid line format: "
#define ERR_NVAL "Error: Negative value: "
#define ERR_UNREALVAL "Error: Unrealistic value: "

class BitcoinExchange
{
private:
	std::map<std::string, float> exchangeRates;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void execute(const std::string& filename);
	void loadExchangeRates();
	void processInputFile(const std::string& filename);
	float getExchangeRate(const std::string& date) const;
};