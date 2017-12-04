#ifndef station_hpp
#define station_hpp

#include <string>

class Station {
    
private:
    int st;
    double ft;
    
public:
    explicit Station(int st = 0, double ft = 0.0);

    int get_st() const;
    double get_ft() const;
    
    Station operator+(const Station &other) const;
    Station operator-(const Station &other) const;
    Station operator+(const double &decimal) const;
    Station operator-(const double &decimal) const;

    double to_decimal() const;
    static Station from_decimal(double decimal);

    std::string to_string();
    
};

#endif /* station_hpp */
