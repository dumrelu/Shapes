#include "Point.h"
#ifdef SHAPES_PRINT
#include <iostream>
#endif
using namespace shapes;

Point::Point() : x(0), y(0)
{
}

Point::Point(double x, double y) : x(x), y(y)
{
}

Point::Point(double xy) : x(xy), y(xy)
{
}


Point Point::operator+(const Point& p) const
{
	return Point(x + p.x, y + p.y);
}

Point Point::operator-(const Point& p) const
{
	return Point(x - p.x, y - p.y);
}

Point Point::operator*(const Point& p) const
{
	return Point(x * p.x, y * p.y);
}

Point Point::operator/(const Point& p) const
{
	return Point(x / p.x, y / p.y);
}


bool Point::collidesWith(const Shape &s) const
{
#ifdef SHAPES_PRINT
	std::clog << "Point::collidesWith(const Shape &s)" << std::endl;
#endif

	if (const Point *p = dynamic_cast<const Point*>(&s))
		return collidesWith(*p);
	else 
		return Shape::collidesWith(s);
}
bool Point::collidesWith(const Point &p) const
{
#ifdef SHAPES_PRINT
	std::clog << "Point::collidesWith(const Point &p)" << std::endl;
#endif

	return (x == p.x && y == p.y);
}


void Point::printToStream(std::ostream &stream) const
{
	stream << "(" << x << ", " << y << ")";
}
void Point::readFromStream(std::istream &stream)
{
	stream >> x >> y;
}