#ifndef vertical_curve_solution_hpp
#define vertical_curve_solution_hpp

#include <string>
#include <vector>

#include "station.hpp"
#include "vertical_curve_data.hpp"

struct VerticalCurveSolution {
    
    Station bvc_station;
    double bvc_elevation;
    double length;
    Station vpi_station;
    double vpi_elevation;
    std::vector<VerticalCurveData> curve_data;
    
    std::string to_string();
    
};

#endif /* vertical_curve_solution_hpp */
