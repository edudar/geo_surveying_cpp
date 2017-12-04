#ifndef horizontal_curve_solution_hpp
#define horizontal_curve_solution_hpp

#include <vector>

#include "angle.hpp"
#include "curve_data.hpp"
#include "station.hpp"

struct HorizontalCurveSolution {
    
    Angle intersection_angle;  // ∆
    double curve_radius;       // R
    double length_of_curve;    // L
    double tangent_distance;   // T = R * tan(∆/2)
    double external;           // E = T * tan(∆/4)
    double middle_ordinate;    // M = E * cos(∆/2)
    double long_chord;         // LC = 2R * sin(∆/2)
    Station pi;
    Station pc;                // PC = PI - T
    Station pt;                // PT = PC + L
    Angle deflection_per_foot; // DC/FT = (∆/2) / L
    std::vector<CurveData> curve_data;
    
    std::string to_string();
};

#endif /* horizontal_curve_solution_hpp */
