#include "Point.h"

Point::Point(double x, double y): _x(x), _y(y) {}

Point::Point(const Point& p): _x(p.x()), _y(p.y()) {
#ifndef NDEBUG
	std::cout << "copied!" << std::endl;
#endif 

}

//Point::Point(Point&& p) noexcept : _x(p.x()), _y(p.y())
//{
//	p.x() = 0;
//	p.y() = 0;
//}

//Point::~Point(){}

Point& Point::operator+=(const Point& v)
{
	x() += v.x();
	y() += v.y();
	return *this;
}

Point& Point::operator-=(const Point& v)
{
	x() -= v.x();
	y() -= v.y();
	return *this;
}

Point& Point::operator=(const Point& p)
{
	x() = p.x();
	y() = p.y();
	return *this;
}

//Point& Point::operator=(Point&& p) noexcept
//{
//	x() = p.x();
//	y() = p.y();
//	p.x() = 0;
//	p.y() = 0;
//	return *this;
//}

ostream& operator<< (ostream& out, const Point& p)
{
	out << p.x() << ' ' << p.y();
	return out;
}

_NODISCARD const Point operator+ (const Point& u, const Point& v)
{
	return { u.x() + v.x(), u.y() + v.y()};
}

_NODISCARD const Point operator- (const Point& u, const Point& v)
{
	return { u.x() - v.x(), u.y() - v.y() };
}

bool operator==(const Point& u, const Point& v)
{
	return u.x() == v.x() && u.y() == v.y();
}

bool operator!=(const Point& u, const Point& v)
{
	return !(u == v);
}