#include "Fixed.hpp"
#include <limits>
#include <cassert>

void test_constructors() {
    cout << "\n=== Constructor Tests ===\n";

    Fixed a;                     // Default
    cout << "Default: " << a << "\n";

    Fixed b(5);                  // Int constructor
    cout << "From int 5: " << b << "\n";

    Fixed c(5.5f);               // Float constructor
    cout << "From float 5.5: " << c << "\n";

    Fixed d(b);                  // Copy constructor
    cout << "Copy of b: " << d << "\n";

}

void test_assignment_operator() {
    cout << "\n=== Assignment Operator Tests ===\n";

    Fixed a(10);
    Fixed b;

    b = a;
    cout << "b = a => " << b << "\n";

    a = static_cast<Fixed&>(a);   // Self-assignment test
    cout << "Self-assign a = a: " << a << "\n";
}

void test_comparisons() {
    cout << "\n=== Comparison Tests ===\n";

    Fixed a(10), b(10), c(20);

    cout << "a == b: " << (a == b) << "\n";
    cout << "a != c: " << (a != c) << "\n";
    cout << "a <  c: " << (a <  c) << "\n";
    cout << "a <= b: " << (a <= b) << "\n";
    cout << "c >  a: " << (c >  a) << "\n";
    cout << "c >= a: " << (c >= a) << "\n";
}

void test_arithmetic() {
    cout << "\n=== Arithmetic Tests ===\n";

    Fixed x(10);
    Fixed y(3);

    cout << "x + y = " << x + y << "\n";
    cout << "x - y = " << x - y << "\n";
    cout << "x * y = " << x * y << "\n";
    cout << "x / y = " << x / y << "\n";

    // Try division by zero
    Fixed z(0);
    cout << "x / 0 = " << (x / z) << "\n";
}

void test_increment() {
    cout << "\n=== Increment Tests ===\n";

    Fixed a(0);

    cout << "a = " << a << "\n";

    cout << "++a = " << ++a << " (prefix)\n";
    cout << "a++ = " << a++ << " (postfix)\n";
    cout << "after a++ => " << a << "\n";

    cout << "--a = " << --a << " (prefix)\n";
    cout << "a-- = " << a-- << " (postfix)\n";
    cout << "after a-- => " << a << "\n";
}

void test_min_max() {
    cout << "\n=== Min/Max Tests ===\n";

    Fixed a(10), b(20);

    cout << "min(a,b) = " << Fixed::min(a, b) << "\n";
    cout << "max(a,b) = " << Fixed::max(a, b) << "\n";

    Fixed c(-5);

    cout << "min(a,c) = " << Fixed::min(a, c) << "\n";
    cout << "max(a,c) = " << Fixed::max(a, c) << "\n";
}

int main() {
    test_constructors();
    test_assignment_operator();
    test_comparisons();
    test_arithmetic();
    test_increment();
    test_min_max();

    return 0;
}

