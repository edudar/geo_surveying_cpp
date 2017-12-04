#include "printer.hpp"

StringPrinter::StringPrinter() {
    out = std::stringstream();
}

void StringPrinter::println() {
    out << std::endl;
}

void StringPrinter::println(double d) {
    out << std::fixed << std::setprecision(4) << d << std::endl;
}

void StringPrinter::print(double d) {
    out << std::fixed << std::setprecision(4) << d;
}

void StringPrinter::println(bool b) {
    out << (b ? "OK" : "ERROR") << std::endl;
}

void StringPrinter::print(bool b) {
    out << (b ? "OK" : "ERROR");
}

std::string StringPrinter::str() {
    return out.str();
}
