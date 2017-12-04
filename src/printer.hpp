#ifndef GEO_SURVEYING_PRINT_UTILS_H
#define GEO_SURVEYING_PRINT_UTILS_H


#include <sstream>
#include <iomanip>

class StringPrinter {

private:
    std::stringstream out;

public:

    StringPrinter();

    void println();

    void println(double d);
    void print(double d);
    
    void println(bool b);
    void print(bool d);

    template<typename T>
    void print(T t) {
        out << t;
    }

    template<typename T>
    void println(T t) {
        out << t << std::endl;
    }

    std::string str();
};

#endif //GEO_SURVEYING_PRINT_UTILS_H
