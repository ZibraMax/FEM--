#include "Serendipity.h"

namespace FEM
{
	Serendipity::Serendipity(std::vector<std::vector<double *>> coords, std::vector<std::vector<int>> gdl)
		: RectangularScheme(3), Element2D(coords, gdl)
	{
		PSI = this->psis(Z);
		DPSI = this->dpsis(Z);
		// Definir bordes
	}

	std::vector<std::vector<double>> Serendipity::psis(std::vector<std::vector<double>> &z)
	{
		std::vector<std::vector<double>> res;
		int nz = z[0].size();
		for (int i = 0; i < nz; i++)
		{
			std::vector<double> row = {0.25 * (1.0 - z[0][i]) * (1.0 - z[1][i]) * (-1.0 - z[0][i] - z[1][i]),
									   0.25 * (1.0 + z[0][i]) * (1.0 - z[1][i]) * (-1.0 + z[0][i] - z[1][i]),
									   0.25 * (1.0 + z[0][i]) * (1.0 + z[1][i]) * (-1.0 + z[0][i] + z[1][i]),
									   0.25 * (1.0 - z[0][i]) * (1.0 + z[1][i]) * (-1.0 - z[0][i] + z[1][i]),
									   0.5 * (1.0 - z[0][i] * z[0][i]) * (1.0 - z[1][i]),
									   0.5 * (1.0 + z[0][i]) * (1.0 - z[1][i] * z[1][i]),
									   0.5 * (1.0 - z[0][i] * z[0][i]) * (1.0 + z[1][i]),
									   0.5 * (1.0 - z[0][i]) * (1.0 - z[1][i] * z[1][i])};
			res.push_back(row);
		}

		return res;
	}

	std::vector<std::vector<std::vector<double>>> Serendipity::dpsis(std::vector<std::vector<double>> &z)
	{
		int nz = z[0].size();
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
			fila1.push_back({-0.25 * (z[1][i] - 1.0) * (2.0 * z[0][i] + z[1][i]), -0.25 * (z[0][i] - 1.0) * (2.0 * z[1][i] + z[0][i])});
			fila2.push_back({-0.25 * (z[1][i] - 1.0) * (2.0 * z[0][i] - z[1][i]), 0.25 * (z[0][i] + 1.0) * (2.0 * z[1][i] - z[0][i])});
			fila3.push_back({0.25 * (z[1][i] + 1.0) * (2.0 * z[0][i] + z[1][i]), 0.25 * (z[0][i] + 1.0) * (2.0 * z[1][i] + z[0][i])});
			fila4.push_back({0.25 * (z[1][i] + 1.0) * (2.0 * z[0][i] - z[1][i]), -0.25 * (z[0][i] - 1.0) * (2.0 * z[1][i] - z[0][i])});
			fila5.push_back({(z[1][i] - 1.0) * z[0][i], 0.5 * (z[0][i] * z[0][i] - 1.0)});
			fila6.push_back({-0.5 * (z[1][i] * z[1][i] - 1.0), -z[1][i] * (z[0][i] + 1.0)});
			fila7.push_back({-(z[1][i] + 1.0) * z[0][i], -0.5 * (z[0][i] * z[0][i] - 1.0)});
			fila8.push_back({0.5 * (z[1][i] * z[1][i] - 1.0), z[1][i] * (z[0][i] - 1.0)});
		}
		res = {fila1, fila2, fila3, fila4, fila5, fila6, fila7, fila8};

		return res;
	}
	std::vector<std::vector<std::vector<double>>> *Serendipity::givePsiDerivatives()
	{
		return &DPSI;
	}
	std::vector<std::vector<double>> *Serendipity::givePsi()
	{
		return &PSI;
	}

} // namespace FEM
