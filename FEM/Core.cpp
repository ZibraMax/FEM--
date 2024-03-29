#include "Core.h"

namespace FEM
{
	Core::Core(Geometry *geometry)
	{
		this->geometry = geometry;
		this->ngdl = geometry->ngdl;

		K = Eigen::MatrixXd(this->ngdl, this->ngdl);
		M = Eigen::MatrixXd(this->ngdl, this->ngdl);
		F = Eigen::VectorXd(this->ngdl);
		Q = Eigen::VectorXd(this->ngdl);
		S = Eigen::VectorXd(this->ngdl);
		U = Eigen::VectorXd(this->ngdl);
	}
	void Core::solve()
	{
		this->elementMatrices();
		this->ensembling();
		this->borderConditions();
		this->solveES();
	}

	void Core::ensembling()
	{
		// for (int el = 0; el < this->geometry->elements.size(); ++el)
		// {
		// 	Element *e = this->geometry->elements[el];
		// 	int ngdl_e = e->n * e->k;
		// 	for (int i = 0; i < ngdl_e; ++i)
		// 	{
		// 		int I = e->_gdl[i];
		// 		for (int j = 0; j < ngdl_e; ++j)
		// 		{
		// 			int J = e->_gdl[j];
		// 			this->K(I, J) += e->Ke(i, j);
		// 		}
		// 		this->F(i) += e->Fe(i);
		// 	}
		// }
	}

	void Core::borderConditions()
	{
		// std::vector<std::vector<double>> nbc = this->geometry->nbc;
		// std::vector<std::vector<double>> ebc = this->geometry->ebc;
		std::cout << "--------------------------" << std::endl;

		for (int i = 0; i < this->geometry->ebc.size(); ++i)
		{
			std::cout << this->geometry->ebc[i][0] << "," << this->geometry->ebc[i][1] << std::endl;
		}

		std::cout << "--------------------------" << std::endl;
		for (int i = 0; i < this->geometry->nbc.size(); ++i)
		{
			this->Q((int)this->geometry->nbc[i][0]) = this->geometry->nbc[i][1];
		}
		for (int i = 0; i < this->geometry->ebc.size(); ++i)
		{
			int I = (int)this->geometry->ebc[i][0];
			Eigen::VectorXd columna = this->K.col(I) * this->geometry->ebc[i][1];
			this->S = this->S - columna;
			this->K.col(I) *= 0.0;
			this->K.row(I) *= 0.0;
			this->K(I, I) = 1.0;
		}
		this->S = this->S + this->F + this->Q;

		// Utils::writeToCSVfile("S.csv", this->S);
		// Utils::writeToCSVfile("ebc.csv", this->geometry->ebc);
		for (int i = 0; i < this->geometry->ebc.size(); ++i)
		{
			int I = (int)this->geometry->ebc[i][0];
			this->S(I) = this->geometry->ebc[i][1];
		}
	}
	void Core::elementMatrices()
	{
	}
	void Core::solveES()
	{
		Utils::writeToCSVfile("S.csv", this->S);
		Utils::writeToCSVfile("k.csv", this->K);
		this->U = this->K.llt().solve(this->S);
		Utils::writeToCSVfile("U.csv", this->U);
	}

} // namespace FEM