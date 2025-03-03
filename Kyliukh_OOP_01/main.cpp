#include <iostream>
#include "Triangle.h"

int main()
{
	Point p(1, 2), p2(3, 4), p3(p);

	Triangle t(p, p2, p3);
	p3 += p += p2;
	std::cout << t.isABNullPtr() << ;
	return 0;
}