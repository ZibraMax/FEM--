#ifndef L_TRIANGULAR_H
#define L_TRIANGULAR_H
#include "TriangularScheme.h"
#include "Element2D.h"
#include <vector>
#include <iostream>

namespace FEM
{
	class LTriangular : public TriangularScheme, public Element2D
	{
	private:
		std::vector<std::vector<double>> PSI;
		std::vector<std::vector<std::vector<double>>> DPSI;

	public:
		LTriangular(std::vector<std::vector<double *>> coords, std::vector<std::vector<int>> gdl);
		std::vector<std::vector<double>> psis(std::vector<std::vector<double>> &z);
		std::vector<std::vector<std::vector<double>>> dpsis(std::vector<std::vector<double>> &z);

		std::vector<std::vector<std::vector<double>>> *givePsiDerivatives();
		std::vector<std::vector<double>> *givePsi();
	};

}
#endif