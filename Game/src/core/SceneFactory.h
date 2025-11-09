#pragma once
#include <memory>
#include <iostream>
#include <json.hpp>
#include "../core/Scene.h"

class SceneFactory
{
public:
	static std::shared_ptr<Scene> CreateScene(const SceneData& data, const nlohmann::json& scene_json);
private:

};

