#include "Segment.h"
#ifdef SHAPES_PRINT
#include <iostream>
#endif
using namespace shapes;

Segment::Segment() : p1(0, 0), p2(0, 0)
{
}

Segment::Segment(Point p1, Point p2) : p1(p1), p2(p2)
{
}

Segment::Segment(double x1, double y1, double x2, double y2) : p1(x1, y1), p2(x2, y2)
{
}


bool Segment::collidesWith(const Shape &s) const
{
#ifdef SHAPES_PRINT
	std::clog << "Segment::collidesWith(const Shape &s)" << std::endl;
#endif

	if (const Segment *sh = dynamic_cast<const Segment*>(&s))
		return collidesWith(*sh);
	else if (const Point *p = dynamic_cast<const Point*>(&s))
		return collidesWith(*p);
	else
		return Shape::collidesWith(s);
}

bool Segment::collidesWith(const Segment &s) const
{
#ifdef SHAPES_PRINT
	std::clog << "Segment::collidesWith(const Segment &s)" << std::endl;
#endif
	if (p1 == s.p1 || p1 == s.p2 ||
		p2 == s.p1 || p2 == s.p2)
		return true;
	return intersectionPoint(s).first;
}

//Creaza un segment cu p1 = p, p2 = p+eps si apeleaza
//metoda de coliziune cu segment.
bool Segment::collidesWith(const Point &p) const
{
#ifdef SHAPES_PRINT
	std::clog << "Segment::collidesWith(const Point &p)" << std::endl;
#endif

	Segment s(p, p+0.0001);

	return collidesWith(s);
}


/*
 *	Un punct dupa un segment(segmentul AB) se poate scrie in felul urmator:
 *				P = (1-t)*A + t*B, cu t in [0, 1]
 *
 *	Pentru a gasi punctul de intersectie a doua segmente AB si CD se rezulva sistemul
 * de ecuatii rezultat din expresia:
 *			(1-t1)*A + t1*B = (1-t2)*C + t2*D, cu t1, t1 in [0, 1].
 *
 *	Sistemul rezultat:
 *			{ (B.x - A.x)*t1 + (C.x - D.x)*t2 = C.x - A.x
 *			{ (B.y - A.y)*t1 + (C.y - D.y)*t2 = C.y - A.y
 *
 * Sistemul se rezulza cu regula lui Crammer:
 *		http://www.e-formule.ro/wp-content/uploads/regula-lui-cramer.htm
*/
std::pair<bool, Point> Segment::intersectionPoint(const Segment &s) const
{
	/* Coeficienti */
	const double a[2][2] = {
		{ p2.x - p1.x, s.p1.x - s.p2.x },
		{ p2.y - p1.y, s.p1.y - s.p2.y },
	};

	const double b[2] = {
		s.p1.x - p1.x,
		s.p1.y - p1.y
	};

	/* Delta */
	double delta = (a[0][0] * a[1][1]) - (a[0][1] * a[1][0]);

	if (delta == 0)
		return std::make_pair(false, Point());	//Dreptele sunt paralele

	/* t-urile */
	double t1 = ((b[0] * a[1][1]) - (a[0][1] * b[1])) / delta;
	double t2 = ((a[0][0] * b[1]) - (b[0] * a[1][0])) / delta;

	/* Punctul de intersectie */
	if (t1 >= 0.0 && t1 <= 1.0 && t2 >= 0.0 && t2 <= 1.0) {	//Daca se intersecteaza
		Point intersection = p1 * (1 - t1) + p2 * t1;

		return std::make_pair(true, intersection);
	}
	
	return std::make_pair(false, Point());
}

void Segment::printToStream(std::ostream &stream) const
{
	stream << "[" << p1 << ", " << p2 << "]";
}

void Segment::readFromStream(std::istream &stream)
{
	stream >> p1 >> p2;
}