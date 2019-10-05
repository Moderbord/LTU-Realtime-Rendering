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
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim))
	{
		if (item.at(0) == 'v') continue;
		*(vector++) = std::stof(item, nullptr);
	}
}

template<typename BackInserter>
void stString(const std::string& s, char delim, BackInserter vector)
{
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim))
	{
		if (item.at(0) == 'f') continue;
		*(vector++) = item;
	}
}

int main()
{

	std::vector<std::vector<float>> vertexPos;
	std::vector<std::vector<float>> vertexTex;
	std::vector<std::vector<float>> vertexNormal;
	std::vector<std::vector<std::string>> verticesStr;

	std::string objPath = "deer.obj";
	std::ifstream ifStream(objPath);
	cout << "Loading " << objPath << "..\n" << endl;

	std::stringstream sStream;
	std::string line;
	while (getline(ifStream, line))
	{
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
			verticesStr.push_back(vec);
			continue;
		}
	}

	cout << vertexPos.size() << " vertex positions loaded" << endl;
	cout << vertexTex.size() << " vertex texture mappings loaded" << endl;
	cout << vertexNormal.size() << " vertex normals loaded" << endl;

}