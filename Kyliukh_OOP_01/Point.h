#pragma once
#include <iostream>
using std::ostream;

class Point
{
private:
	double _x;
	double _y;
public:
	Point(double x = 0, double y = 0);
	Point(const Point&);
	Point(Point&&) noexcept;
	~Point();

	Point& operator=(const Point&);
	Point& operator=(Point&&) noexcept;

	double& x(){ return _x; }
	double& y() { return _y; }
	const double& x() const { return _x; }
	const double& y() const { return _y; }
};

ostream& operator<<(ostream&, const Point&);

[[nodiscard]] const Point operator+ (const Point& u, const Point& v) ;
[[nodiscard]] const Point operator- (const Point& u, const Point& v);
Point& operator+=(Point&, const Point&);
Point& operator-=(Point&, const Point&);
bool operator==(const Point& u, const Point& v);
bool operator!=(const Point& u, const Point& v);


