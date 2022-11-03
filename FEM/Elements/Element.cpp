#include "Element.h"

namespace FEM
{
	Element::Element(std::vector<std::vector<double *>> coords, std::vector<std::vector<int>> gdls)
	{
		this->coords = coords;
		this->gdls = gdls;
		this->n = coords.size();
	}
	std::ostream &operator<<(std::ostream &output, const Element e)
	{
		output << "Element of " << e.n << " nodes" << std::endl;
		output << "Coords:" << std::endl;
		int ndim = e.coords[0].size();
		for (int i = 0; i < e.n; i++)
		{
			for (int j = 0; j < ndim; j++)
			{
				output << *e.coords[i][j] << "\t";
			}
			output << std::endl;
		}
		output << "Degrees of freedom:" << std::endl;
		for (int i = 0; i < ndim; i++)
		{
			output << "Var " << i << "\t";
		}
		output << std::endl;
		for (int j = 0; j < e.n; j++)
		{
			for (int i = 0; i < ndim; i++)
			{
				output << e.gdls[i][j] << "\t";
			}
			output << std::endl;
		}
		output << "++++++++++++++++++++++++";

		return output;
	}
} // namespace FEM
