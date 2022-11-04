#ifndef CUBE_SCHEME_H
#define CUBE_SCHEME_H

#include "Element3D.h"
#include "Utils.h"

#include <vector>

namespace FEM
{
	class CubeScheme
	{

	public:
		inline static std::vector<std::vector<double>> Z;
		inline static std::vector<double> W;
		CubeScheme(int n);
	};

}

#endif