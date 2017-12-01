#include <numeric>
#include <cmath>
#include "traversing.hpp"

TraversingSolution Traverser::solve(Point a, Angle a_azimuth, const std::vector<std::unique_ptr<HorizontalPoint>> &horizontal_points) {

    TraversingSolution ts = TraversingSolution();

    ts.internal_angles.reserve(horizontal_points.size());
    for (auto &horizontal_point : horizontal_points) {
        ts.internal_angles.push_back(horizontal_point->get_left_angle() - horizontal_point->get_right_angle());
    }

    ts.geometrical_sum = Angle(180) * (horizontal_points.size() - 2);
    ts.measured_sum = std::accumulate(ts.internal_angles.begin(), ts.internal_angles.end(), Angle(0));
    ts.misclosure = ts.geometrical_sum - ts.measured_sum;
    ts.distributed_misclosure = ts.misclosure / horizontal_points.size();

    ts.corrected_internal_angles.reserve(horizontal_points.size());
    for (auto &horizontal_angle : ts.internal_angles) {
        ts.corrected_internal_angles.push_back(horizontal_angle + ts.distributed_misclosure);
    }

    ts.azimuths.reserve(horizontal_points.size());
    ts.azimuths.emplace_back(a_azimuth);
    for (unsigned long i = 1; i < horizontal_points.size(); i++) {
        Angle azimuth = ts.azimuths[i - 1] + ts.corrected_internal_angles[i] + Angle(180);
        ts.azimuths.push_back(azimuth < Angle(360) ? azimuth : azimuth - Angle(360));
    }

    ts.delta_x.reserve(horizontal_points.size());
    ts.delta_y.reserve(horizontal_points.size());
    for (unsigned long i = 0; i < horizontal_points.size(); i++) {
        ts.delta_x.push_back(horizontal_points[i]->get_right_distance() * sin(M_PI * ts.azimuths[i].to_decimal() / 180));
        ts.delta_y.push_back(horizontal_points[i]->get_right_distance() * cos(M_PI * ts.azimuths[i].to_decimal() / 180));
    }

    ts.sum_delta_x = std::accumulate(ts.delta_x.begin(), ts.delta_x.end(), 0.0);
    ts.sum_delta_y = std::accumulate(ts.delta_y.begin(), ts.delta_y.end(), 0.0);

    ts.linear_misclosure_w = sqrt(pow(ts.sum_delta_x, 2) + pow(ts.sum_delta_y, 2));
    ts.total_length = 0.0;
    for (auto &horizontal_point : horizontal_points) {
        ts.total_length += horizontal_point->get_right_distance();
    }
    ts.relative_precision = ts.linear_misclosure_w / ts.total_length;

    ts.corrected_x = ts.sum_delta_x / ts.total_length;
    ts.corrected_y = ts.sum_delta_y / ts.total_length;

    ts.points.reserve(horizontal_points.size());
    ts.points.push_back(a);
    for (unsigned long i = 0; i < horizontal_points.size() - 1; i++) {
        ts.points.emplace_back(
                ts.points[i].get_x() + ts.delta_x[i] - ts.corrected_x * horizontal_points[i]->get_right_distance(),
                ts.points[i].get_y() + ts.delta_y[i] - ts.corrected_y * horizontal_points[i]->get_right_distance()
        );
    }

    long i = horizontal_points.size() - 1;
    Point check = Point(
            ts.points[i].get_x() + ts.delta_x[i] - ts.corrected_x * horizontal_points[i]->get_right_distance(),
            ts.points[i].get_y() + ts.delta_y[i] - ts.corrected_y * horizontal_points[i]->get_right_distance());

    ts.check = check == a;

    return ts;

}
