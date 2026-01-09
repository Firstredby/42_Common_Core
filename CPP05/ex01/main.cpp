#include "Bureaucrat.hpp"
#include "Form.hpp"

static void printHeader(const std::string &title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

int main()
{
    /* ========================================================= */
    printHeader("TC-01 / TC-02 / TC-03: Valid Form constructors");
    try {
        Form a("TaxForm", 50, 25);
        Form b("TopSecret", 1, 1);
        Form c("LowLevel", 150, 150);

        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;
    } catch (std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-04: signGrade < 1");
    try {
        Form f("Error", 0, 50);
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-05: signGrade > 150");
    try {
        Form f("Error", 151, 50);
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-06: execGrade < 1");
    try {
        Form f("Error", 50, 0);
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-07: execGrade > 150");
    try {
        Form f("Error", 50, 151);
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-08: beSigned success");
    try {
        Bureaucrat b("Alice", 40);
        Form f("Contract", 50, 20);

        std::cout << f << std::endl;
        f.beSigned(b);
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-09: beSigned failure (grade too low)");
    try {
        Bureaucrat b("Bob", 100);
        Form f("Contract", 50, 20);

        std::cout << f << std::endl;
        f.beSigned(b);
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-10: beSigned already signed");
    try {
        Bureaucrat b("Alice", 1);
        Form f("Contract", 50, 20);

        f.beSigned(b);
        f.beSigned(b); // second attempt
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-11: Bureaucrat::signForm success");
    try {
        Bureaucrat b("Alice", 40);
        Form f("Permit", 50, 20);

        b.signForm(f);
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-12: Bureaucrat::signForm failure");
    try {
        Bureaucrat b("Bob", 100);
        Form f("Permit", 50, 20);

        b.signForm(f);
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-13: operator<< formatting");
    try {
        Form f("TaxForm", 50, 25);
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-14: Copy constructor");
    try {
        Form a("A", 50, 25);
        Form b(a);

        std::cout << a << std::endl;
        std::cout << b << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-15: Assignment operator (const fields)");
    try {
        Form a("A", 50, 25);
        Form b("B", 10, 5);

        a.beSigned(Bureaucrat("Boss", 1));

        std::cout << "Before assignment:" << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;

        b = a;

        std::cout << "After assignment:" << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-16: Full scenario");
    try {
        Bureaucrat boss("Boss", 1);
        Form f("TopSecret", 1, 1);

        boss.signForm(f);
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("END OF TESTS");
    return 0;
}
