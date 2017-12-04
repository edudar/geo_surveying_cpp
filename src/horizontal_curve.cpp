#include <numeric>
#include <cmath>

#include "horizontal_curve.hpp"

static bool are_double_equal(double a, double b) {
    return fabs(a - b) < 1E-6;
}

HorizontalCurveSolution HorizontalCurve::solve(Angle _intersection_angle,
                                               double _curve_radius,
                                               double _length_of_curve,
                                               Station _pi, Station _pc, int station_distance) {
    HorizontalCurveSolution hcs = HorizontalCurveSolution();
        
    if (are_double_equal(_intersection_angle.to_decimal(), 0.0)) {
        hcs.intersection_angle = Angle::from_decimal((180 / M_PI) * (_length_of_curve / _curve_radius));
        hcs.curve_radius = _curve_radius;
        hcs.length_of_curve = _length_of_curve;
    } else if (are_double_equal(_curve_radius, 0.0)) {
        hcs.intersection_angle = _intersection_angle;
        hcs.curve_radius = (180 / M_PI) * (_length_of_curve / _intersection_angle.to_decimal());
        hcs.length_of_curve = _length_of_curve;
    } else if (are_double_equal(_length_of_curve, 0.0)) {
        hcs.intersection_angle = _intersection_angle;
        hcs.curve_radius = _curve_radius;
        hcs.length_of_curve = (M_PI / 180) * _curve_radius * _intersection_angle.to_decimal();
    }
    
    hcs.tangent_distance = hcs.curve_radius * tan((M_PI / 180) * hcs.intersection_angle.to_decimal() / 2);
    hcs.external = hcs.tangent_distance * tan((M_PI / 180) * hcs.intersection_angle.to_decimal() / 4);
    hcs.middle_ordinate = hcs.external * cos((M_PI / 180) * hcs.intersection_angle.to_decimal() / 2);
    hcs.long_chord = 2 * hcs.curve_radius * sin((M_PI / 180) * hcs.intersection_angle.to_decimal() / 2);
    
    if (are_double_equal(_pi.to_decimal(), 0.0)) {
        hcs.pc = _pc;
        hcs.pi = hcs.pc + hcs.tangent_distance;
    } else if (are_double_equal(_pc.to_decimal(), 0.0)) {
        hcs.pi = _pi;
        hcs.pc = hcs.pi - hcs.tangent_distance;
    }
    hcs.pt = hcs.pc + hcs.length_of_curve;

    Station start_station;
    for (int i = static_cast<int>(hcs.pc.to_decimal()) ;; i++) {
        if (i % station_distance == 0) {
            start_station = Station::from_decimal(i);
            break;
        }
    }
    
    hcs.deflection_per_foot = Angle::from_decimal(hcs.intersection_angle.to_decimal() / (2 * hcs.length_of_curve));

    hcs.curve_data.emplace_back(hcs.pc, 0.0, Angle(), Angle());
    for (int i = start_station.to_decimal(), j = 0; i < hcs.pt.to_decimal(); i += station_distance, j++) {
        HorizontalCurveData hcd = HorizontalCurveData::create(hcs.curve_radius, hcs.pc, hcs.deflection_per_foot,
                                                              Station::from_decimal(i), hcs.curve_data[j]);
        hcs.curve_data.push_back(hcd);
    }

    HorizontalCurveData hcd_pt = HorizontalCurveData::create(hcs.curve_radius, hcs.pc, hcs.deflection_per_foot,
                                                             hcs.pt, hcs.curve_data[hcs.curve_data.size() - 1]);
    hcs.curve_data.push_back(hcd_pt);

    return hcs;
}
