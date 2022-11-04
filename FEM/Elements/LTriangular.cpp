#include "LTriangular.h"

namespace FEM
{
	LTriangular::LTriangular(std::vector<std::vector<double *>> coords, std::vector<std::vector<int>> gdl)
		: TriangularScheme(), Element2D(coords, gdl)
	{
		// Definir bordes
	}

	std::vector<std::vector<double>> LTriangular::psis(std::vector<std::vector<double>> &z)
	{
		// Crear algo para pasar a matriz?
		std::vector<std::vector<double>> res;
		// int n_z = z.row(0).size();
		// Eigen::MatrixXd res(this->n, n_z);
		// Eigen::ArrayXd _z = z.row(0).array();
		// Eigen::ArrayXd _n = z.row(1).array();
		// res << (1.0 - _z - _n).matrix().transpose(), _z.matrix().transpose(), _n.matrix().transpose();
		return res;
	}

	std::vector<std::vector<std::vector<double>>> LTriangular::dpsis(std::vector<std::vector<double>> &z)
	{
		std::vector<std::vector<std::vector<double>>> res;
		// int n = z.row(0).size();
		// for (int i = 0; i < n; i++)
		// {
		// 	Eigen::MatrixXd matrix(this->n, this->m);
		// 	matrix << -1.0, -1.0, 1.0, 0.0, 0.0, 1.0;
		// 	res.push_back(matrix);
		// }

		return res;
	}

	std::vector<std::vector<std::vector<double>>> *LTriangular::givePsiDerivatives()
	{
		return &DPSI;
	}
	std::vector<std::vector<double>> *LTriangular::givePsi()
	{
		return &PSI;
	}

} // namespace FEM
