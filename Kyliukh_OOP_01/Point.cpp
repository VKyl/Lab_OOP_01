#include "Point.h"
Point::Point(double x, double y): _x(x), _y(y) {}

Point::Point(const Point& p): _x(p.x()), _y(p.y()) {}

Point::~Point(){}

Point& Point::operator=(const Point& p)
{
	_x = p.x();
	_y = p.y();
	return *this;
}

ostream& operator<< (ostream& out, const Point& p)
{
	out << p.x() << ' ' << p.y();
	return out;
}

const Point operator+ (const Point& u, const Point& v)
{
	return { u.x() + v.x(), u.y() + v.y()};
}

const Point operator- (const Point& u, const Point& v)
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