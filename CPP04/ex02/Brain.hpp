#pragma once

#include <iostream>

using std::cout;
using std::endl;

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain&);
		Brain& operator=(const Brain&);
		~Brain();

		void	setIdea(size_t, std::string);
		std::string	getIdea(size_t) const;
};
