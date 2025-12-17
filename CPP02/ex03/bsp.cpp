#include "Point.hpp"

static float area(const Point p1, const Point p2, const Point p3)
{
	float a = p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat());
    float b = p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat());
    float c = p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat());
	float area = (a + b + c) / 2.0f;
	if (area >= 0)
		return (area);
	else
		return (area * -1);
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	float S, S1, S2, S3;
	bool ret_val = false;

	S = area(a, b, c);
	S1 = area(point, a, b);
	S2 = area(point, b, c);
	S3 = area(point, a, c);

	if ( S1 == 0 || S2 == 0 || S3 == 0)
		ret_val = false;
	else if ( S1 + S2 + S3 == S )
		ret_val = true;

	return (ret_val);
}
