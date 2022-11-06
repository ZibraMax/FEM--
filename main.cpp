#include <iostream>
#include "FEM.h"
#include "Element.h"
#include "CubeScheme.h"
#include "Utils.h"
#include "Elasticity2D.h"
#include "FEM/Geometry/Geometry.h"
#include <Eigen/Dense>
#include <unistd.h>
#include <chrono>
#include <windows.h>
using namespace std::chrono;
using namespace std;
int main()
{
    auto start = high_resolution_clock::now();
    double E = 21000000;
    double v = 0.2;
    FEM::Geometry *geo = new FEM::Geometry("C:/Users/david/Desktop/FEM++/resources/BeamBC.json");
    FEM::PlaneStress *O = new FEM::PlaneStress(geo, E, v, 0.1, 0.0, 0.0, 0.0);
    O->solve();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    std::cout << ((double)duration.count()) / 1000 << std::endl;
    sleep(10);
    // std::cout << *geo << std::endl;
}