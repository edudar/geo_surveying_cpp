#ifndef GEO_SURVEYING_ANGLE_H
#define GEO_SURVEYING_ANGLE_H


#include <string>

class Angle {

private:
    int degree;
    int minutes;
    double seconds;

public:
    explicit Angle(int degree = 0, int minutes = 0, double seconds = 0);

    int get_degree() const;
    int get_minutes() const;
    double get_seconds() const;
    
    Angle operator+(const Angle &other) const;
    Angle operator-(const Angle &other) const;
    Angle operator*(double scalar) const;
    Angle operator/(double scalar) const;
    bool operator<(const Angle &other) const;

    double to_seconds() const;
    static Angle from_seconds(double seconds);

    double to_decimal() const;
    static Angle from_decimal(double decimal);

    std::string to_string();

};


#endif //GEO_SURVEYING_ANGLE_H
