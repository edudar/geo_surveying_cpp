#include <numeric>
#include <cmath>
#include "three_wire_levelling.hpp"

static bool are_double_equal(double a, double b) {
    return fabs(a - b) < 1E-6;
}

ThreeWireLevellingSolution ThreeWireLevelling::solve(double benchmark,
                                                     const std::vector<std::unique_ptr<SightPoint>> &sight_points) {
    ThreeWireLevellingSolution twls = ThreeWireLevellingSolution();

    twls.backsight_heights.reserve(sight_points.size());
    twls.foresight_heights.reserve(sight_points.size());
    twls.adjusted_backsight_distance.reserve(sight_points.size());
    twls.adjusted_foresight_distance.reserve(sight_points.size());

    for (auto &sight_point : sight_points) {
        twls.backsight_heights.push_back(sight_point->get_backsight().get_middle());
        twls.foresight_heights.push_back(sight_point->get_foresight().get_middle());
        twls.adjusted_backsight_distance.push_back(
                (sight_point->get_backsight().get_upper()
                 - sight_point->get_backsight().get_lower()) * sight_point->get_backsight_distance());
        twls.adjusted_foresight_distance.push_back(
                (sight_point->get_foresight().get_upper()
                 - sight_point->get_foresight().get_lower()) * sight_point->get_foresight_distance());
    }

    twls.sum_backsight_height = std::accumulate(
            twls.backsight_heights.begin(), twls.backsight_heights.end(), 0.0);
    twls.sum_foresight_height = std::accumulate(
            twls.foresight_heights.begin(), twls.foresight_heights.end(), 0.0);

    twls.sum_backsight_distance = std::accumulate(twls.adjusted_backsight_distance.begin(),
                                                  twls.adjusted_backsight_distance.end(), 0.0);
    twls.sum_foresight_distance = std::accumulate(twls.adjusted_foresight_distance.begin(),
                                                  twls.adjusted_foresight_distance.end(), 0.0);

    twls.misclosure = twls.sum_backsight_height - twls.sum_foresight_height;
    twls.correction_factor =
            twls.misclosure / (twls.sum_backsight_distance + twls.sum_foresight_distance);

    twls.backsight_corrections.reserve(sight_points.size());
    for (auto &absd : twls.adjusted_backsight_distance) {
        twls.backsight_corrections.push_back(absd * twls.correction_factor);
    }

    twls.foresight_corrections.reserve(sight_points.size());
    for (auto &afsd : twls.adjusted_foresight_distance) {
        twls.foresight_corrections.push_back(afsd * twls.correction_factor);
    }

    twls.adjusted_backsight_heights.reserve(sight_points.size());
    for (unsigned long i = 0; i < twls.backsight_heights.size(); i++) {
        twls.adjusted_backsight_heights.push_back(
                twls.backsight_heights[i] - twls.backsight_corrections[i]);
    }

    twls.adjusted_foresight_heights.reserve(sight_points.size());
    for (unsigned long i = 0; i < twls.backsight_heights.size(); i++) {
        twls.adjusted_foresight_heights.push_back(
                twls.foresight_heights[i] + twls.foresight_corrections[i]);
    }

    double sum_adjusted_backsight_heights = std::accumulate(twls.adjusted_backsight_heights.begin(),
                                                            twls.adjusted_backsight_heights.end(),
                                                            0.0);
    double sum_adjusted_foresight_heights = std::accumulate(twls.adjusted_foresight_heights.begin(),
                                                            twls.adjusted_foresight_heights.end(),
                                                            0.0);
    twls.check = are_double_equal(sum_adjusted_backsight_heights - sum_adjusted_foresight_heights, 0.0);

    twls.heights.reserve(sight_points.size());
    twls.heights.emplace_back(benchmark);
    twls.output_heights.emplace_back(benchmark);
    for (unsigned long i = 2; i < sight_points.size() + 1; i++) {
        double h = benchmark +
                   std::accumulate(twls.adjusted_backsight_heights.begin(),
                                   twls.adjusted_backsight_heights.begin() + i - 1,
                                   0.0) -
                   std::accumulate(twls.adjusted_foresight_heights.begin() + 1,
                                   twls.adjusted_foresight_heights.begin() + i,
                                   0.0);
        twls.heights.push_back(h);
        if (sight_points[i - 1]->is_output()) {
            twls.output_heights.push_back(h);
        }
    }

    return twls;
}
