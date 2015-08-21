#pragma once
#include "..\scene\scene.h"

#include "assimp/Importer.hpp"
#include "assimp/postprocess.h"
#include "assimp/scene.h"

#include "texture_importer.h"

class SceneImporter
{
    private:
        TextureImporter textureImporter;

    public:
        SceneImporter();
        virtual ~SceneImporter();
        bool Import(const std::string &sFilepath, Scene &outScene);
        // fine imports
        Material ImportMaterial(aiMaterial *mMaterial);
        Mesh ImportMesh(aiMesh *mMesh);
        void ProcessNodes(Scene &scene, aiNode* node, Node &newNode);
        void ImportMaterialTextures(Scene &scene, aiMaterial * mMaterial,
                                    Material &material);
};

