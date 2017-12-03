#ifndef GEO_SURVEYING_THREE_WIRE_LEVELLING_H
#define GEO_SURVEYING_THREE_WIRE_LEVELLING_H


#include <vector>
#include "three_wire_levelling_solution.hpp"
#include "sight_point.hpp"

class ThreeWireLevelling {

public:
    ThreeWireLevellingSolution solve(double benchmark, const std::vector<std::unique_ptr<SightPoint>> &sight_points);
};


#endif //GEO_SURVEYING_THREE_WIRE_LEVELLING_H
