#ifndef TRIANGULAR_SCHEME_H
#define TRIANGULAR_SCHEME_H
#include <vector>

namespace FEM
{
	class TriangularScheme
	{

	public:
		inline static std::vector<std::vector<double>> Z;
		inline static std::vector<double> W;
		TriangularScheme();
	};

}
#endif