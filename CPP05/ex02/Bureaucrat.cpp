#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("Fred"), grade(149)
{
	cout << "Default constructor called!\n";
}
Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{
	cout << "Default constructor called!\n";
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	this->grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.getName()), grade(obj.getGrade())
{
	cout << "Default copy constructor called!\n";
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	cout << "Default copy assignment constructor called!\n";
	if (this != &obj)
		this->grade = obj.grade;
	return *this;
}
Bureaucrat::~Bureaucrat()
{
	cout << "Default destructor called!\n";
}

std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void	Bureaucrat::incrGrade()
{
	if (grade - 1 < 1)
		throw GradeTooHighException();
	--grade;
}

void	Bureaucrat::decrGrade()
{
	if (grade + 1 > 150)
		throw GradeTooLowException();
	++grade;
}

void	Bureaucrat::signForm(Form& f)
{
	try
	{
		f.beSigned(*this);
		cout << name << " signed " << f.getName() << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << name << " couldn't sign " << f.getName()
				  << " because " << e.what();
	}
	
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade "
	   << obj.getGrade() << endl;;
	return os;
}