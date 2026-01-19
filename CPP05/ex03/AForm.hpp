#pragma once

#include <iostream>

using std::cout;
using std::endl;

class Bureaucrat;

class AForm
{
private:
	const std::string	name;
	bool				isSigned;
	const int			gradeToSign;
	const int			gradeToExecute;
	static int			validation(int);
public:
	AForm();
	AForm(const AForm&);
	AForm(const std::string&, int, int);
	AForm& operator=(const AForm&);
	virtual ~AForm();

	std::string	getName() const;
	bool		checkSign() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	void		beSigned(const Bureaucrat&);
	virtual void		execute(Bureaucrat const & executor) const = 0;

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

	class FormNotSignedException : public std::exception {
	public:
		const char* what() const throw() {
			return "Form is not signed!\n";
		}
	};

	class LowGradeExecution : public std::exception {
	public:
		const char* what() const throw() {
			return "Grade is too low for execution!\n";
		}
	};
};

std::ostream& operator<<(std::ostream&, const AForm&);
