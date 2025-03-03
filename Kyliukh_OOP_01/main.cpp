#include <iostream>
#include "Triangle.h"

int main()
{
	Point p(1, 2), p2(3, 4), p3({1,2});

	p3 += p += p2;
	return 0;
}