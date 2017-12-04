#include "printer.hpp"
#include "vertical_curve_solution.hpp"

std::string VerticalCurveSolution::to_string() {
    StringPrinter p = StringPrinter();
    
    p.print("BVC Station: ");
    p.println(bvc_station.to_string());
    p.print("BVC Elevation: ");
    p.println(bvc_elevation);

    p.println();
    p.print("Length: ");
    p.println(length);
    
    p.println();
    p.print("VPI Station: ");
    p.println(vpi_station.to_string());
    p.print("VPI Elevation: ");
    p.println(vpi_elevation);

    p.println();
    p.println("Curve Data: ");
    for (auto &cd : curve_data) {
        p.print("- Station: ");
        p.println(cd.get_station().to_string());
        p.print("  x: ");
        p.println(cd.get_x());
        p.print("  x*g1: ");
        p.println(cd.get_g1x());
        p.print("  x*x*r/2: ");
        p.println(cd.get_r2xx());
        p.print("  Elevation: ");
        p.println(cd.get_elevation());
        p.println();
    }

    return p.str();
}
