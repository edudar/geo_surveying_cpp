#include "horizontal_curve_solution.hpp"
#include "printer.hpp"

std::string HorizontalCurveSolution::to_string() {
    StringPrinter p;

    p.print("Intersection Angle: ");
    p.println(intersection_angle.to_string());
    p.print("Curve Radius: ");
    p.println(curve_radius);
    p.print("Total Length of Curve: ");
    p.println(length_of_curve);

    p.println();
    p.print("Tangent Distance: ");
    p.println(tangent_distance);
    p.print("External: ");
    p.println(external);
    p.print("Middle Ordinate: ");
    p.println(middle_ordinate);
    p.print("Circular Curve Long Chord: ");
    p.println(long_chord);
    p.print("Average Deflection Per Foot: ");
    p.println(deflection_per_foot.to_string());

    p.println();
    p.print("Station PI: ");
    p.println(pi.to_string());
    p.print("Station PC: ");
    p.println(pc.to_string());
    p.print("Station PT: ");
    p.println(pt.to_string());

    p.println();
    p.println("Curve Data: ");
    for (auto &cd : curve_data) {
        p.print("Station: ");
        p.println(cd.get_station().to_string());
        p.print("Chord: ");
        p.println(cd.get_chord());
        p.print("Deflection Increment: ");
        p.println(cd.get_deflection_increment().to_string());
        p.print("Deflection Angle: ");
        p.println(cd.get_deflection_angle().to_string());
        p.println();
    }

    return p.str();
}
