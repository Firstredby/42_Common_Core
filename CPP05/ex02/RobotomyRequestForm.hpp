#include "AForm.hpp"

class RobotomyRequestForm : virtual public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm&);
	RobotomyRequestForm& operator=(const RobotomyRequestForm&);
	~RobotomyRequestForm();
};


