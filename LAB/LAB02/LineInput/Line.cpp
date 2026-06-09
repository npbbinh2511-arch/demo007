#include "Line.h"

ostream& operator<<(ostream& os, Line x){
    os << x._start << " -> " << x._end;
    return os;
}

istream& operator>>(istream& in, Line& x){
    in >> x._start >> x._end;
    return in;
}