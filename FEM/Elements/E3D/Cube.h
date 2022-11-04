#ifndef CUBE_H
#define CUBE_H
#include "CubeScheme.h"
#include "Element2D.h"
#include <vector>
#include <iostream>

namespace FEM
{
	class Cube : public CubeScheme, public Element3D
	{
	private:
		inline static std::vector<std::vector<double>> PSI;
		inline static std::vector<std::vector<std::vector<double>>> DPSI;

	public:
		Cube(std::vector<std::vector<double *>> coords, std::vector<std::vector<int>> gdl);
		std::vector<std::vector<double>> psis(std::vector<std::vector<double>> &_z);
		std::vector<std::vector<std::vector<double>>> dpsis(std::vector<std::vector<double>> &_z);
		std::vector<std::vector<std::vector<double>>> *givePsiDerivatives();
		std::vector<std::vector<double>> *givePsi();
	};
}
#endif
