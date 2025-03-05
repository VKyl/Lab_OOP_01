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
    _a(x1, y1), _b(x2, y2), _c(x3, y3) 
{
    assert(!isSharingLine(_a, _b, _c));
}

Triangle::Triangle(const Point& a, const Point& b, const Point& c) :
    _a(a), _b(b), _c(c) 
{
    assert(!isSharingLine(_a, _b, _c));
}

Triangle::Triangle(const Triangle& t) :
    _a(t.a()), _b(t.b()), _c(t.c()) {}

Triangle::Triangle(Triangle&& t) noexcept :
    _a(t.a()), _b(t.b()), _c(t.c()) 
{   
    if (this == &t) return;
    clearTriangle(t);
}

Triangle::~Triangle()
{
    clearSideRelatedPtrs(_ab_m_p_ptr, _ab_m_ptr);
    clearSideRelatedPtrs(_ac_m_p_ptr, _ac_m_ptr);
    clearSideRelatedPtrs(_bc_m_p_ptr, _bc_m_ptr);
    clearPtr(_ab_ptr);
    clearPtr(_ac_ptr);
    clearPtr(_bc_ptr);
}

const Point& Triangle::a() const { return _a; }

void Triangle::a(const double x, const double y)
{
     _a = Point(x, y);
     assert(!isSharingLine(_a, _b, _c));
     clearSideRelatedPtrs(_ab_m_p_ptr, _ab_m_ptr);
     clearSideRelatedPtrs(_ac_m_p_ptr, _ac_m_ptr);
}

void Triangle::a(const Point& p)
{
     _a = p;
     assert(isSharingLine(_a, _b, _c));
     clearSideRelatedPtrs(_ab_m_p_ptr, _ab_m_ptr);
     clearSideRelatedPtrs(_ac_m_p_ptr, _ac_m_ptr);
}

const Point& Triangle::b() const { return _b; }

void Triangle::b(const double x, const double y)
{
     _b = Point(x, y);
     assert(isSharingLine(_a, _b, _c));
     clearSideRelatedPtrs(_ab_m_p_ptr, _ab_m_ptr);
     clearSideRelatedPtrs(_bc_m_p_ptr, _bc_m_ptr);
}

void Triangle::b(const Point& p)
{
     _b = p;
     assert(isSharingLine(_a, _b, _c));
     clearSideRelatedPtrs(_ab_m_p_ptr, _ab_m_ptr);
     clearSideRelatedPtrs(_bc_m_p_ptr, _bc_m_ptr);
}

const Point& Triangle::c() const { return _c; }

void Triangle::c(const double x, const double y)
{
     _c = Point(x, y);
     assert(isSharingLine(_a, _b, _c));
     clearSideRelatedPtrs(_ab_m_p_ptr, _ab_m_ptr);
     clearSideRelatedPtrs(_bc_m_p_ptr, _bc_m_ptr);
}

void Triangle::c(const Point& p)
{
     _c = p;
     assert(isSharingLine(_a, _b, _c));
     clearSideRelatedPtrs(_ac_m_p_ptr, _ac_m_ptr);
     clearSideRelatedPtrs(_bc_m_p_ptr, _bc_m_ptr);
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

const Point& Triangle::mPointAB() { return getMidPointOrCalc(_ab_m_p_ptr, _a, _b); }
const Point& Triangle::mPointAC() { return getMidPointOrCalc(_ac_m_p_ptr, _a, _c); }
const Point& Triangle::mPointBC() { return getMidPointOrCalc(_bc_m_p_ptr, _b, _c); }

const Triangle::Segment& Triangle::medianAB() { return getSegmentOrCalc(_ab_m_ptr, _c, *_ab_m_p_ptr); }

const Triangle::Segment& Triangle::medianAC() { return getSegmentOrCalc(_ac_m_ptr, _b, *_ac_m_p_ptr); }

const Triangle::Segment& Triangle::medianBC() { return getSegmentOrCalc(_bc_m_ptr, _a, *_bc_m_p_ptr); }

Triangle& Triangle::operator=(const Triangle& t)
{
    // Add assignment logic here
    return *this;
}

Triangle& Triangle::operator=(Triangle&& t) noexcept
{
    // Add move assignment logic here
    return *this;
}

void Triangle::clearTriangle(Triangle& t)
{
     t.a({0, 0});
     t.b({1, 0});
     t.c({0, 1});
}

void Triangle::clearSideRelatedPtrs(Point* m_p_ptr, Segment* m_ptr)
{
    clearPtr(m_p_ptr);
    clearPtr(m_ptr);
}

const Point& Triangle::getMidPointOrCalc(Point* m_p_ptr, const Point& p1, const Point& p2)
{
    if (m_p_ptr == nullptr) m_p_ptr = new Point((p1.x() + p2.x()) / 2, (p1.y() + p2.y()) / 2);
    return *m_p_ptr;
}

const Triangle::Segment& Triangle::getSegmentOrCalc(Segment* segment_ptr, const Point& p1, const Point& p2)
{
     if (segment_ptr == nullptr) segment_ptr = new Segment(p1, p2);
     return *segment_ptr;
}

template <typename T>
void clearPtr(T* segment_ptr)
{
     if(segment_ptr == nullptr) return;
     delete segment_ptr;
     segment_ptr = nullptr;
}
