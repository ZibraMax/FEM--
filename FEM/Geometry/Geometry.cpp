#include "Geometry.h"

namespace FEM
{
	Geometry::Geometry()
	{
		std::cout << "kudos" << std::endl;
	}

	Geometry::Geometry(std::vector<std::vector<double>> nodes_coords, std::vector<std::vector<int>> dictionary, std::vector<std::string> types, int nvn)
	{
		this->nodes = nodes_coords;
		this->types = types;
		this->dictionary = dictionary;
		this->nvn = nvn;
		this->initializeElements();
	}

	Geometry::Geometry(std::string json_file)
	{
		// open json file
		std::ifstream i(json_file);
		nlohmann::json j;
		i >> j;
		this->nodes = j["nodes"].get<std::vector<std::vector<double>>>();
		this->dictionary = j["dictionary"].get<std::vector<std::vector<int>>>();
		this->allElementsSameType = j.value("sameTypeElements", true);
		if (this->allElementsSameType)
		{
			this->allElementsType = j["types"].get<std::vector<std::string>>()[0];
		}
		else
		{
			this->types = j["types"].get<std::vector<std::string>>();
		}

		this->ebc = j["ebc"].get<std::vector<std::vector<double>>>();
		this->nbc = j["nbc"].get<std::vector<std::vector<double>>>();
		this->nvn = j["nvn"].get<int>();
		this->ngdl = j["ngdl"].get<int>();
		this->initializeElements();
	}

	void Geometry::initializeElements()
	{
		this->ngdl = this->nodes.size() * this->nvn;
		for (int i = 0; i < dictionary.size(); i++)
		{
			std::vector<int> element_nodes = dictionary[i];
			int n = element_nodes.size();
			std::vector<std::vector<double *>> coords;
			std::vector<std::vector<int>> gdls;
			int ndim = nodes[0].size();
			for (int j = 0; j < n; j++)
			{
				std::vector<double *> node;
				for (int k = 0; k < ndim; k++)
				{
					node.push_back(&nodes[element_nodes[j]][k]);
				}
				coords.push_back(node);
			}

			for (int k = 0; k < this->nvn; k++)
			{
				std::vector<int> linea = element_nodes;
				for (int j = 0; j < linea.size(); j++)
				{
					linea[j] = linea[j] * this->nvn + k;
				}
				gdls.push_back(linea);
			}
			std::string tipo;

			if (this->allElementsSameType)
			{
				tipo = this->allElementsType;
			}
			else
			{
				tipo = this->types[i];
			}

			this->elements.push_back(createElement(tipo, coords, gdls));
		}
	}

	void Geometry::setEbc(std::vector<std::vector<double>> ebc)
	{
		this->ebc = ebc;
	}

	void Geometry::setNbc(std::vector<std::vector<double>> nbc)
	{
		this->nbc = nbc;
	}
	Element *Geometry::createElement(std::string type, std::vector<std::vector<double *>> coords, std::vector<std::vector<int>> gdl)
	{
		Element *elemento;
		if (type == "T1V")
		{
			elemento = new LTriangular(coords, gdl);
		}
		else if (type == "T2V")
		{
			/* code */
		}
		else if (type == "C1V")
		{
			/* code */
		}
		else if (type == "C2V")
		{
			elemento = new Serendipity(coords, gdl);
		}
		else if (type == "L1V")
		{
			/* code */
		}
		else if (type == "L2V")
		{
			/* code */
		}
		else if (type == "L3V")
		{
			/* code */
		}
		else if (type == "B1V")
		{
			elemento = new Cube(coords, gdl);
		}
		else if (type == "B2V")
		{
			/* code */
		}
		else if (type == "TE1V")
		{
			/* code */
		}
		else if (type == "TE2V")
		{
			/* code */
		}
		return elemento;
	}
	std::ostream &operator<<(std::ostream &output, const Geometry geometry)
	{
		output << "Geometry " << std::endl;
		output << "DOF: " << geometry.ngdl << std::endl;
		output << "Number of elements: " << geometry.elements.size() << std::endl;
		output << "---------------------------------" << std::endl;
		for (int i = 0; i < geometry.elements.size(); ++i)
		{
			std::cout << "Element " << i + 1 << ": " << *geometry.elements[i] << std::endl;
		}
		output << "End of geometry";
		return output;
	}
} // namespace FEM
