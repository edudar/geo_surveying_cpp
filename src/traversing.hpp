#ifndef GEO_SURVEYING_TRAVERSING_H
#define GEO_SURVEYING_TRAVERSING_H


#include <vector>
#include "traversing_solution.hpp"
#include "point.hpp"
#include "angle.hpp"
#include "horizontal_point.hpp"

class Traverser {

public:
    TraversingSolution solve(Point a, Angle a_azimuth, const std::vector<std::unique_ptr<HorizontalPoint>> &horizontal_points);
};


#endif //GEO_SURVEYING_TRAVERSING_H
