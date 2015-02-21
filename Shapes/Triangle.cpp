#include "Triangle.h"
using namespace shapes;

Triangle::Triangle()
{
}

Triangle::Triangle(Point p1, Point p2, Point p3)
{
	segments[0] = Segment(p1, p2);
	segments[1] = Segment(p2, p3);
	segments[2] = Segment(p3, p1);
}

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	segments[0] = Segment(x1, y1, x2, y2);
	segments[1] = Segment(x2, y2, x3, y3);
	segments[2] = Segment(x3, y3, x1, y1);
}


Point Triangle::getP1() const { return segments[0].getP1(); }
Point Triangle::getP2() const { return segments[1].getP1(); }
Point Triangle::getP3() const { return segments[2].getP1(); }

void Triangle::setP1(const Point &p1)
{
	segments[0].setP1(p1);
	segments[2].setP2(p1);
}

void Triangle::setP2(const Point &p2)
{
	segments[0].setP2(p2);
	segments[1].setP1(p2);
}

void Triangle::setP3(const Point &p3)
{
	segments[1].setP2(p3);
	segments[2].setP1(p3);
}