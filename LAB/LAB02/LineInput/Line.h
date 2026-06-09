#ifndef LINE_H
#define LINE_H

#include <print>
#include <iostream>
#include "../Point/Point.h"

using namespace std;

class Line{
private:
    Point _start;
    Point _end;
public:
    Line() : _start(0, 0), _end(0, 0) {}
    Line(Point start, Point end) : _start{start}, _end{end} {}
public:
    void inputLine();
    Point getStartPoint() const noexcept {return _start;}
    Point getEndPoint() const noexcept {return _end;}
    void setStartPoint(const Point &start) noexcept {_start = start;}
    void setEndPoint(const Point &end) noexcept {_end = end;}
    friend ostream& operator<<(ostream& os, Line x);
    friend istream& operator>>(istream& in, Line& x);
};

#endif