#ifndef GEO_SURVEYING_SIGHT_POINT_H
#define GEO_SURVEYING_SIGHT_POINT_H


#include "sight_height.hpp"

struct SightPoint {

    SightHeight backsight;
    double backsight_distance;
    SightHeight foresight;
    double foresight_distance;
    bool output;

    explicit SightPoint(SightHeight backsight, double backsight_distance, SightHeight foresight,
                        double foresight_distance, bool output = false) : backsight(backsight),
                                                                          backsight_distance(backsight_distance),
                                                                          foresight(foresight),
                                                                          foresight_distance(foresight_distance),
                                                                          output(output) {}

    std::string to_string();

};


#endif //GEO_SURVEYING_SIGHT_POINT_H
