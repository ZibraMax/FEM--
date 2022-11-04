#include "Element2D.h"

namespace FEM
{
	Element2D::Element2D(std::vector<std::vector<double *>> coords, std::vector<std::vector<int>> gdls) : Element(coords, gdls)
	{
	}
	bool Element2D::isInside(std::vector<std::vector<double>> &x)
	{
		return true;
	}
} // namespace FEM
