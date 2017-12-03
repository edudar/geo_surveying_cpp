#include "sight_point.hpp"

SightPoint::SightPoint() {}

SightPoint::SightPoint(SightPoint* cp) {
    backsight = cp->backsight;
    backsight_distance = cp->backsight_distance;
    foresight = cp->foresight;
    foresight_distance = cp->foresight_distance;
    output = cp->output;
}

SightPoint::SightPoint(SightHeight backsight, double backsight_distance, SightHeight foresight,
           double foresight_distance, bool output) : backsight(backsight), backsight_distance(backsight_distance), foresight(foresight), foresight_distance(foresight_distance), output(output) {}

SightHeight SightPoint::get_backsight() const {
    return backsight;
}

double SightPoint::get_backsight_distance() const {
    return backsight_distance;
}

SightHeight SightPoint::get_foresight() const {
    return foresight;
}

double SightPoint::get_foresight_distance() const {
    return foresight_distance;
}

bool SightPoint::is_output() const {
    return output;
}

std::string SightPoint::to_string() const {
    return "(bs=" + backsight.to_string() + ", bs_d=" + std::to_string(backsight_distance) + ", "
            "fs=" + foresight.to_string() + ", fs_d=" + std::to_string(foresight_distance) + ")";
}
