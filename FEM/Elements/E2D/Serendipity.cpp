#include "Serendipity.h"

namespace FEM
{
	Serendipity::Serendipity(std::vector<std::vector<double *>> coords, std::vector<std::vector<int>> gdl)
		: RectangularScheme(3), Element2D(coords, gdl)
	{
		PSI = this->psis(Z);
		DPSI = this->dpsis(Z);
		transformations(Z);
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
		for (int i = 0; i < nz; i++)
		{
			res.push_back({{-0.25 * (z[1][i] - 1.0) * (2.0 * z[0][i] + z[1][i]), -0.25 * (z[0][i] - 1.0) * (2.0 * z[1][i] + z[0][i])},
						   {-0.25 * (z[1][i] - 1.0) * (2.0 * z[0][i] - z[1][i]), 0.25 * (z[0][i] + 1.0) * (2.0 * z[1][i] - z[0][i])},
						   {0.25 * (z[1][i] + 1.0) * (2.0 * z[0][i] + z[1][i]), 0.25 * (z[0][i] + 1.0) * (2.0 * z[1][i] + z[0][i])},
						   {0.25 * (z[1][i] + 1.0) * (2.0 * z[0][i] - z[1][i]), -0.25 * (z[0][i] - 1.0) * (2.0 * z[1][i] - z[0][i])},
						   {(z[1][i] - 1.0) * z[0][i], 0.5 * (z[0][i] * z[0][i] - 1.0)},
						   {-0.5 * (z[1][i] * z[1][i] - 1.0), -z[1][i] * (z[0][i] + 1.0)},
						   {-(z[1][i] + 1.0) * z[0][i], -0.5 * (z[0][i] * z[0][i] - 1.0)},
						   {0.5 * (z[1][i] * z[1][i] - 1.0), z[1][i] * (z[0][i] - 1.0)}});
		}

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
	std::vector<double> *Serendipity::giveW()
	{
		return &W;
	}

} // namespace FEM
