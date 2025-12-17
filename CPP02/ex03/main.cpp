#include <iostream>
#include "Point.hpp"

static void printResult(const std::string& test, bool result, bool expected)
{
	cout << test << ": ";
	if (result == expected)
		cout << "\x1B[32mPASS\033[0m";
	else
		cout << "\x1B[31mFAIL\033[0m";
	cout << endl;
}

int main()
{
	cout << "===== POINT & BSP TESTS =====" << endl;

	/* ------------------------------------------------------------ */
	cout << "\n--- Construction tests ---" << endl;

	Point p1;
	Point p2(1.5f, 2.5f);
	Point p3(p2);
	Point p4;
	p4 = p2;

	cout << "Construction / copy / assignment: PASS" << endl;

	/* ------------------------------------------------------------ */
	cout << "\n--- Triangle setup ---" << endl;

	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(0.0f, 10.0f);

	/* ------------------------------------------------------------ */
	cout << "\n--- Inside triangle ---" << endl;

	Point inside(2.0f, 2.0f);
	printResult(
		"Point strictly inside",
		bsp(a, b, c, inside),
		true
	);

	/* ------------------------------------------------------------ */
	cout << "\n--- Outside triangle ---" << endl;

	Point outside(10.0f, 10.0f);
	printResult(
		"Point outside",
		bsp(a, b, c, outside),
		false
	);

	/* ------------------------------------------------------------ */
	cout << "\n--- On edge ---" << endl;

	Point onEdge(5.0f, 0.0f);
	printResult(
		"Point on edge",
		bsp(a, b, c, onEdge),
		false
	);

	/* ------------------------------------------------------------ */
	cout << "\n--- On vertex ---" << endl;

	Point onVertex(0.0f, 0.0f);
	printResult(
		"Point on vertex",
		bsp(a, b, c, onVertex),
		false
	);

	/* ------------------------------------------------------------ */
	cout << "\n--- Degenerate triangle ---" << endl;

	Point d1(0.0f, 0.0f);
	Point d2(5.0f, 5.0f);
	Point d3(10.0f, 10.0f); // collinear

	Point testDegenerate(3.0f, 3.0f);
	printResult(
		"Degenerate triangle",
		bsp(d1, d2, d3, testDegenerate),
		false
	);

	/* ------------------------------------------------------------ */
	cout << "\n--- Negative coordinates ---" << endl;

	Point n1(-5.0f, 0.0f);
	Point n2(5.0f, 0.0f);
	Point n3(0.0f, 5.0f);

	Point negativeInside(0.0f, 1.0f);
	printResult(
		"Negative coordinate triangle",
		bsp(n1, n2, n3, negativeInside),
		true
	);
	/* ------------------------------------------------------------ */
	cout << "\n===== END OF TESTS =====" << endl;

	return 0;
}
