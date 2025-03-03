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
	// left median impl

public:
	Triangle(const double x1, const double y1, 
			 const double x2, const double y2, 
			 const double x3, const double y3);

	Triangle(const Triangle& t);
	// Triangle(Triangle&& t); left move constructor decl and iml


	Point& a() { return _a; }
	const Point& a() const { return _a; }

	Point& b() { return _b; }
	const Point& a() const { return _b; }

	Point& c() { return _c; }
	const Point& c() const { return _c; }

	const Segment& ab();
	const Segment& ac();
	const Segment& bc();

	//const Segment& ab() const; in question
};

