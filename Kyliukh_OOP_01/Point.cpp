#include "Point.h"
Point::Point(double x, double y): _x(x), _y(y) {}

Point::Point(const Point& p): _x(p.x()), _y(p.y()) {}

Point::Point(Point&& p) : _x(p.x()), _y(p.y())
{
	p.x() = 0;
	p.y() = 0;
}

Point::~Point(){}

Point& Point::operator=(const Point& p)
{
	x() = p.x();
	y() = p.y();
	return *this;
}

Point& Point::operator=(Point&& p)
{
	x() = p.x();
	y() = p.y();
	p.x() = 0;
	p.y() = 0;
	return *this;
}

ostream& operator<< (ostream& out, const Point& p)
{
	out << p.x() << ' ' << p.y();
	return out;
}

[[nodiscard]] const Point& operator+ (const Point& u, const Point& v)
{
	return { u.x() + v.x(), u.y() + v.y()};
}

[[nodiscard]] const Point& operator- (const Point& u, const Point& v)
{
	return { u.x() - v.x(), u.y() - v.y() };
}

Point& operator+=(Point& u, const Point& v)
{
	u.x() +=  v.x();
	u.y() += v.y();
	return u;
}

Point& operator-=(Point& u, const Point& v)
{
	u.x() -= v.x();
	u.y() -= v.y();
	return u;
}

bool operator==(const Point& u, const Point& v)
{
	return u.x() == v.x() && u.y() == v.y();
}

bool operator!=(const Point& u, const Point& v)
{
	return !(u == v);
}