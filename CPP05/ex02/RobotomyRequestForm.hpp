#include "AForm.hpp"

class RobotomyRequestForm : virtual public AForm
{
private:
	std::string target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm&);
	RobotomyRequestForm(std::string);
	RobotomyRequestForm& operator=(const RobotomyRequestForm&);
	~RobotomyRequestForm();

	void		execute(Bureaucrat const & executor) const;
};


