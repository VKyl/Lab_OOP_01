#include "Triangle.h"
#include "Triangle.h"

Triangle::Segment::Segment(const Point& a, const Point& b) : _a(a), _b(b) {}

const double Triangle::Segment::length()
{
     const double x = a().x() - b().x();
     const double y = a().y() - b().y();
     return sqrt(pow(x, 2) + pow(y, 2));
}

const Point& Triangle::Segment::a() const { return _a; }

const Point& Triangle::Segment::b() const { return _b; }

Triangle::Triangle(const double x1, const double y1, 
                   const double x2, const double y2, 
                   const double x3, const double y3) :
    _a(x1, y1), _b(x2, y2), _c(x3, y3)/*,
    _ab_ptr(nullptr), _ac_ptr(nullptr), _bc_ptr(nullptr),
    _ab_mid_ptr(nullptr), _ac_mid_ptr(nullptr), _bc_mid_ptr(nullptr)*/ {}

Triangle::Triangle(const Point& a, const Point& b, const Point& c) :
    _a(a), _b(b), _c(c)/*,
    _ab_ptr(nullptr), _ac_ptr(nullptr), _bc_ptr(nullptr),
    _ab_mid_ptr(nullptr), _ac_mid_ptr(nullptr), _bc_mid_ptr(nullptr)*/ {}

Triangle::Triangle(const Triangle& t) :
    _a(t.a()), _b(t.b()), _c(t.c())/*,
    _ab_ptr(nullptr), _ac_ptr(nullptr), _bc_ptr(nullptr),
    _ab_mid_ptr(nullptr), _ac_mid_ptr(nullptr), _bc_mid_ptr(nullptr)*/ {}

Triangle::Triangle(Triangle&& t) :
    _a(t.a()), _b(t.b()), _c(t.c())/*,
    _ab_ptr(nullptr), _ac_ptr(nullptr), _bc_ptr(nullptr),
    _ab_mid_ptr(nullptr), _ac_mid_ptr(nullptr), _bc_mid_ptr(nullptr)*/
{   
    if (this == &t) return;
    clearTriangle(t);
}

Triangle::~Triangle()
{
    // implement clean up here
}

const Point& Triangle::a() const { return _a; }

void Triangle::a(const double x, const double y)
{
    // _a = Point(x, y);
}

void Triangle::a(const Point& p)
{
    // _a = p;
}

const Point& Triangle::b() const { return _b; }

void Triangle::b(const double x, const double y)
{
    // _b = Point(x, y);
}

void Triangle::b(const Point& p)
{
    // _b = p;
}

const Point& Triangle::c() const { return _c; }

void Triangle::c(const double x, const double y)
{
    // _c = Point(x, y);
}

void Triangle::c(const Point& p)
{
    // _c = p;
}

const Triangle::Segment& Triangle::ab()
{
     return getSegmentOrCalc(_ab_ptr, _a, _b);
}

const Triangle::Segment& Triangle::ac()
{
     return getSegmentOrCalc(_ac_ptr, _a, _c);
}

const Triangle::Segment& Triangle::bc()
{
     return getSegmentOrCalc(_bc_ptr, _b, _c);
}

const Triangle::Segment& Triangle::medianAB()
{
    // return getSegmentOrCalc(_ab_mid_ptr, (_a + _b) / 2, _c);
}

const Triangle::Segment& Triangle::medianAC()
{
    // return getSegmentOrCalc(_ac_mid_ptr, (_a + _c) / 2, _b);
}

const Triangle::Segment& Triangle::medianBC()
{
    // return getSegmentOrCalc(_bc_mid_ptr, (_b + _c) / 2, _a);
}

Triangle& Triangle::operator=(const Triangle& t)
{
    // Add assignment logic here
    return *this;
}

Triangle& Triangle::operator=(Triangle&& t)
{
    // Add move assignment logic here
    return *this;
}

bool Triangle::isValidTriangle(const double& a, const double& b, const double& c)
{
    // return fabs((y1 - y2) * (x1 - x3) - (y1 - y3) * (x1 - x2)) > 1e-14;
}

void Triangle::clearTriangle(Triangle& t)
{
    // t.a({0, 0});
    // t.b({1, 0});
    // t.c({0, 1});
}

void Triangle::clearSegment(Segment* segment_ptr)
{
    // if(segment == nullptr) return;
    // delete segment_ptr;
    // segment_ptr = nullptr;
}

const Triangle::Segment& Triangle::getSegmentOrCalc(Segment* segment_ptr, const Point& p1, const Point& p2)
{
     if (segment_ptr == nullptr) segment_ptr = new Segment(p1, p2);
     return *segment_ptr;
}
