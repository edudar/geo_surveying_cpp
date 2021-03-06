#ifndef curve_data_hpp
#define curve_data_hpp

#include "angle.hpp"
#include "station.hpp"

class HorizontalCurveData {
    
private:
    Station station;
    double chord;
    Angle deflection_increment;
    Angle deflection_angle;
    
public:
    HorizontalCurveData(Station station, double chord, Angle deflection_increment, Angle deflection_angle);
    
    Station get_station() const;
    double get_chord() const;
    Angle get_deflection_increment() const;
    Angle get_deflection_angle() const;
    
    static HorizontalCurveData create(double curve_radius, Station pc,
                                      Angle deflection_per_foot, Station st_i, HorizontalCurveData cd_i_1);
    
};

#endif /* curve_data_hpp */
