#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
private:
    float m_x;
    float m_y;

public:
    Point() : m_x{0.0f}, m_y{0.0f} {}
    Point(float x, float y) : m_x{x}, m_y{y} {}

    float getX() const noexcept { return m_x; }
    float getY() const noexcept { return m_y; }
    void setX(float value) noexcept { m_x = value; }
    void setY(float value) noexcept { m_y = value; }

    // Toán tử luồng thô - không chứa giao diện chữ, dùng được cho cả đọc file/network
    friend std::istream& operator>>(std::istream& in, Point& point);
    friend std::ostream& operator<<(std::ostream& out, const Point& point);
};

#endif // POINT_H