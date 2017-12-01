#ifndef GEO_SURVEYING_SIGHT_HEIGHT_H
#define GEO_SURVEYING_SIGHT_HEIGHT_H

#include <string>

struct SightHeight {

    double upper;
    double middle;
    double lower;

    explicit SightHeight(double upper = 0.0, double middle = 0.0, double lower = 0.0) : upper(upper),
                                                                                        middle(middle),
                                                                                        lower(lower) {}

    std::string to_string();

};


#endif //GEO_SURVEYING_SIGHT_HEIGHT_H
