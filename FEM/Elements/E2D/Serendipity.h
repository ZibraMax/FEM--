#ifndef SERENDIPITY_H
#define SERENDIPITY_H
#include "RectangularScheme.h"
#include "Element2D.h"
#include <vector>
#include <iostream>

namespace FEM
{
	class Serendipity : public RectangularScheme, public Element2D
	{
	private:
		inline static std::vector<std::vector<double>> PSI;
		inline static std::vector<std::vector<std::vector<double>>> DPSI;

	public:
		Serendipity(std::vector<std::vector<double *>> coords, std::vector<std::vector<int>> gdl);
		std::vector<std::vector<double>> psis(std::vector<std::vector<double>> &z);
		std::vector<std::vector<std::vector<double>>> dpsis(std::vector<std::vector<double>> &z);
		std::vector<std::vector<std::vector<double>>> *givePsiDerivatives();
		std::vector<std::vector<double>> *givePsi();
		std::vector<double> *giveW();
	};
}
#endif
