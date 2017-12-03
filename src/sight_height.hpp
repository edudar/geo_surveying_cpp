#ifndef GEO_SURVEYING_SIGHT_HEIGHT_H
#define GEO_SURVEYING_SIGHT_HEIGHT_H

#include <string>

class SightHeight {

private:
    double upper;
    double middle;
    double lower;

public:
    explicit SightHeight(double upper = 0.0, double middle = 0.0, double lower = 0.0);
    
    double get_upper() const;
    double get_middle() const;
    double get_lower() const;
    
    std::string to_string() const;

};


#endif //GEO_SURVEYING_SIGHT_HEIGHT_H
