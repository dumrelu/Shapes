#pragma once
#include "Shape.h"
#include <vector>

namespace shapes {

	struct ComposedShape : public Shape {
		bool collidesWith(const Shape &s) const;

	private:
		/* Obliga clasele derivate sa implementeze operatiile de copiere daca au nevoie de ele */
		ComposedShape(const ComposedShape &) { };
		ComposedShape &operator=(const ComposedShape &) { }

	protected:
		void printToStream(std::ostream &) const;
		void readFromStream(std::istream &);

	protected:
		/* Clasa nu poate fi instantiata */
		ComposedShape() { }
		ComposedShape(const std::vector<Shape *> &shapes) : shapes_(shapes) { }

		std::vector<Shape *> shapes_;
	};
}
