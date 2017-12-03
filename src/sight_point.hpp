#ifndef GEO_SURVEYING_SIGHT_POINT_H
#define GEO_SURVEYING_SIGHT_POINT_H


#include "sight_height.hpp"

class SightPoint {

private:
    SightHeight backsight;
    double backsight_distance;
    SightHeight foresight;
    double foresight_distance;
    bool output;

public:
    SightPoint();
    SightPoint(SightPoint* cp);
    explicit SightPoint(SightHeight backsight, double backsight_distance, SightHeight foresight,
                        double foresight_distance, bool output = false);
    
    SightHeight get_backsight() const;
    double get_backsight_distance() const;
    SightHeight get_foresight() const;
    double get_foresight_distance() const;
    bool is_output() const;

    std::string to_string() const;

};


#endif //GEO_SURVEYING_SIGHT_POINT_H
