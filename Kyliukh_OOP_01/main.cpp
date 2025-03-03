#include <iostream>
#include "Triangle.h"

int main()
{
	Point p(1, 2), p2(p), p3({1,2});
	p3 + p2;
	p3 += p += p2;
	std::cout << p3;
	return 0;
}