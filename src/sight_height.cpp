#include "sight_height.hpp"

std::string SightHeight::to_string() {
    return "(u=" + std::to_string(upper) + ", m=" + std::to_string(middle) + ", l=" + std::to_string(lower) + ")";
}
