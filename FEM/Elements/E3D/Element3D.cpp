#include "Element3D.h"

namespace FEM
{
	Element3D::Element3D(std::vector<std::vector<double *>> coords, std::vector<std::vector<int>> gdls) : Element(coords, gdls)
	{
	}
	bool Element3D::isInside(std::vector<std::vector<double>> &x)
	{
		return true;
	}
}