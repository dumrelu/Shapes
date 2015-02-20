/*
 *	Interfata pentru formele geometrice.
 */
#pragma once

#include <istream>
#include <ostream>

namespace shapes {

	//Clasa de baza pentru forme geometrice.
	struct Shape {
		//Detecteaza coliziune intre formele geometrice
		virtual bool collidesWith(const Shape &s) const { return s.collidesWith(*this);  }

		/* Operatori pentru I/O */
		friend std::ostream &operator<<(std::ostream &stream, const Shape &shape)
		{
			shape.printToStream(stream);
			return stream;
		}

		friend std::istream &operator>>(std::istream &stream, Shape &shape)
		{
			shape.readFromStream(stream);
			return stream;
		}
	protected:
		virtual void printToStream(std::ostream &) const = 0;
		virtual void readFromStream(std::istream &) = 0;
	};
}