#pragma once

#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string	name;
	bool				isSigned;
	const int	gradeToSign;
	const int	gradeToExecute;
public:
	Form();
	Form(const Form&);
	Form();
	Form& operator=(const Form&);
	~Form();

	std::string	getName() const;
	bool		checkSign() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() {
			return "Grade is too high!\n";
		}
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() {
			return "Grade is too low!\n";
		}
	};

	class FormAlreadySignedException : public std::exception {
	public:
		const char* what() const throw() {
			return "Form is already signed!\n";
		}
	};
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);
