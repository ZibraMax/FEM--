#include <iostream>
#include "FEM.h"
#include "Utils.h"
#include "FEM/Geometry/Geometry.h"
#include <Eigen/Dense>

int main()
{
    FEM::Geometry *geo = new FEM::Geometry("C:/Users/david/Desktop/FEM++/resources/Beam_serendipity.json");
    std::vector<std::vector<double>> *x = (*(geo->elements[0])).givePsi();
    Utils::printMatrix(*x);
    std::cout << std::endl;
    std::vector<std::vector<double>> *x2 = (*(geo->elements[1])).givePsi();
    Utils::printMatrix(*x2);
    // std::cout << *geo << std::endl;
}