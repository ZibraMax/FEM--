#include "CubeScheme.h"

namespace FEM
{
	CubeScheme::CubeScheme(int n)
	{

		std::vector<double> zz = Utils::darPuntos(n);
		std::vector<double> www = Utils::darPesos(n, zz);
		std::vector<double> zz1;
		std::vector<double> zz2;
		std::vector<double> zz3;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
				{
					zz1.push_back(zz[i]);
					zz2.push_back(zz[j]);
					zz3.push_back(zz[k]);
					W.push_back(www[i] * www[j] * www[k]);
				}
			}
		}
		Z = {zz1, zz2, zz3};
	}
} // namespace FEM
