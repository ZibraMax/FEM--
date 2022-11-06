#include "Cube.h"

namespace FEM
{
	Cube::Cube(std::vector<std::vector<double *>> coords, std::vector<std::vector<int>> gdl)
		: CubeScheme(3), Element3D(coords, gdl)
	{
		PSI = this->psis(Z);
		DPSI = this->dpsis(Z);
		transformations(Z);
		// Definir bordes
	}

	std::vector<std::vector<double>> Cube::psis(std::vector<std::vector<double>> &_z)
	{
		std::vector<std::vector<double>> res;
		int nz = _z[0].size();

		for (int i = 0; i < nz; i++)
		{
			double z = _z[0][i];
			double n = _z[1][i];
			double g = _z[2][i];
			std::vector<double> row = {(1 - z) * (1 - n) * (1 - g) / 8.0,
									   (1 + z) * (1 - n) * (1 - g) / 8.0,
									   (1 + z) * (1 + n) * (1 - g) / 8.0,
									   (1 - z) * (1 + n) * (1 - g) / 8.0,
									   (1 - z) * (1 - n) * (1 + g) / 8.0,
									   (1 + z) * (1 - n) * (1 + g) / 8.0,
									   (1 + z) * (1 + n) * (1 + g) / 8.0,
									   (1 - z) * (1 + n) * (1 + g) / 8.0};
			res.push_back(row);
		}

		return res;
	}

	std::vector<std::vector<std::vector<double>>> Cube::dpsis(std::vector<std::vector<double>> &_z)
	{
		int nz = _z[0].size();
		std::vector<std::vector<std::vector<double>>> res;
		for (int i = 0; i < nz; i++)
		{
			double x = _z[0][i];
			double y = _z[1][i];
			double z = _z[2][i];
			res.push_back({{(y - 1.0) * (1.0 - z) / 8.0, (x - 1) * (1 - z) / 8.0, -(1 - x) * (1 - y) / 8.0},
						   {(1 - y) * (1 - z) / 8.0, (-1 - x) * (1 - z) / 8.0, -(1 + x) * (1 - y) / 8.0},
						   {(1 + y) * (1 - z) / 8.0, (1 + x) * (1 - z) / 8.0, -(1 + x) * (1 + y) / 8.0},
						   {(-1.0 - y) * (1 - z) / 8.0, (1 - x) * (1 - z) / 8.0, -(1 - x) * (1 + y) / 8.0},
						   {(1 - y) * (-1 - z) / 8.0, -(1 - x) * (1 + z) / 8.0, (1 - x) * (1 - y) / 8.0},
						   {(1 - y) * (1 + z) / 8.0, -(1 + x) * (1 + z) / 8.0, (1 + x) * (1 - y) / 8.0},
						   {(1 + y) * (1 + z) / 8.0, (1 + x) * (1 + z) / 8.0, (1 + x) * (1 + y) / 8.0},
						   {-(1 + y) * (1 + z) / 8.0, (1 - x) * (1 + z) / 8.0, (1 - x) * (1 + y) / 8.0}});
		}

		return res;
	}
	std::vector<std::vector<std::vector<double>>> *Cube::givePsiDerivatives()
	{
		return &DPSI;
	}
	std::vector<std::vector<double>> *Cube::givePsi()
	{
		return &PSI;
	}
	std::vector<double> *Cube::giveW()
	{
		return &W;
	}

} // namespace FEM
