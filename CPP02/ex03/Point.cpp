#include "Point.hpp"

Point::Point(/* args */) : x(0), y(0)
{
}

Point::Point(float xpos, float ypos) : x(xpos), y(ypos)
{
}

Point::Point(const Point& obj) : x(obj.getX()), y(obj.getY())
{
	//Point::operator=(obj);
}

Point& Point::operator=(const Point&)
{
	// How tf i should assign const values?
	std::cerr << "Class can't be assigned due to const values\n";
	return *this;
}

Point::~Point()
{
}

const Fixed& Point::getX() const
{
	return this->x;
}
const Fixed& Point::getY() const
{
	return this->y;
}
