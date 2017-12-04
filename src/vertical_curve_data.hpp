#ifndef vertical_curve_data_hpp
#define vertical_curve_data_hpp

#include "station.hpp"

class VerticalCurveData {
    
private:
    Station station;
    double x;
    double g1x;
    double r2xx;
    double elevation;
    
public:
    VerticalCurveData(Station station, double x, double g1_x, double r_2_x_x, double elevation);
    
    Station get_station() const;
    double get_x() const;
    double get_g1x() const;
    double get_r2xx() const;
    double get_elevation() const;

    static VerticalCurveData create(Station bvc_station, double bvc_elevation, double initial_grade,
                                    double r, Station st_i);
};

#endif /* vertical_curve_data_hpp */
