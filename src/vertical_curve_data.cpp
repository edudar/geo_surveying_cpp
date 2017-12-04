#include "vertical_curve_data.hpp"

VerticalCurveData::VerticalCurveData(Station station, double x, double g1_x, double r_2_x_x, double elevation) : station(station), x(x), g1x(g1_x), r2xx(r_2_x_x), elevation(elevation) {}

Station VerticalCurveData::get_station() const {
    return station;
}

double VerticalCurveData::get_x() const {
    return x;
}

double VerticalCurveData::get_g1x() const {
    return g1x;
}

double VerticalCurveData::get_r2xx() const {
    return r2xx;
}

double VerticalCurveData::get_elevation() const {
    return elevation;
}

VerticalCurveData VerticalCurveData::create(Station bvc_station, double bvc_elevation, double initial_grade,
                                            double r, Station st_i) {
    double x = (st_i - bvc_station).to_decimal() / 100;
    double g1x = initial_grade * x;
    double r2xx = (r / 2) * x * x;
    return VerticalCurveData(st_i, x, g1x, r2xx, bvc_elevation + g1x + r2xx);
}
