#include <sstream>
#include <iomanip>

#include "angle.hpp"

Angle::Angle(int degree, int minutes, double seconds) : degree(degree), minutes(minutes), seconds(seconds) {}

std::string Angle::to_string() {
    std::stringstream seconds_s;
    seconds_s << std::fixed << std::setprecision(4) << seconds;
    return std::to_string(degree) + "˚" + std::to_string(minutes) + "'" + seconds_s.str() + "\"";
}

int Angle::get_degree() const {
    return degree;
}

int Angle::get_minutes() const {
    return minutes;
}

double Angle::get_seconds() const {
    return seconds;
}

Angle Angle::operator+(const Angle &other) const {
    return Angle::from_seconds(to_seconds() + other.to_seconds());
}

Angle Angle::operator-(const Angle &other) const {
    return Angle::from_seconds(to_seconds() - other.to_seconds());
}

Angle Angle::operator*(double scalar) const {
    return Angle::from_seconds(to_seconds() * scalar);
}

Angle Angle::operator/(double scalar) const {
    return Angle::from_seconds(to_seconds() / scalar);
}

bool Angle::operator<(const Angle &other) const {
    return to_seconds() < other.to_seconds();
}

double Angle::to_seconds() const {
    return 3600 * degree + 60 * minutes + seconds;
}

Angle Angle::from_seconds(double seconds) {
    auto d = static_cast<int>(seconds / 3600);
    auto m = static_cast<int>((seconds - d * 3600) / 60);
    double s = seconds - d * 3600 - m * 60;
    return Angle(d, m, s);
}

double Angle::to_decimal() const {
    return degree + static_cast<double>(minutes) / 60 + static_cast<double>(seconds) / 3600;
}

Angle Angle::from_decimal(double decimal) {
    int d = static_cast<int>(decimal);
    int m = static_cast<int>((decimal - d) * 60);
    double s = (decimal - d - static_cast<double>(m) / 60) * 3600;
    return Angle(d, m, s);
}
