/*
 * Implementare segment.
 */
#pragma once
#include "Shape.h"
#include "Point.h"
#include <utility>

namespace shapes {

	//Reprezinta un segment de la punctul
	//p1 la punctul p1.
	struct Segment : public Shape {
		/* Constructori */
		Segment();
		Segment(Point p1, Point p2);
		Segment(double x1, double y1, double x2, double y2);

		/* Getters and Setters */
		Point getP1() const { return p1; }
		Point getP2() const { return p2; }
		void setP1(Point p1) { this->p1 = p1; }
		void setP2(Point p2) { this->p2 = p2; }

		/* Coliziune */
		bool collidesWith(const Shape &s) const;
		bool collidesWith(const Segment &s) const;
		bool collidesWith(const Point &p) const;

		//Returneaza punctul de intersectie dintre segmente.
		//Daca .first == true atunci dreptele se intersecteaza
		//in punctul .second.
		std::pair<bool, Point> intersectionPoint(const Segment &s) const;

	protected:
		void printToStream(std::ostream &) const;
		void readFromStream(std::istream &);

	private:
		Point p1;
		Point p2;
	};

}
