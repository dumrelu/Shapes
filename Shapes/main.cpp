#include <iostream>
#include "Point.h"
#include "Segment.h"

int main(int argc, char *argv[])
{
	using namespace shapes;
	using namespace std;

	Segment s1(0, 0, 2, 2);
	Segment s2(2, 0, 0, 2);
	Shape &shape1 = s1, &shape2 = s2;

	std::cout << shape1.collidesWith(shape2) << std::endl;


	std::cin >> s1;
	std::cout << s1;

	std::cin.ignore(2);
	return 0;
}