#include "Cube.h"

namespace FEM
{
	Cube::Cube(std::vector<std::vector<double *>> coords, std::vector<std::vector<int>> gdl)
		: CubeScheme(3), Element3D(coords, gdl)
	{
		PSI = this->psis(Z);
		DPSI = this->dpsis(Z);
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
			std::vector<double> row = {(1 - z) * (1 - n) * (1 - g),
									   (1 + z) * (1 - n) * (1 - g),
									   (1 + z) * (1 + n) * (1 - g),
									   (1 - z) * (1 + n) * (1 - g),
									   (1 - z) * (1 - n) * (1 + g),
									   (1 + z) * (1 - n) * (1 + g),
									   (1 + z) * (1 + n) * (1 + g),
									   (1 - z) * (1 + n) * (1 + g)};
			res.push_back(row);
		}

		return res;
	}

	std::vector<std::vector<std::vector<double>>> Cube::dpsis(std::vector<std::vector<double>> &_z)
	{
		int nz = _z[0].size();
		std::vector<std::vector<std::vector<double>>> res;
		std::vector<std::vector<double>> fila1;
		std::vector<std::vector<double>> fila2;
		std::vector<std::vector<double>> fila3;
		std::vector<std::vector<double>> fila4;
		std::vector<std::vector<double>> fila5;
		std::vector<std::vector<double>> fila6;
		std::vector<std::vector<double>> fila7;
		std::vector<std::vector<double>> fila8;
		for (int i = 0; i < nz; i++)
		{
			double x = _z[0][i];
			double y = _z[1][i];
			double z = _z[2][i];
			fila1.push_back({(y - 1.0) * (1.0 - z), (x - 1) * (1 - z), -(1 - x) * (1 - y)});
			fila2.push_back({(1 - y) * (1 - z), (-1 - x) * (1 - z), -(1 + x) * (1 - y)});
			fila3.push_back({(1 + y) * (1 - z), (1 + x) * (1 - z), -(1 + x) * (1 + y)});
			fila4.push_back({(-1.0 - y) * (1 - z), (1 - x) * (1 - z), -(1 - x) * (1 + y)});

			fila5.push_back({(1 - y) * (-1 - z), -(1 - x) * (1 + z), (1 - x) * (1 - y)});
			fila6.push_back({(1 - y) * (1 + z), -(1 + x) * (1 + z), (1 + x) * (1 - y)});
			fila7.push_back({(1 + y) * (1 + z), (1 + x) * (1 + z), (1 + x) * (1 + y)});
			fila8.push_back({-(1 + y) * (1 + z), (1 - x) * (1 + z), (1 - x) * (1 + y)});
		}
		res = {fila1, fila2, fila3, fila4, fila5, fila6, fila7, fila8};

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

} // namespace FEM
