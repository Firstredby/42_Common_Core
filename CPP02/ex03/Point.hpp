#include "Fixed.hpp"

class Point
{
private:
	const Fixed x,y;
public:
	Point();
	Point(float, float);
	Point(const Point&);
	Point& operator=(const Point&);

	const Fixed& getX() const;
	const Fixed& getY() const;
	~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);