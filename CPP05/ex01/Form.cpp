#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Form"), isSigned(0), gradeToSign(1), gradeToExecute(1)
{
	cout << "Default constructor called!\n";
}

Form::Form(const Form& obj) : name(obj.name),
		isSigned(obj.isSigned), gradeToSign(obj.gradeToSign), gradeToExecute(obj.gradeToExecute)
{
	cout << "Default copy constructor called!\n";
}

int	Form::validation(int grade)
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
	return grade;
}

Form::Form(const std::string& name, int sign, int exec) : name(name), isSigned(0),
		gradeToSign(validation(sign)), gradeToExecute(validation(exec))
{
	cout << "Default constructor called!\n";
}

Form& Form::operator=(const Form& obj)
{
	cout << "Default copy assignment constructor called!\n";
	if (this != &obj)
		this->isSigned = obj.isSigned;
	return *this;
}

Form::~Form()
{
	cout << "Default destructor called!\n";
}

std::string	Form::getName() const
{
	return name;
}

bool		Form::checkSign() const
{
	return isSigned;
}

int			Form::getGradeToSign() const
{
	return gradeToSign;
}

int			Form::getGradeToExecute() const
{
	return gradeToExecute;
}

void		Form::beSigned(const Bureaucrat& obj)
{
	if (isSigned)
		throw FormAlreadySignedException();
	if (obj.getGrade() <= gradeToSign)
		isSigned = 1;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	os << "Form " << obj.getName() << " is "
	   << (obj.checkSign() ? "signed.\n" : "not signed.\n");
	os << "It's grade to sign is " << obj.getGradeToSign()
	   << " and grade to execute is " << obj.getGradeToExecute()
	   << endl;
	return os;
}