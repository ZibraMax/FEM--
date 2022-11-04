#include <iostream>
#include "FEM.h"
#include "Element.h"
#include "FEM/Geometry/Geometry.h"
#include <Eigen/Dense>

void printMatrix(std::vector<std::vector<double>> x)
{
    for (int i = 0; i < x.size(); i++)
    {
        for (int j = 0; j < x[i].size(); j++)
        {
            std::cout << x[i][j] << ",";
        }
        std::cout << std::endl;
    }
}

int main()
{
    FEM::Geometry *geo = new FEM::Geometry("C:/Users/david/Desktop/FEM++/resources/Beam_serendipity.json");
    std::vector<std::vector<double>> *x = (*(geo->elements[0])).givePsi();
    printMatrix(*x);
    std::cout << std::endl;
    std::vector<std::vector<double>> *x2 = (*(geo->elements[1])).givePsi();
    printMatrix(*x2);
    // std::cout << *geo << std::endl;
}