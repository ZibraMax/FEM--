#ifndef RECTANGULAR_SCHEME_H
#define RECTANGULAR_SCHEME_H

#include "Element2D.h"
#include "Utils.h"

#include <vector>

namespace FEM
{
	class RectangularScheme
	{

	public:
		inline static std::vector<std::vector<double>> Z;
		inline static std::vector<double> W;
		RectangularScheme(int n);
	};

}

#endif