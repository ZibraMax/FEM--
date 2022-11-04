#include "RectangularScheme.h"

namespace FEM
{
	RectangularScheme::RectangularScheme(int n)
	{

		std::vector<double> zz = Utils::darPuntos(n);
		std::vector<double> www = Utils::darPesos(n, zz);
		std::vector<double> zz1;
		std::vector<double> zz2;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				zz1.push_back(zz[i]);
				zz2.push_back(zz[j]);
				W.push_back(www[i] * www[j]);
			}
		}
		Z = {zz1, zz2};
	}

} // namespace FEM
