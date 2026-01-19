#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void printHeader(const std::string &title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

int main()
{
    /* ========================================================= */
    printHeader("TC-01: Create Bureaucrats");
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat manager("Manager", 50);
        Bureaucrat intern("Intern", 150);

        std::cout << boss << std::endl;
        std::cout << manager << std::endl;
        std::cout << intern << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-02: Create Forms");
    try {
        ShrubberyCreationForm shrub("Home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-03: Execute unsigned form");
    try {
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm shrub("Garden");

        boss.executeForm(shrub);
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-04: Sign but insufficient grade to execute");
    try {
        Bureaucrat manager("Manager", 140);
        ShrubberyCreationForm shrub("Park");

        manager.signForm(shrub);
        manager.executeForm(shrub);
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-05: ShrubberyCreationForm success");
    try {
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm shrub("Forest");

        boss.signForm(shrub);
        boss.executeForm(shrub);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-06: RobotomyRequestForm multiple executions");
    try {
        Bureaucrat boss("Boss", 1);
        RobotomyRequestForm robot("Marvin");

        boss.signForm(robot);
        boss.executeForm(robot);
        boss.executeForm(robot);
        boss.executeForm(robot);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-07: PresidentialPardonForm success");
    try {
        Bureaucrat boss("Boss", 1);
        PresidentialPardonForm pardon("Ford Prefect");

        boss.signForm(pardon);
        boss.executeForm(pardon);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-08: Sign with insufficient grade");
    try {
        Bureaucrat intern("Intern", 150);
        RobotomyRequestForm robot("Bender");

        intern.signForm(robot);
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-09: Execute with insufficient grade");
    try {
        Bureaucrat intern("Intern", 140);
        ShrubberyCreationForm shrub("Office");

        intern.signForm(shrub);
        intern.executeForm(shrub);
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-10: Polymorphism via AForm pointer");
    try {
        Bureaucrat boss("Boss", 1);
        AForm *form = new PresidentialPardonForm("Trillian");

        boss.signForm(*form);
        boss.executeForm(*form);

        delete form;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("END OF TESTS");
    return 0;
}
