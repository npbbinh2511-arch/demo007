#include "Point.h"

std::istream& operator>>(std::istream& in, Point& point) {
    in >> point.m_x >> point.m_y;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Point& point) {
    out << "(" << point.m_x << ", " << point.m_y << ")";
    return out;
}