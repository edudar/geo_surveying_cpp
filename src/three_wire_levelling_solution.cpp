#include "three_wire_levelling_solution.hpp"
#include "printer.hpp"

std::string ThreeWireLevellingSolution::to_string() {
    StringPrinter p;

    p.println("Backsight Heights:");
    for (auto &height : backsight_heights) {
        p.println(height);
    }

    p.println();
    p.println("Foresight Heights:");
    for (auto &height : foresight_heights) {
        p.println(height);
    }

    p.println();
    p.println("Adjusted Backsight Distances:");
    for (auto &distance : adjusted_backsight_distance) {
        p.println(distance);
    }

    p.println();
    p.println("Adjusted Foresight Distances:");
    for (auto &distance : adjusted_foresight_distance) {
        p.println(distance);
    }

    p.println();
    p.println("∑ of Backsight Heights:");
    p.println(sum_backsight_height);

    p.println();
    p.println("∑ of Foresight Heights:");
    p.println(sum_foresight_height);

    p.println();
    p.println("Misclosure:");
    p.println(misclosure);

    p.println();
    p.println("∑ of Backsight Distances:");
    p.println(sum_backsight_distance);

    p.println();
    p.println("∑ of Foresight Distances:");
    p.println(sum_foresight_distance);

    p.println();
    p.println("Correction Factor:");
    p.println(correction_factor);

    p.println();
    p.println("Backsight Corrections:");
    for (auto &correction : backsight_corrections) {
        p.println(correction);
    }

    p.println();
    p.println("Foresight Corrections:");
    for (auto &correction : foresight_corrections) {
        p.println(correction);
    }

    p.println();
    p.println("Adjusted Backsight Heights:");
    for (auto &height : adjusted_backsight_heights) {
        p.println(height);
    }

    p.println();
    p.println("Adjusted Foresight Heights:");
    for (auto &height : adjusted_foresight_heights) {
        p.println(height);
    }

    p.println();
    p.println("Check:");
    p.println(check);

    p.println();
    p.println("All Heights:");
    for (auto &height : heights) {
        p.println(height);
    }

    p.println();
    p.println("Required Heights:");
    for (auto &height : output_heights) {
        p.println(height);
    }

    return p.str();
}
