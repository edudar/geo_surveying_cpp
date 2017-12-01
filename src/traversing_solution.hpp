#ifndef GEO_SURVEYING_TRAVERSING_SOLUTION_H
#define GEO_SURVEYING_TRAVERSING_SOLUTION_H


#include <vector>
#include "angle.hpp"
#include "point.hpp"

struct TraversingSolution {

    std::vector<Angle> internal_angles;
    Angle geometrical_sum;
    Angle measured_sum;
    Angle misclosure;
    Angle distributed_misclosure;
    std::vector<Angle> corrected_internal_angles;
    std::vector<Angle> azimuths;
    std::vector<double> delta_x;
    std::vector<double> delta_y;
    double sum_delta_x;
    double sum_delta_y;
    double linear_misclosure_w;
    double total_length;
    double relative_precision;
    double corrected_x;
    double corrected_y;
    bool check;
    std::vector<Point> points;

    std::string to_string();
};


#endif //GEO_SURVEYING_TRAVERSING_SOLUTION_H
