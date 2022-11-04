#ifndef ELEMENT2D_H
#define ELEMENT2D_H

#include <iostream>
#include <vector>
#include "Element.h"

namespace FEM
{
	class Element2D : public Element
	{
	public:
		Element2D(std::vector<std::vector<double *>> coords, std::vector<std::vector<int>> gdls);
		bool isInside(std::vector<std::vector<double>> &x);
	};
}
#endif