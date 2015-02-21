#include "Triangle.h"
#include <algorithm>
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


bool Triangle::collidesWith(const Shape &s) const
{
	if (const Triangle *t = dynamic_cast<const Triangle*>(&s))
		return collidesWith(*t);
	else if (const Segment *sg = dynamic_cast<const Segment*>(&s))
		return collidesWith(*sg);
	else if (const Point *p = dynamic_cast<const Point*>(&s))
		return collidesWith(*p);
	else
		return Shape::collidesWith(s);
}

/*
 *	Verifica daca se intersecteaza laturile si apoi daca unul 
 * dintre triunghiuri se afla in celalat.
 */
bool Triangle::collidesWith(const Triangle &t) const
{
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (segments[i].collidesWith(t.segments[j]))
				return true;
		}
	}

	//Daca t e in interiorul lui this sau this e in interiorul lui t
	return (collidesWith(t.segments[0].getP1(), false) || t.collidesWith(segments[0].getP1(), false));
}

/*
 *	Verifica mai intai daca segmentul se intersecteaza cu 
 * vreo latura a triunghiului apoi verifica daca segmentul
 * se afla in interiorul triunghiului.
 *	Un segment se afla in interiorul triunghiului daca 
 * oricare din punctele segmentului se afla in interior.
 */
bool Triangle::collidesWith(const Segment &s) const
{
	for (int i = 0; i < 3; ++i) {
		if (s.collidesWith(segments[i]))
			return true;
	}

	return collidesWith(s.getP1(), false);
}

/*
 * S1 < S2 daca S1.p1.x < S2.p2.x
 */
bool cmpSegmentP1X(const Segment &s1, const Segment &s2)
{
	return (s1.getP1().x < s2.getP1().x);
}

/*
 *	Pentru a verifica daca un punct "se ciocneste" cu un
 * triunghi se ia un punct din afara triunghiului si se creaza
 * un segment de la punctul p la punctul din afara.
 *	Daca segmentul nou intersecteaza doar o singura latura a triunghiului
 * atunci a avut loc o coliziune.
 *	checkIfOnEdge indica daca se verifica daca punctul se afla pe
 * laturile triunghiului.
 */
bool Triangle::collidesWith(const Point &p, bool checkIfOnEdge) const
{
	if (checkIfOnEdge) {
		for (int i = 0; i < 3; ++i) {
			if (segments[i].collidesWith(p))
				return true;
		}
	}

	//Ca punct din afara triunghiului se alege punctul 
	//cu x = x_max+1
	Point p_max = std::max_element(segments, segments + 3, cmpSegmentP1X)->getP1();
	p_max = p_max + Point(1, 0);
	Segment new_segment(p, p_max);

	//Calculeaza cate laturi se intersecteaza cu segmentul nou
	int n_intersections = 0;
	for (int i = 0; i < 3; ++i) {
		if (segments[i].collidesWith(new_segment) && ++n_intersections > 1)
			return false;
	}
	
	return (n_intersections == 1);
}


void Triangle::printToStream(std::ostream &stream) const
{
	stream << "[" << getP1() << ", " << getP2() << ", " << getP3() << "]";
}

void Triangle::readFromStream(std::istream &stream)
{
	Point points[3];
	stream >> points[0] >> points[1] >> points[2];

	*this = Triangle(points[0], points[1], points[2]);
}