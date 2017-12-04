#include <cmath>

#include "vertical_curve.hpp"

VerticalCurveSolution VerticalCurve::solve(Station bvc_station, double bvc_elevation, double length,
                                           double initial_grade, double final_grade, int station_distance) {
    VerticalCurveSolution vcs = VerticalCurveSolution();
    
    vcs.bvc_station = bvc_station;
    vcs.bvc_elevation = bvc_elevation;
    vcs.length = length;
    vcs.vpi_station = bvc_station + length / 2;
    vcs.vpi_elevation = bvc_elevation + initial_grade * (length / 200);
    
    Station start_station;
    for (int i = static_cast<int>(bvc_station.to_decimal()) ;; i++) {
        if (i % station_distance == 0) {
            start_station = Station::from_decimal(i);
            break;
        }
    }

    double r = (final_grade - initial_grade) / length * 100;
    Station evcStation = bvc_station + length;

    vcs.curve_data.emplace_back(bvc_station, 0.0, 0.0, 0.0, bvc_elevation);
    for (int i = start_station.to_decimal(); i < evcStation.to_decimal(); i += station_distance) {
        Station st_i = Station::from_decimal(i);
        VerticalCurveData vcd = VerticalCurveData::create(bvc_station, bvc_elevation, initial_grade, r, st_i);
        vcs.curve_data.push_back(vcd);
    }
    
    VerticalCurveData vcd_evc = VerticalCurveData::create(bvc_station, bvc_elevation, initial_grade, r, evcStation);
    vcs.curve_data.push_back(vcd_evc);

    return vcs;
}

double quadratic_equation(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;
    return (-b + sqrt(discriminant)) / (2 * a);
}

VerticalCurveSolution VerticalCurve::solve(Station vpi_station, double vpi_elevation,
                                           Station fixed_station, double fixed_elevation,
                                           double initial_grade, double final_grade, int station_distance) {
    double s = (vpi_station - fixed_station).to_decimal() / 100;

    double g = final_grade - initial_grade;
    double a = - g / 4;
    double b = 2 * fixed_elevation - 2 * vpi_elevation + 2 * initial_grade * s + g * s;
    double c = - g * s * s;
    
    double l = quadratic_equation(a, b, c);
    
    Station bvc_station = vpi_station - (l * 100 / 2);
    double bvc_elevation = vpi_elevation - initial_grade * (l / 2);

    return solve(bvc_station, bvc_elevation, l * 100, initial_grade, final_grade, station_distance);
}
