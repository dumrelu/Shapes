/*
 * Implementare triunghi.
 */
#pragma once
#include "Shape.h"
#include "Segment.h"
#include "Point.h"

namespace shapes {

	//Triunghiul e memorat sub forma de 3 segmente
	struct Triangle {
		/* Constructori */
		Triangle();
		Triangle(Point p1, Point p2, Point p3);
		Triangle(double x1, double y1, double x2, double y2, double x3, double y3);

		/* Getters and Setters */
		Point getP1() const;
		Point getP2() const;
		Point getP3() const;
		void setP1(const Point &p1);
		void setP2(const Point &p2);
		void setP3(const Point &p3);

		/* Coliziune */
		bool collidesWith(const Shape &s) const;
		bool collidesWith(const Triangle &t) const;
		bool collidesWith(const Segment &s) const;
		bool collidesWith(const Point &p) const;
	private:
		Segment segments[3];
	};

}