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

	std::vector<std::vector<double>> Element::T(std::vector<std::vector<double>> &z)
	{
		std::vector<std::vector<double>> P = this->psis(z);
		Eigen::MatrixXd MP = Utils::matrixFromArray(P);
		Eigen::MatrixXd Mcoords = Utils::matrixFromArray2(coords);
		Eigen::MatrixXd Tx = MP * Mcoords;
		std::vector<std::vector<double>> res = Utils::arrayFromMatrix(Tx);
		return res;
	}
	std::vector<std::vector<std::vector<double>>> Element::J(std::vector<std::vector<double>> &z)
	{
		std::vector<std::vector<std::vector<double>>> Dpsis = this->dpsis(z);
		std::vector<Eigen::MatrixXd> MDpsis;
		for (int i = 0; i < Dpsis.size(); i++)
		{
			MDpsis.push_back(Utils::matrixFromArray(Dpsis[i]));
		}

		Eigen::MatrixXd MP = Utils::matrixFromArray(P);
		Eigen::MatrixXd Mcoords = Utils::matrixFromArray2(coords);
		Eigen::MatrixXd Tx = MP * Mcoords;
		std::vector<std::vector<double>> res = Utils::arrayFromMatrix(Tx);
		return res;
	}

	bool Element::isInside(std::vector<std::vector<double>> &z)
	{
		return false;
	}
	std::vector<std::vector<double>> Element::psis(std::vector<std::vector<double>> &z)
	{
		return {};
	}

	std::vector<std::vector<std::vector<double>>> Element::dpsis(std::vector<std::vector<double>> &z)
	{

		return {};
	}
	std::vector<std::vector<std::vector<double>>> *Element::givePsiDerivatives()
	{
		return nullptr;
	}
	std::vector<std::vector<double>> *Element::givePsi()
	{
		return nullptr;
	}
} // namespace FEM
