#include <cmath>
#include "point.hpp"

Point::Point(double x, double y) : x(x), y(y) {
}

double Point::get_x() {
    return x;
}

double Point::get_y() {
    return y;
}

std::string Point::to_string() {
    return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
}

static bool are_double_equal(double a, double b) {
    return fabs(a - b) < EPSILON;
}

bool Point::operator==(const Point &other) const {
    return are_double_equal(x, other.x) && are_double_equal(y, other.y);
}
