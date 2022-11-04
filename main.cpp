#include <iostream>
#include "FEM.h"
#include "FEM/Geometry/Geometry.h"
#include <Eigen/Dense>

int main()
{
    FEM::Geometry *geo = new FEM::Geometry("C:/Users/david/Desktop/FEM++/resources/Beam_serendipity.json");
    std::cout << *geo << std::endl;
}