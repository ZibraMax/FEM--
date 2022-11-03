#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Element.h"

#include <nlohmann/json.hpp>

namespace FEM
{
	class Geometry
	{
	public:
		std::vector<std::vector<double>> nodes;
		std::vector<std::vector<int>> dictionary;
		std::vector<std::string> types;
		std::vector<std::vector<int>> regions;
		std::vector<std::vector<double>> ebc;
		std::vector<std::vector<double>> nbc;
		int nvn;
		int ngdl;
		bool allElementsSameType = true;

		std::vector<Element *> elements;

		void setEbc(std::vector<std::vector<double>> ebc);
		void setNbc(std::vector<std::vector<double>> nbc);
		void initializeElements();

		Geometry(std::vector<std::vector<double>> nodes_coords, std::vector<std::vector<int>> dictionary, std::vector<std::string> types, int nvn);
		Geometry(std::string json_file);
		Geometry();

		friend std::ostream &operator<<(std::ostream &output, const Geometry geometry);
	};
}
#endif