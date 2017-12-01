#include <iostream>
#include <vector>

#include "point.hpp"
#include "angle.hpp"
#include "horizontal_point.hpp"
#include "traversing.hpp"
#include "three_wire_levelling.hpp"

std::string traversing() {
    Point a = Point(1000, 1000);
    Angle a_azimuth = Angle(90);
    std::vector<std::unique_ptr<HorizontalPoint>> horizontal_points;
    horizontal_points.emplace_back(new HorizontalPoint(Angle(314, 45, 44.15), Angle(222, 42, 53.3), 83.103));
    horizontal_points.emplace_back(new HorizontalPoint(Angle(175, 20, 26.5), Angle(92, 32, 30), 190.120));
    horizontal_points.emplace_back(new HorizontalPoint(Angle(321, 7, 24), Angle(230, 18, 6), 53.115));
    horizontal_points.emplace_back(new HorizontalPoint(Angle(343, 29, 6.5), Angle(243, 45, 43.5), 181.748));
    
    Traverser traversing = Traverser();
    TraversingSolution solution = traversing.solve(a, a_azimuth, horizontal_points);
    return solution.to_string();
}

std::string three_wire_levelling() {
    double benchmark = 108.92;
    std::vector<SightPoint> sight_points;
    
    // BM909
    sight_points.emplace_back(SightHeight(6.53, 6.03, 5.54), 82.00, SightHeight(3.19, 3.02, 2.86), 24.00, true);
    sight_points.emplace_back(SightHeight(6.41, 6.04, 5.66), 50.00, SightHeight(3.87, 3.33, 2.79), 82.00);
    sight_points.emplace_back(SightHeight(5.93, 5.62, 5.31), 50.00, SightHeight(4.67, 4.31, 3.95), 50.00);
    sight_points.emplace_back(SightHeight(7.40, 7.03, 6.70), 50.00, SightHeight(4.78, 4.45, 4.13), 50.00);
    sight_points.emplace_back(SightHeight(5.79, 5.38, 4.92), 50.00, SightHeight(4.66, 4.31, 3.95), 50.00);
    
    // BM148
    sight_points.emplace_back(SightHeight(13.30, 12.62, 11.93), 80.00, SightHeight(5.16, 4.72, 4.26), 50.00, true);
    sight_points.emplace_back(SightHeight(07.70, 07.44, 07.21), 32.00, SightHeight(1.13, 0.59, 0.04), 80.00);
    
    // BM508
    sight_points.emplace_back(SightHeight(8.11, 7.37, 6.64), 100.00, SightHeight(3.33, 3.06, 2.79), 032.00, true);
    sight_points.emplace_back(SightHeight(6.50, 6.25, 6.00), 036.00, SightHeight(1.57, 0.93, 0.30), 100.00);
    
    // BM143
    sight_points.emplace_back(SightHeight(5.30, 4.55, 3.76), 80.00, SightHeight(4.99, 4.74, 4.49), 36.00, true);
    sight_points.emplace_back(SightHeight(2.60, 2.02, 1.44), 80.00, SightHeight(5.98, 5.31, 4.63), 80.00);
    sight_points.emplace_back(SightHeight(4.66, 4.39, 4.14), 40.00, SightHeight(7.00, 6.46, 5.91), 80.00);
    
    // BM18
    sight_points.emplace_back(SightHeight(2.05, 1.38, 0.70), 100.00, SightHeight(06.28, 06.00, 05.72), 040.00, true);
    sight_points.emplace_back(SightHeight(1.95, 1.59, 1.24), 057.00, SightHeight(13.98, 13.31, 12.67), 100.00);
    sight_points.emplace_back(SightHeight(6.20, 5.86, 5.16), 072.00, SightHeight(10.50, 10.09, 09.68), 066.00);
    sight_points.emplace_back(SightHeight(6.02, 5.63, 5.24), 046.00, SightHeight(06.07, 05.63, 05.20), 072.00);
    
    // BM36
    sight_points.emplace_back(SightHeight(5.15, 4.80, 4.45), 046.00, SightHeight(6.39, 6.05, 5.72), 046.00, true);
    sight_points.emplace_back(SightHeight(1.47, 0.75, 0.00), 100.00, SightHeight(5.50, 5.18, 4.80), 046.00);
    sight_points.emplace_back(SightHeight(5.70, 5.51, 5.25), 040.00, SightHeight(7.58, 6.76, 6.03), 100.00);
    sight_points.emplace_back(SightHeight(6.95, 6.80, 6.66), 024.00, SightHeight(7.63, 7.38, 7.08), 040.00);
    
    ThreeWireLevelling threeWireLevelling = ThreeWireLevelling();
    ThreeWireLevellingSolution solution = threeWireLevelling.solve(benchmark, sight_points);
    return solution.to_string();
}

int main() {
    traversing();
    three_wire_levelling();
    return 0;
}
