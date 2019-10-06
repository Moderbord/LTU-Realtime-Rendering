#pragma once

#include "Parser.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>


namespace
{
	using std::cout;
	using std::endl;
}

template<typename BackInserter>
void stFloat(const std::string& s, char delim, BackInserter vector)
{
	std::stringstream stream(s);
	std::string item;
	while (std::getline(stream, item, delim))
	{
		if (item.at(0) == 'v') continue;
		*(vector++) = std::stof(item, nullptr);
	}
}

template<typename BackInserter>
void stString(const std::string& s, char delim, BackInserter vector)
{
	std::stringstream stream(s);
	std::string item;
	while (std::getline(stream, item, delim))
	{
		if (item.at(0) == 'f') continue;
		*(vector++) = item;
	}
}

int main()
{
	int trangleCount = 0;
	int quadCount = 0;
	std::string objPath = "cube.obj";
	cout << "Loading " << objPath << "..\n" << endl;

	std::vector<std::vector<float>> vertexPos;
	std::vector<std::vector<float>> vertexTex;
	std::vector<std::vector<float>> vertexNormal;
	std::vector<std::vector<std::string>> triangleStr;
	std::vector<std::vector<float>> indicies;

	std::ifstream ifStream(objPath);
	std::stringstream sStream;
	std::string line;
	while (getline(ifStream, line))
	{
		if (line.find("#") != std::string::npos)
		{
			continue;
		}
		if (line.find("v ") != std::string::npos)
		{
			std::vector<float> vec;
			stFloat(line, (char)32, std::back_inserter(vec));
			vertexPos.push_back(vec);
			continue;
		}
		if (line.find("vt") != std::string::npos)
		{
			std::vector<float> vec;
			stFloat(line, (char)32, std::back_inserter(vec));
			vertexTex.push_back(vec);
			continue;
		}
		if (line.find("vn") != std::string::npos)
		{
			std::vector<float> vec;
			stFloat(line, (char)32, std::back_inserter(vec));
			vertexNormal.push_back(vec);
			continue;
		}
		if (line.find("f ") != std::string::npos)
		{
			std::vector<std::string> vec;
			stString(line, (char)32, std::back_inserter(vec));

			if (vec.size() > 3)
			{
				int i;
				for (i = 2; i < vec.size(); i++)
				{
					std::vector<std::string> qVec;
					qVec.push_back(vec[0]);
					qVec.push_back(vec[i - 1]);
					qVec.push_back(vec[i]);
					triangleStr.push_back(qVec);
				}
				cout << i << "-sized polygon found. Splitting.." << endl;
				continue;
			}
			triangleStr.push_back(vec);
			continue;
		}
	}

	for (std::vector<std::vector<std::string>>::iterator it = triangleStr.begin(); it != triangleStr.end(); it++)
	{
		for (int i = 0; i < 3; i++)
		{
			std::vector<float> vec;
			stFloat((*it)[i], '/', std::back_inserter(vec));
			indicies.push_back(vec);
		}
	}

	cout << vertexPos.size() << " vertex positions loaded" << endl;
	cout << vertexTex.size() << " vertex texture mappings loaded" << endl;
	cout << vertexNormal.size() << " vertex normals loaded" << endl;
	cout << triangleStr.size() << " total traingles" << endl;
	cout << indicies.size() << " total indicies" << endl;

}