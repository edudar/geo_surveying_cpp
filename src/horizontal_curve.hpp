#ifndef horizontal_curve_hpp
#define horizontal_curve_hpp

#include "angle.hpp"
#include "horizontal_curve_solution.hpp"
#include "station.hpp"

class HorizontalCurve {
    
public:
    HorizontalCurveSolution solve(Angle _intersection_angle,
                                  double _curve_radius,
                                  double _length_of_curve,
                                  Station pi, Station pc, int station_distance);
    
};

#endif /* horizontal_curve_hpp */
