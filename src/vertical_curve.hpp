#ifndef vertical_curve_hpp
#define vertical_curve_hpp

#include "station.hpp"
#include "vertical_curve_solution.hpp"

class VerticalCurve {
    
public:
    VerticalCurveSolution solve(Station bvc_station, double bvc_elevation, double length,
                                double initial_grade, double final_grade, int station_distance);
    VerticalCurveSolution solve(Station vpi_station, double vpi_elevation,
                                Station fixed_station, double fixed_elevation, 
                                double initial_grade, double final_grade, int station_distance);

};

#endif /* vertical_curve_hpp */
