#include <iostream>

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "\n========== TC-01: Create Intern ==========\n";
    {
        Intern intern;
    }

    std::cout << "\n========== TC-02: makeForm ShrubberyCreationForm ==========\n";
    {
        Intern intern;
        AForm *form = intern.makeForm("shrubbery creation", "Garden");

        if (form)
        {
            std::cout << *form;
            delete form;
        }
    }

    std::cout << "\n========== TC-03: makeForm RobotomyRequestForm ==========\n";
    {
        Intern intern;
        AForm *form = intern.makeForm("robotomy request", "Bender");

        if (form)
        {
            std::cout << *form;
            delete form;
        }
    }

    std::cout << "\n========== TC-04: makeForm PresidentialPardonForm ==========\n";
    {
        Intern intern;
        AForm *form = intern.makeForm("presidential pardon", "Ford Prefect");

        if (form)
        {
            std::cout << *form;
            delete form;
        }
    }

    std::cout << "\n========== TC-05: makeForm unknown form ==========\n";
    {
        Intern intern;
        AForm *form = intern.makeForm("tax evasion", "Nobody");

        if (!form)
            std::cout << "Form creation failed as expected.\n";
        else
            delete form;
    }

    std::cout << "\n========== TC-06: Full workflow ==========\n";
    {
        Intern intern;
        Bureaucrat boss("Boss", 1);

        AForm *form = intern.makeForm("robotomy request", "Marvin");

        if (form)
        {
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }
    }

    std::cout << "\n========== TC-07: Polymorphism via AForm* ==========\n";
    {
        Intern intern;
        Bureaucrat boss("Boss", 1);

        AForm *form = intern.makeForm("presidential pardon", "Trillian");

        if (form)
        {
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }
    }

    std::cout << "\n========== TC-08: Multiple makeForm calls ==========\n";
    {
        Intern intern;

        AForm *f1 = intern.makeForm("shrubbery creation", "Home");
        AForm *f2 = intern.makeForm("robotomy request", "R2D2");
        AForm *f3 = intern.makeForm("presidential pardon", "Arthur Dent");

        delete f1;
        delete f2;
        delete f3;
    }

    std::cout << "\n========== TC-09: Memory ownership ==========\n";
    {
        Intern intern;
        AForm *form = intern.makeForm("shrubbery creation", "Park");

        // Intern does NOT own the form
        delete form;
    }

    std::cout << "\n========== TC-10: Subject scenario ==========\n";
    {
        Intern someRandomIntern;
        AForm *rrf;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");

        if (rrf)
            delete rrf;
    }

    std::cout << "\n========== END OF TESTS ==========\n";
    return 0;
}
