#include "Bereaucrat.hpp"

Bereaucrat::Bereaucrat() : name("Fred"), grade(149)
{
	cout << "Default constructor called!\n";
}
Bereaucrat::Bereaucrat(const std::string& name, int grade) : name(name)
{
	cout << "Default constructor called!\n";
	if (grade > 150)
		throw GradeTooHighException();
	if (grade < 1)
		throw GradeTooLowException();
	this->grade = grade;
}
Bereaucrat::Bereaucrat(const Bereaucrat& obj) : name(obj.getName()), grade(obj.getGrade())
{
	cout << "Default copy constructor called!\n";
}
Bereaucrat& Bereaucrat::operator=(const Bereaucrat& obj)
{
	cout << "Default copy assignment constructor called!\n";
	if (this != &obj)
		*this = obj;
	return *this;
}
Bereaucrat::~Bereaucrat()
{
	cout << "Default destructor called!\n";
}

const std::string Bereaucrat::getName() const
{
	return name;
}
const int Bereaucrat::getGrade() const
{
	return grade;
}
void	Bereaucrat::incrGrade()
{
	if (grade - 1 <= 1)
		throw GradeTooHighException();
	cout << "Grade was increased by 1!\n"
		 << "Current grade is " << --grade
		 << endl;
}
void	Bereaucrat::decrGrade()
{
	if (grade + 1 >= 150)
		throw GradeTooLowException();
	cout << "Grade was decreased by 1!\n"
		 << "Current grade is " << ++grade
		 << endl;
}