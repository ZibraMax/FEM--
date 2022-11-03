#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
#include <vector>

#include <Eigen/Dense>

namespace FEM
{
	class Element
	{
	public:
		std::vector<std::vector<double *>> coords;
		std::vector<std::vector<int>> gdls;
		int n;
		Element(std::vector<std::vector<double *>> coords, std::vector<std::vector<int>> gdls);
		friend std::ostream &operator<<(std::ostream &output, const Element e);
	};
}
#endif