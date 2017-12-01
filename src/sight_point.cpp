#include "sight_point.hpp"

std::string SightPoint::to_string() {
    return "(bs=" + backsight.to_string() + ", bs_d=" + std::to_string(backsight_distance) + ", "
            "fs=" + foresight.to_string() + ", fs_d=" + std::to_string(foresight_distance) + ")";
}
