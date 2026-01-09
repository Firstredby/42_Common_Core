#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("AForm"), isSigned(0), gradeToSign(1), gradeToExecute(1)
{
	cout << "Default constructor called!\n";
}

AForm::AForm(const AForm& obj) : name(obj.name),
		isSigned(obj.isSigned), gradeToSign(obj.gradeToSign), gradeToExecute(obj.gradeToExecute)
{
	cout << "Default copy constructor called!\n";
}

int	AForm::validation(int grade)
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
	else if (grade > 150)
		throw AForm::GradeTooLowException();
	return grade;
}

AForm::AForm(const std::string& name, int sign, int exec) : name(name), isSigned(0),
		gradeToSign(validation(sign)), gradeToExecute(validation(exec))
{
	cout << "Default constructor called!\n";
}

AForm& AForm::operator=(const AForm& obj)
{
	cout << "Default copy assignment constructor called!\n";
	if (this != &obj)
		this->isSigned = obj.isSigned;
	return *this;
}

AForm::~AForm()
{
	cout << "Default destructor called!\n";
}

std::string	AForm::getName() const
{
	return name;
}

bool		AForm::checkSign() const
{
	return isSigned;
}

int			AForm::getGradeToSign() const
{
	return gradeToSign;
}

int			AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

void		AForm::beSigned(const Bureaucrat& obj)
{
	if (isSigned)
		throw FormAlreadySignedException();
	if (obj.getGrade() <= gradeToSign)
		isSigned = 1;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
	os << "AForm " << obj.getName() << " is "
	   << (obj.checkSign() ? "signed.\n" : "not signed.\n");
	os << "It's grade to sign is " << obj.getGradeToSign()
	   << " and grade to execute is " << obj.getGradeToExecute()
	   << endl;
	return os;
}