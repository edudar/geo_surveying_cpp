#include <sstream>
#include <iomanip>

#include "station.hpp"

Station::Station(int st, double ft) : st(st), ft(ft) {}

int Station::get_st() const {
    return st;
}

double Station::get_ft() const {
    return ft;
}

Station Station::operator+(const Station &other) const {
    return Station::from_decimal(to_decimal() + other.to_decimal());
}

Station Station::operator-(const Station &other) const {
    return Station::from_decimal(to_decimal() - other.to_decimal());
}

Station Station::operator+(const double &decimal) const {
    return Station::from_decimal(to_decimal() + decimal);
}

Station Station::operator-(const double &decimal) const {
    return Station::from_decimal(to_decimal() - decimal);
}

double Station::to_decimal() const {
    return st * 100 + ft;
}

Station Station::from_decimal(double decimal) {
    int st = static_cast<int>(decimal / 100);
    double ft = decimal - st * 100;
    return Station(st, ft);
}

std::string Station::to_string() {
    std::stringstream ft_s;
    ft_s << std::fixed << std::setprecision(2) << ft;
    return std::to_string(st) + "+" + ft_s.str();
}
