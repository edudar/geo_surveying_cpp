#include <numeric>
#include <cmath>

#include "horizontal_curve_data.hpp"

HorizontalCurveData::HorizontalCurveData(Station station, double chord, Angle deflection_increment, Angle deflection_angle) : station(station), chord(chord), deflection_increment(deflection_increment), deflection_angle(deflection_angle) {}

Station HorizontalCurveData::get_station() const {
    return station;
}

double HorizontalCurveData::get_chord() const {
    return chord;
}

Angle HorizontalCurveData::get_deflection_increment() const {
    return deflection_increment;
}

Angle HorizontalCurveData::get_deflection_angle() const {
    return deflection_angle;
}

HorizontalCurveData HorizontalCurveData::create(double curve_radius, Station pc,
                                                Angle deflection_per_foot, Station st_i, HorizontalCurveData cd_i_1) {
    double lc = (st_i - pc).to_decimal();
    Angle deflection_angle = deflection_per_foot * lc;
    Angle deflection_icrement = deflection_angle - cd_i_1.get_deflection_angle();
    double chord = 2 * curve_radius * sin((deflection_angle * (M_PI / 180)).to_decimal());
    return HorizontalCurveData(st_i, chord, deflection_icrement, deflection_angle);
}
