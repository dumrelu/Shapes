#include "ComposedShape.h"
using namespace shapes;

bool ComposedShape::collidesWith(const Shape &s) const
{
	for (std::size_t i = 0; i < shapes_.size(); ++i) {
		if (shapes_[i]->collidesWith(s))
			return true;
	}

	return false;
}

void ComposedShape::printToStream(std::ostream &stream) const
{
	stream << "{";
	for (std::size_t i = 0; i < shapes_.size() - 1; ++i)
		stream << *shapes_[i] << ", ";
	if (!shapes_.empty())
		stream << *shapes_.back();
	stream << "}";
}

void ComposedShape::readFromStream(std::istream &stream)
{
	for (std::size_t i = 0; i < shapes_.size(); ++i)
		stream >> *shapes_[i];
}