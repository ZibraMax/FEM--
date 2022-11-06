#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
#include <vector>
#include "Utils.h"
#include <Eigen/Dense>

namespace FEM
{
	class Element
	{
	public:
		std::vector<std::vector<double *>> coords;
		std::vector<std::vector<double>> x;
		std::vector<double> det_jacs;
		std::vector<std::vector<std::vector<double>>> inv_jacs;
		std::vector<std::vector<int>> gdls;
		std::vector<int> _gdl;
		std::vector<std::vector<std::vector<double>>> dpx;

		int n;
		void transformations(std::vector<std::vector<double>> &Z);
		Element(std::vector<std::vector<double *>> coords, std::vector<std::vector<int>> gdls);
		std::vector<std::vector<double>> T(std::vector<std::vector<double>> &z);
		std::vector<std::vector<std::vector<double>>> J(std::vector<std::vector<double>> &z);
		friend std::ostream &operator<<(std::ostream &output, const Element e);

		virtual bool isInside(std::vector<std::vector<double>> &x);

		virtual std::vector<std::vector<double>> psis(std::vector<std::vector<double>> &z);
		virtual std::vector<std::vector<std::vector<double>>> dpsis(std::vector<std::vector<double>> &z);
		virtual std::vector<std::vector<std::vector<double>>> *givePsiDerivatives();
		virtual std::vector<std::vector<double>> *givePsi();
		virtual std::vector<double> *giveW();
	};
}
#endif