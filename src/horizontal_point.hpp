#ifndef GEO_SURVEYING_HORIZONTALPOINT_H
#define GEO_SURVEYING_HORIZONTALPOINT_H


#include <string>
#include "angle.hpp"

class HorizontalPoint {

private:
    Angle left_angle;
    Angle right_angle;
    double right_distance;

public:
    HorizontalPoint();
    HorizontalPoint(HorizontalPoint* cp);
    HorizontalPoint(Angle left_angle, Angle right_angle, double right_distance);

    Angle get_left_angle() const;
    
    Angle get_right_angle() const;
    
    double get_right_distance() const;
    
    std::string to_string() const;

};


#endif //GEO_SURVEYING_HORIZONTALPOINT_H
