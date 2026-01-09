#include "AForm.hpp"

class PresidentialPardonForm : virtual public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm&);
	PresidentialPardonForm& operator=(const PresidentialPardonForm&);
	~PresidentialPardonForm();
};


