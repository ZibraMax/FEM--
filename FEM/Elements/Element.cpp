#include "Element.h"

namespace FEM
{
	Element::Element(std::vector<std::vector<double *>> coords, std::vector<std::vector<int>> gdls)
	{
		this->coords = coords;
		this->gdls = gdls;
		this->_gdl = {};
		this->n = coords.size();
		int k = coords[0].size();
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < this->n; j++)
			{
				this->_gdl.push_back(gdls[i][j]);
			}
		}
	}

	void Element::transformations(std::vector<std::vector<double>> &Z)
	{
		det_jacs = {};
		inv_jacs = {};
		dpx = {};
		x = T(Z);
		std::vector<std::vector<std::vector<double>>> jacs = J(Z);
		std::vector<std::vector<std::vector<double>>> D = *givePsiDerivatives();
		for (int i = 0; i < jacs.size(); i++)
		{
			std::vector<std::vector<double>> jac = jacs[i];
			Eigen::MatrixXd Mjac = Utils::matrixFromArray(jac);
			Eigen::MatrixXd Ijac = Mjac.inverse();
			double Djac = Mjac.determinant();
			det_jacs.push_back(Djac);
			inv_jacs.push_back(Utils::arrayFromMatrix(Ijac));
			Eigen::MatrixXd dpxx = Ijac * (Utils::matrixFromArray(D[i]).transpose());
			dpx.push_back(Utils::arrayFromMatrix(dpxx));
		}
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
		std::vector<std::vector<std::vector<double>>> Dpsi = this->dpsis(z);
		std::vector<std::vector<std::vector<double>>> res;
		Eigen::MatrixXd Mcoords = Utils::matrixFromArray2(coords);
		for (int i = 0; i < Dpsi.size(); i++)
		{
			Eigen::MatrixXd d = Utils::matrixFromArray(Dpsi[i]).transpose() * Mcoords;
			res.push_back(Utils::arrayFromMatrix(d));
		}

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
	std::vector<double> *Element::giveW()
	{
		return nullptr;
	}

} // namespace FEM
