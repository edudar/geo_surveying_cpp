#include "horizontal_point.hpp"

HorizontalPoint::HorizontalPoint() {}

HorizontalPoint::HorizontalPoint(HorizontalPoint* cp) {
    left_angle = cp->left_angle;
    right_angle = cp->right_angle;
    right_distance = cp->right_distance;
}

HorizontalPoint::HorizontalPoint(Angle left_angle, Angle right_angle, double right_distance) : left_angle(left_angle), right_angle(right_angle), right_distance(right_distance) {}

Angle HorizontalPoint::get_left_angle() const {
    return left_angle;
}

Angle HorizontalPoint::get_right_angle() const {
    return right_angle;
}

double HorizontalPoint::get_right_distance() const {
    return right_distance;
}

std::string HorizontalPoint::to_string() const {
    return "(left=" + get_left_angle().to_string() + ", right=" + get_right_angle().to_string() + ", distance=" + std::to_string(right_distance) + ")";
}


