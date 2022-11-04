#ifndef ELEMENT3D_H
#define ELEMENT3D_H

#include <iostream>
#include <vector>
#include "Element.h"

namespace FEM
{
	class Element3D : public Element
	{
	public:
		Element3D(std::vector<std::vector<double *>> coords, std::vector<std::vector<int>> gdls);
		bool isInside(std::vector<std::vector<double>> &x);
	};
}
#endif