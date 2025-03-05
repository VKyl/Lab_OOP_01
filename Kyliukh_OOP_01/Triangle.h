#pragma once
#include "Point.h"
#include <cassert>
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
		Segment(const Point& a, const Point& b);

		const double length();

		const Point& a() const;
		const Point& b() const;
	};

private:
	Point _a, _b, _c;
	Segment *_ab_ptr = nullptr, 
		    * _ac_ptr = nullptr, 
		    * _bc_ptr = nullptr;
	
	Segment* _ab_m_ptr = nullptr,
		* _ac_m_ptr = nullptr,
		* _bc_m_ptr = nullptr;

	Point *_ab_m_p_ptr = nullptr, 
		  *_ac_m_p_ptr = nullptr, 
		  *_bc_m_p_ptr = nullptr;

public:
	Triangle(const double x1 = 0, const double y1 = 0,
		const double x2 = 1, const double y2 = 0,
		const double x3 = 0, const double y3 = 1);

	Triangle(const Point& a, const Point& b, const Point& c);

	Triangle(const Triangle& t);

	Triangle(Triangle&& t) noexcept;

	~Triangle();

	const Point& a() const;
	void a(const double x, const double y);
	void a(const Point& p);
	//void a(Point&& p);

	const Point& b() const;
	void b(const double x, const double y);
	void b(const Point& p);
	//void b(Point&& p);

	const Point& c() const;
	void c(const double x, const double y);
	void c(const Point& p);
	//void c(Point&& p);

	const Segment& ab();
	const Segment& ac();
	const Segment& bc();

	const Point& mPointAB();
	const Point& mPointAC();
	const Point& mPointBC();

	const Segment& medianAB();
	const Segment& medianAC();
	const Segment& medianBC();

	Triangle& operator=(const Triangle& t);
	Triangle& operator=(Triangle&& t) noexcept; 

private:
	//bool isSharingLine(const Point& a, const Point& b, const Point& c);
	// return fabs((y1-y2)(x1-x3) - (y1-y3)(x1-x2)) > 1e-14;
	void clearTriangle(Triangle& t);

	void clearSideRelatedPtrs(Point* m_p_ptr, Segment* m_ptr);
	// t.a({0, 0});
	// t.b({1, 0});
	// t.c({0, 1});
	//void clearSegment(Segment* segment_ptr);
	// if(segment == nullptr) return;
	// delete segment_ptr;
	// segment_ptr = nullptr;
	//void clearPoint(Point* point_ptr);

	const Point& getMidPointOrCalc(Point* m_p_ptr, const Point& p1, const Point& p2);
	const Segment& getSegmentOrCalc(Segment* segment_ptr, const Point& p1, const Point& p2);
	// if (segment_ptr == nullptr) segment_ptr = new Segment(p1, p2);
	// return segment;
};

