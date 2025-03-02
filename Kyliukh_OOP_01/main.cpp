#include <iostream>
#include "Point.h"

int main()
{
	Point p(1, 2), p2(3, 4), p3(p);

	std::cout << std::boolalpha << (p != p2) << ' ' << (p != p3);
	return 0;
}