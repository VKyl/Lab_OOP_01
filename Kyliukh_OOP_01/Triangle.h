#pragma once
#include "Point.h"
#include <cmath>

class Triangle
{
public:
	class Segment
	{
	private:
		const Point& _a;
		const Point& _b;

	public:
		Segment(const Point& a, const Point& b) : _a(a), _b(b) {}

		const double length();
		/*{
			const double x = _a.x() - _b.x();
			const double y = _a.y() - _b.y();
			return sqrt(pow(x, 2) + pow(y, 2));
		}*/
		const Point& a() const { return _a; }
		const Point& b() const { return _b; }
	};

private:
	Point _a, _b, _c;
	Segment *_ab_ptr, * _ac_ptr, * _bc_ptr;
	
	Point *_ab_mid_ptr, *_ac_mid_ptr, *_bc_mid_ptr;

public:
	Triangle(const double x1=0, const double y1=0, 
			 const double x2=1, const double y2=0, 
			 const double x3=0, const double y3=1) :
		_a(x1,y1),_b(x2,y2),_c(x3,y3),
		_ab_ptr(nullptr), _ac_ptr(nullptr), _bc_ptr(nullptr),
		_ab_mid_ptr(nullptr), _ac_mid_ptr(nullptr), _bc_mid_ptr(nullptr) { }

	Triangle(const Point& a, const Point& b, const Point& c) :
		_a(a), _b(b), _c(c),
		_ab_ptr(nullptr), _ac_ptr(nullptr), _bc_ptr(nullptr),
		_ab_mid_ptr(nullptr), _ac_mid_ptr(nullptr), _bc_mid_ptr(nullptr) { }

	Triangle(const Triangle& t) :
		_a(t.a()), _b(t.b()), _c(t.c()),
		_ab_ptr(nullptr), _ac_ptr(nullptr), _bc_ptr(nullptr),
		_ab_mid_ptr(nullptr), _ac_mid_ptr(nullptr), _bc_mid_ptr(nullptr) { }

	Triangle(Triangle&& t) : 
		_a(t.a()), _b(t.b()), _c(t.c()),
		_ab_ptr(nullptr), _ac_ptr(nullptr), _bc_ptr(nullptr),
		_ab_mid_ptr(nullptr), _ac_mid_ptr(nullptr), _bc_mid_ptr(nullptr)
	{
		clearTriangle(t);
	}


	~Triangle();

	const Point& a() const { return _a; }
	void a(const double x, const double y);
	void a(const Point& p);
	//void a(Point&& p);

	const Point& b() const { return _b; }
	void b(const double x, const double y);
	void b(const Point& p);
	//void b(Point&& p);

	const Point& c() const { return _c; }
	void c(const double x, const double y);
	void c(const Point& p);
	//void c(Point&& p);

	const Segment& ab();
	const Segment& ac();
	const Segment& bc();

	const Segment& medianAB();
	const Segment& medianAC();
	const Segment& medianBC();

	Triangle& operator=(const Triangle& t);
	Triangle& operator=(Triangle&& t); 

private:
	bool isValidTriangle(const double& a, const double& b, const double& c);
	// return fabs((y1-y2)(x1-x3) - (y1-y3)(x1-x2)) > 1e-14;
	void clearTriangle(Triangle& t);
	// t.a({0, 0});
	// t.b({1, 0});
	// t.c({0, 1});
	void clearSegment(Segment* segment_ptr);
	// if(segment == nullptr) return;
	// delete segment_ptr;
	// segment_ptr = nullptr;
	const Segment& getSegmentOrCalc(Segment* segment_ptr, const Point& p1, const Point& p2);
	// if (segment_ptr == nullptr) segment_ptr = new Segment(p1, p2);
	// return segment;
};

