#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Lys/renderer/OpenGL/vertex.hpp"

namespace Lys
{
	struct TexCoord
	{
		float u, v;
	};

	struct Normal
	{
		float nx, ny, nz;
	};

	struct Face
	{
		std::vector<int> vertices;
		std::vector<int> texCoords;
		std::vector<int> normals;
	};

	Vertices<float> vertices;

	// void loadOBJ(const std::string &filename)
	// {
	// 	std::ifstream file(filename);
	// 	if (!file.is_open())
	// 	{
	// 		std::cerr << "Could not open the file: " << filename << std::endl;
	// 		return;
	// 	}

	// 	std::string line;
	// 	while (std::getline(file, line))
	// 	{
	// 		std::istringstream iss(line);
	// 		std::string prefix;
	// 		iss >> prefix;

	// 		if (prefix == "v")
	// 		{
	// 			iss >> vertex.x >> vertex.y >> vertex.z;
	// 			vertices.vertices.push_back(vertex);
	// 		}
	// 		else if (prefix == "vt")
	// 		{
	// 			TexCoord texCoord;
	// 			iss >> texCoord.u >> texCoord.v;
	// 			texCoords.push_back(texCoord);
	// 		}
	// 		else if (prefix == "vn")
	// 		{
	// 			Normal normal;
	// 			iss >> normal.nx >> normal.ny >> normal.nz;
	// 			normals.push_back(normal);
	// 		}
	// 		else if (prefix == "f")
	// 		{
	// 			Face face;
	// 			std::string vertexData;
	// 			while (iss >> vertexData)
	// 			{
	// 				std::istringstream vertexStream(vertexData);
	// 				std::string vertexIndex, texCoordIndex, normalIndex;

	// 				// Parse the face indices (v/vt/vn)
	// 				std::getline(vertexStream, vertexIndex, '/');
	// 				std::getline(vertexStream, texCoordIndex, '/');
	// 				std::getline(vertexStream, normalIndex, '/');

	// 				// Convert strings to integer indices
	// 				face.vertices.push_back(std::stoi(vertexIndex) - 1); // OBJ indices are 1-based
	// 				if (!texCoordIndex.empty())
	// 					face.texCoords.push_back(std::stoi(texCoordIndex) - 1);
	// 				if (!normalIndex.empty())
	// 					face.normals.push_back(std::stoi(normalIndex) - 1);
	// 			}
	// 			faces.push_back(face);
	// 		}
	// 	}

	// 	file.close();
	// }
} // namespace Lys