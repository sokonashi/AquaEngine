#ifndef AQUAGL_MODEL_H
#define AQUAGL_MODEL_H

#include <iostream>
#include <string>
#include <vector>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <graphics/Mesh.h>
#include <graphics/Texture.h>

class Model {
private:
	std::vector<Mesh> Meshes;

	void ProcessNode(aiNode* Node, const aiScene* Scene);
	Mesh ProcessMesh(aiMesh* mesh);

	bool MeshFail;
public:
	Model(const std::string& FilePath);
	~Model();

	void Render();

	std::string FilePath;
	uint32_t MeshCount;
};

#endif
