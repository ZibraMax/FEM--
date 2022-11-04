#include "TriangularScheme.h"

namespace FEM
{
	TriangularScheme::TriangularScheme()
	{
		double A0 = 1.0 / 3.0;
		double A1 = 0.059715871789770;
		double A2 = 0.797426985353087;
		double B1 = 0.470142064105115;
		double B2 = 0.101286507323456;
		double W0 = 0.1125;
		double W1 = 0.066197076394253;
		double W2 = 0.062969590272413;

		Z = {{A0, A1, B1, B1, B2, B2, A2}, {A0, B1, A1, B1, A2, B2, B2}};

		W = {W0, W1, W1, W1, W2, W2, W2};
	}

} // namespace FEM
