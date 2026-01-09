#include "Bureaucrat.hpp"

static void printHeader(const std::string &title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

int main()
{
    /* ========================================================= */
    printHeader("TC-01 / TC-02 / TC-03: Valid constructors");
    try {
        Bureaucrat a("Alice", 42);
        Bureaucrat b("Boss", 1);
        Bureaucrat c("Intern", 150);

        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;
    } catch (std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-04: Grade too high in constructor");
    try {
        Bureaucrat d("Error", 0);
        std::cout << d << std::endl;
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-05: Grade too low in constructor");
    try {
        Bureaucrat e("Error", 151);
        std::cout << e << std::endl;
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-06: incrementGrade normal case");
    try {
        Bureaucrat a("Alice", 42);
        std::cout << a << std::endl;
        a.incrGrade();
        std::cout << a << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-07: decrementGrade normal case");
    try {
        Bureaucrat a("Alice", 42);
        std::cout << a << std::endl;
        a.decrGrade();
        std::cout << a << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-08: incrementGrade at grade 1");
    try {
        Bureaucrat b("Boss", 1);
        std::cout << b << std::endl;
        b.incrGrade();
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-09: decrementGrade at grade 150");
    try {
        Bureaucrat c("Intern", 150);
        std::cout << c << std::endl;
        c.decrGrade();
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-10 / TC-11: what() message check");
    try {
        Bureaucrat x("X", 0);
    } catch (std::exception &e) {
        std::cout << "GradeTooHighException: " << e.what() << std::endl;
    }

    try {
        Bureaucrat y("Y", 151);
    } catch (std::exception &e) {
        std::cout << "GradeTooLowException: " << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-12: operator<< formatting");
    try {
        Bureaucrat a("Alice", 42);
        std::cout << a << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-14: Copy constructor");
    try {
        Bureaucrat a("Alice", 42);
        Bureaucrat b(a);

        std::cout << a << std::endl;
        std::cout << b << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("TC-15: Assignment operator");
    try {
        Bureaucrat a("Alice", 42);
        Bureaucrat b("Bob", 10);

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
    printHeader("TC-16: Multiple increment until exception");
    try {
        Bureaucrat a("Test", 3);
        std::cout << a << std::endl;
        a.incrGrade();
        std::cout << a << std::endl;
        a.incrGrade();
        std::cout << a << std::endl;
        a.incrGrade(); // must throw
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    /* ========================================================= */
    printHeader("END OF TESTS");
    return 0;
}
