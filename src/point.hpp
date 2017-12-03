#ifndef GEO_SURVEYING_POINT_H
#define GEO_SURVEYING_POINT_H


#include <string>

static const double EPSILON = 1E-6;

class Point {

private:
    double x;
    double y;

public:
    explicit Point(double x = 0, double y = 0);

    double get_x() const;
    double get_y() const;
    
    bool operator==(const Point &other) const;

    std::string to_string();

};


#endif //GEO_SURVEYING_POINT_H
