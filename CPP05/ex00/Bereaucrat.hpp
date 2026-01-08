#pragma once

#include <iostream>

using std::cout;
using std::endl;

class Bereaucrat
{
private:
	const std::string name;
	unsigned int grade;
public:
	Bereaucrat();
	Bereaucrat(const std::string&, int);
	Bereaucrat(const Bereaucrat&);
	Bereaucrat& operator=(const Bereaucrat&);
	~Bereaucrat();

	const std::string getName() const;
	const int getGrade() const;
	void	incrGrade();
	void	decrGrade();

	class GradeTooHighException : public std::exception
	{
		public:
			const char* result() const throw()
			{
				return "Grade is too high!\n";
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char* result() const throw()
			{
				return "Grade is too low!\n";
			}
	};
};
