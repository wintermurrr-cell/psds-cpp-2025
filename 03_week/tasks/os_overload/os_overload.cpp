#include <stdexcept>
#include <utility>
#include <vector>

struct Coord2D {

    Coord2D(int x_val = 0, int y_val = 0) {
        x = x_val;
        y = y_val;
    }

    int x;
    int y;
};

struct Circle {

    Circle(int x = 0, int y = 0) {
        coord.x = x;
        coord.y = y;
    }

    Circle(Coord2D obj, unsigned r) {
        coord = obj;
        radius = r;
    }

    Coord2D coord;
    unsigned radius = 1;
};

using CircleRegion = std::pair<Circle, bool>;
using CircleRegionList = std::vector<CircleRegion>;

using RetType = std::ostream;

RetType& operator<<(RetType& os, const Coord2D& obj) {
    os << "(" << obj.x << ", " << obj.y << ")";
    return os;
}

RetType& operator<<(RetType& os, const Circle& obj) {

    os << "circle[";

    if (obj.radius != 0)
        os << obj.coord << ", r = " << obj.radius;

    os << "]";
    return os;
}

RetType& operator<<(RetType& os, const CircleRegion& obj) {

    const char symb = obj.second ? '+' : '-';
    os << symb << obj.first;
    return os;
}

RetType& operator<<(RetType& os, const CircleRegionList& objs) {

    os << '{';
    if (!objs.empty())
        os << '\n';

    for (auto itr = objs.begin(); itr != objs.end(); itr++) {
        os << '\t' << *itr;

        // Подглядываем в следующий элемент
        if (itr + 1 != objs.end())
            os << ',';
        os << '\n';
    }

    os << '}';
    return os;
}