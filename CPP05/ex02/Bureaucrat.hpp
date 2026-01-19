#pragma once

#include <iostream>

using std::cout;
using std::endl;

class AForm;

class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string&, int);
	Bureaucrat(const Bureaucrat&);
	Bureaucrat& operator=(const Bureaucrat&);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;
	void	incrGrade();
	void	decrGrade();

	void		signForm(AForm&);
	void		executeForm(AForm const & form);

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return "Grade is too high!\n";
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return "Grade is too low!\n";
			}
	};
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);
