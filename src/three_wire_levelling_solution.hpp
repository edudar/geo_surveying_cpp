#ifndef GEO_SURVEYING_THREE_WAY_LEVELLING_SOLUTION_H
#define GEO_SURVEYING_THREE_WAY_LEVELLING_SOLUTION_H


#include <vector>

struct ThreeWireLevellingSolution {

    std::vector<double> backsight_heights;
    std::vector<double> foresight_heights;
    std::vector<double> adjusted_backsight_distance;
    std::vector<double> adjusted_foresight_distance;
    double sum_backsight_height;
    double sum_foresight_height;
    double misclosure;
    double sum_backsight_distance;
    double sum_foresight_distance;
    double correction_factor;
    std::vector<double> backsight_corrections;
    std::vector<double> foresight_corrections;
    std::vector<double> adjusted_backsight_heights;
    std::vector<double> adjusted_foresight_heights;
    bool check;
    std::vector<double> heights;
    std::vector<double> output_heights;

    std::string to_string();

};


#endif //GEO_SURVEYING_THREE_WAY_LEVELLING_SOLUTION_H
