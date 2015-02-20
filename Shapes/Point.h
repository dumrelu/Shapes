/*
 * Punct 2D.
 */
#pragma once
#include "Shape.h"

namespace shapes {
	//Punct in 2D.
	struct Point : public Shape {
		/* Constructori */
		Point();
		Point(double x, double y);
		Point(double xy);
		
		/* Operatori aritmetici intre puncte */
		Point operator+(const Point& p) const;
		Point operator-(const Point& p) const;
		Point operator*(const Point& p) const;
		Point operator/(const Point& p) const;

		/* Coliziune */
		bool collidesWith(const Shape &s) const;
		bool collidesWith(const Point &p) const;

	protected:
		void printToStream(std::ostream &) const;
		void readFromStream(std::istream &);

	public:
		double x;
		double y;
	};

}