#include "sight_height.hpp"

SightHeight::SightHeight(double upper, double middle, double lower) : upper(upper), middle(middle), lower(lower) {}

double SightHeight::get_upper() const {
    return upper;
}

double SightHeight::get_middle() const {
    return middle;
}

double SightHeight::get_lower() const {
    return lower;
}

std::string SightHeight::to_string() const {
    return "(u=" + std::to_string(upper) + ", m=" + std::to_string(middle) + ", l=" + std::to_string(lower) + ")";
}
