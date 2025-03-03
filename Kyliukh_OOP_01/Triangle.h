#pragma once
#include "Point.h"

class Triangle
{
public:
	class Segment
	{
	private:
		Point& a, & b;
	};

private:
	Point _a, _b, _c;
	Segment *_ab_ptr,  *_ac_ptr, *_bc_ptr;
};

