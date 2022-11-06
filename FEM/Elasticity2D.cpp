#include "Elasticity2D.h"

namespace FEM
{
	PlaneStress::PlaneStress(Geometry *geometry, double E, double v, double t, double rho, double fx, double fy) : Core(geometry)
	{
		this->E = E;
		this->v = v;
		this->t = t;
		this->rho = rho;
		this->fx = fx;
		this->fy = fy;

		this->C11 = this->E / (1.0 - (this->v * this->v));
		this->C12 = this->v * this->C11;
		this->C66 = this->E / 2.0 / (1.0 + this->v);

		if (this->geometry->nvn != 2)
		{
			std::cout << "WARNING: Border conditions lost. You have to use a geometry with 2 variables per node." << std::endl;
			this->geometry->nvn = 2;
			this->geometry->ebc = {};
			this->geometry->nbc = {};
			this->geometry->initializeElements();
		}
	}

	void PlaneStress::elementMatrices()
	{
		for (int ee = 0; ee < this->geometry->elements.size(); ee++)
		{
			Element *e = this->geometry->elements[ee];
			int m = e->n;

			Eigen::MatrixXd B = Eigen::MatrixXd::Zero(3, 2 * m);
			Eigen::MatrixXd C = Eigen::MatrixXd::Zero(3, 3);
			C(0, 0) = C11;
			C(0, 1) = C12;
			C(1, 0) = C12;
			C(1, 1) = C11;
			C(2, 2) = C66;

			Eigen::MatrixXd K = Eigen::MatrixXd::Zero(2 * m, 2 * m);
			Eigen::VectorXd F = Eigen::VectorXd::Zero(2 * m);
			std::vector<std::vector<std::vector<double>>> dpx = e->dpx;
			std::vector<double> det_jacs = e->det_jacs;
			std::vector<double> W = *(e->giveW());
			int ezsize = dpx.size();
			for (int k = 0; k < ezsize; k++)
			{
				for (int i = 0; i < m; i++)
				{
					B(0, i) = dpx[k][0][i];
					B(1, m + i) = dpx[k][1][i];
					B(2, i) = dpx[k][1][i];
					B(2, m + i) = dpx[k][0][i];
				}
				K = K + B.transpose() * C * B * det_jacs[k] * W[k];
			}
			for (int i = 0; i < e->_gdl.size(); i++)
			{
				for (int j = 0; j < e->_gdl.size(); j++)
				{
					this->K(e->_gdl[i], e->_gdl[j]) = this->K(e->_gdl[i], e->_gdl[j]) + K(i, j);
				}
			}

			std::cout << (double)(ee + 1) / (double)this->geometry->elements.size() << std::endl;
		}
	}

} // namespace FEM