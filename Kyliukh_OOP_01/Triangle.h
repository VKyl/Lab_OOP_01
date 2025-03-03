#pragma once
#include "Point.h"

class Triangle
{
public:
	class Segment
	{
	private:
		Point& a, &b;
	};

private:
	Point _a, _b, _c;
	Segment *_ab_ptr,  *_ac_ptr, *_bc_ptr;
	// left median impl

public:
	Triangle(const double x1=0, const double y1=0, 
			 const double x2=1, const double y2=0, 
			 const double x3=0, const double y3=1);

	Triangle(const Point& a, const Point& b, const Point& c);

	Triangle(const Triangle& t);
	// Triangle(Triangle&& t); left move constructor decl and iml

	~Triangle();

	//Point& a() { return _a; }
	const Point& a() const { return _a; }

	//Point& b() { return _b; }
	const Point& a() const { return _b; }

	//Point& c() { return _c; }
	const Point& c() const { return _c; }

	const Segment& ab() const;
	const Segment& ac() const;
	const Segment& bc() const;

	//const Segment& ab() const; in question
};

