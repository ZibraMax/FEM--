#include "Utils.h"
const double Pi = 3.141592653589793238463;
namespace Utils
{
	void printMatrix(std::vector<std::vector<double>> x)
	{
		for (int i = 0; i < x.size(); i++)
		{
			for (int j = 0; j < x[i].size(); j++)
			{
				std::cout << x[i][j] << ",";
			}
			std::cout << std::endl;
		}
	}
	double p(double x, int n)
	{
		if (n == 0)
		{
			return 1;
		}
		else if (n == 1)
		{
			return x;
		}
		else
		{
			return 1.0 / n * ((2.0 * n - 1.0) * x * p(x, n - 1) - (n - 1.0) * p(x, n - 2));
		}
	}
	double dpdx(double x, int n)
	{
		return n / (x * x - 1.0) * (x * p(x, n) - p(x, n - 1));
	}

	std::vector<double> darPuntos(int n)
	{
		std::vector<double> puntos;
		double tol = 1.0 * pow(10.0, -16.0);
		for (int i = 1; i <= n; ++i)
		{
			double x = cos(Pi * (i - 0.25) / (n + 0.5));
			double error = 1;
			while (fabs(error) > tol)
			{
				error = p(x, n) / dpdx(x, n);
				x -= error;
			}
			puntos.push_back(x);
		}
		return puntos;
	}

	std::vector<double> darPesos(int n, std::vector<double> puntos)
	{
		std::vector<double> pesos;
		for (int i = 0; i < puntos.size(); ++i)
		{
			double deriv = dpdx(puntos[i], n);
			double w = 2.0 / (1.0 - puntos[i] * puntos[i]) / deriv / deriv;
			pesos.push_back(w);
		}
		return pesos;
	}

	const static Eigen::IOFormat CSVFormat(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", "\n");

	void writeToCSVfile(std::string name, const Eigen::MatrixXd &matrix)
	{
		std::ofstream file(name.c_str());
		file << matrix.format(CSVFormat);
	}

	Eigen::MatrixXd matrixFromArray(std::vector<std::vector<double>> &z)
	{
		Eigen::MatrixXd res(z.size(), z[0].size());
		for (int i = 0; i < z.size(); i++)
		{
			for (int j = 0; j < z[0].size(); j++)
			{
				res(i, j) = z[i][j];
			}
		}
		return res;
	}
	Eigen::MatrixXd matrixFromArray2(std::vector<std::vector<double *>> &z)
	{
		Eigen::MatrixXd res(z.size(), z[0].size());
		for (int i = 0; i < z.size(); i++)
		{
			for (int j = 0; j < z[0].size(); j++)
			{
				res(i, j) = *z[i][j];
			}
		}
		return res;
	}

	std::vector<std::vector<double>> arrayFromMatrix(Eigen::MatrixXd &M)
	{
		int n = M.rows();
		int m = M.cols();
		std::vector<std::vector<double>> res;
		for (int i = 0; i < n; i++)
		{
			std::vector<double> row;
			for (int j = 0; j < m; j++)
			{
				row.push_back(M(i, j));
			}
			res.push_back(row);
		}
		return res;
	}

} // namespace Utils