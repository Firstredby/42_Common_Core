#include "AForm.hpp"

class ShrubberyCreationForm : virtual public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm&);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
	~ShrubberyCreationForm();
};
