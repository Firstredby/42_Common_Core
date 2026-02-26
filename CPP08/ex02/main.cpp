#include <iostream>
#include <list>
#include <string>
#include "MutantStack.hpp"

static void printHeader(const std::string &title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

static void test_basic_stack_behavior()
{
    printHeader("TEST 1: Basic stack behavior");

    MutantStack<int> m;
    m.push(5);
    m.push(17);
    std::cout << "top(): " << m.top() << std::endl; // 17
    m.pop();
    std::cout << "size(): " << m.size() << std::endl; // 1
}

static void test_iteration()
{
    printHeader("TEST 2: Iteration");

    MutantStack<int> m;
    m.push(5);
    m.push(17);
    m.push(3);
    m.push(5);
    m.push(737);
    m.push(0);

    MutantStack<int>::iterator it = m.begin();
    MutantStack<int>::iterator ite = m.end();
    std::cout << "Elements:\n";
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    /*
        5
        17
        3
        5
        737
        0
    */
}

static void test_compare_with_list()
{
    printHeader("TEST 3: Compare with std::list");

    MutantStack<int> mstack;
    std::list<int> lst;
    for (int i = 0; i < 5; ++i)
    {
        mstack.push(i);
        lst.push_back(i);
    }

    MutantStack<int>::iterator mit = mstack.begin();
    std::list<int>::iterator lit = lst.begin();
    while (mit != mstack.end() && lit != lst.end())
    {
        std::cout << *mit << " | " << *lit << std::endl;
        ++mit;
        ++lit;
    }
    /*
        0 | 0
        1 | 1
        2 | 2
        3 | 3
        4 | 4
    */
}

static void test_copy_constructor()
{
    printHeader("TEST 4: Copy constructor");

    MutantStack<int> a;
    a.push(10);
    a.push(20);

    MutantStack<int> b(a);
    b.pop();
    b.push(42);

    std::cout << "a.top(): " << a.top() << std::endl; // 20
    std::cout << "b.top(): " << b.top() << std::endl; // 42
}

static void test_assignment_operator()
{
    printHeader("TEST 5: Assignment operator");

    MutantStack<int> a;
    a.push(1);
    a.push(2);

    MutantStack<int> b;
    b.push(100);
    b = a;
    b.push(42);

    std::cout << "a.size(): " << a.size() << std::endl; // 2
    std::cout << "b.size(): " << b.size() << std::endl; // 3
}

static void test_with_strings()
{
    printHeader("TEST 6: Different type (std::string)");

    MutantStack<std::string> ms;
    ms.push("hello");
    ms.push("mutant");
    ms.push("stack");

    MutantStack<std::string>::iterator it = ms.begin();
    MutantStack<std::string>::iterator ite = ms.end();

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}

static void test_lifo_integrity()
{
    printHeader("TEST 7: LIFO integrity");

    MutantStack<int> m;
    for (int i = 0; i < 5; ++i)
        m.push(i);

    while (!m.empty())
    {
        std::cout << m.top() << std::endl;
        m.pop();
    }
    /*
        Must be:
        4
        3
        2
        1
        0
    */
}

int main()
{
    test_basic_stack_behavior();
    test_iteration();
    test_compare_with_list();
    test_copy_constructor();
    test_assignment_operator();
    test_with_strings();
    test_lifo_integrity();

    return 0;
}
