#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include "Eigen/Dense"
namespace Utils
{

	double p(double x, int n);
	double dpdx(double x, int n);
	std::vector<double> darPuntos(int n);
	std::vector<double> darPesos(int n, std::vector<double> puntos);
	void writeToCSVfile(std::string name, const Eigen::MatrixXd &matrix);
	void printMatrix(std::vector<std::vector<double>> x);
	Eigen::MatrixXd matrixFromArray(std::vector<std::vector<double>> &z);
	Eigen::MatrixXd matrixFromArray2(std::vector<std::vector<double *>> &z);
	std::vector<std::vector<double>> arrayFromMatrix(Eigen::MatrixXd &M);
} // namespace Utils

#endif