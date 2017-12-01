#include "traversing_solution.hpp"
#include "printer.hpp"

std::string TraversingSolution::to_string() {
    StringPrinter p;

    p.println("Internal Angles:");
    for (auto &internal_angle : internal_angles) {
        p.println(internal_angle.to_string());
    }

    p.println();
    p.println("Geometrical Sum:");
    p.println(geometrical_sum.to_string());

    p.println();
    p.println("Measured Sum:");
    p.println(measured_sum.to_string());

    p.println();
    p.println("Misclosure:");
    p.println(misclosure.to_string());

    p.println();
    p.println("Distributed Misclosure:");
    p.println(distributed_misclosure.to_string());

    p.println();
    p.println("Corrected Internal Angles:");
    for (auto &corrected_internal_angle : corrected_internal_angles) {
        p.println(corrected_internal_angle.to_string());
    }

    p.println();
    p.println("Azimuths:");
    for (auto &azimuth : azimuths) {
        p.println(azimuth.to_string());
    }

    p.println();
    p.println("∆X:");
    for (auto &x : delta_x) {
        p.println(x);
    }

    p.println();
    p.println("∆Y:");
    for (auto &y : delta_y) {
        p.println(y);
    }

    p.println();
    p.println("∑∆X:");
    p.println(sum_delta_x);

    p.println();
    p.println("∑∆Y:");
    p.println(sum_delta_y);

    p.println();
    p.println("W (Linear Misclosure):");
    p.println(linear_misclosure_w);

    p.println();
    p.println("Total Length:");
    p.println(total_length);

    p.println();
    p.println("Relative Precision:");
    p.println(relative_precision);

    p.println();
    p.println("Corrected X:");
    p.println(corrected_x);

    p.println();
    p.println("Corrected Y:");
    p.println(corrected_y);

    p.println();
    p.println("Check:");
    p.println(check);

    p.println();
    p.println("Points:");
    for (auto &point : points) {
        p.println(point.to_string());
    }

    return p.str();
}
