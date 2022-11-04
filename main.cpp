#include <iostream>
#include "FEM.h"
#include "Element.h"
#include "Utils.h"
#include "FEM/Geometry/Geometry.h"
#include <Eigen/Dense>
#include <unistd.h>
#include <chrono>
using namespace std::chrono;

int main()
{
    auto start = high_resolution_clock::now();

    FEM::Geometry *geo = new FEM::Geometry("C:/Users/david/Desktop/FEM++/resources/Cube.json");
    FEM::Element *e0 = geo->elements[0];
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    // To get the value of duration use the count()
    // member function on the duration object
    std::cout << ((double)duration.count()) / 1000 << std::endl;

    std::vector<std::vector<std::vector<double>>> *x = e0->givePsiDerivatives();
    Utils::printMatrix((*x)[0]);
    std::cout << std::endl;
    e0 = geo->elements[1];
    std::vector<std::vector<std::vector<double>>> *x2 = e0->givePsiDerivatives();
    Utils::printMatrix((*x2)[0]);
    // std::cout << *geo << std::endl;
}