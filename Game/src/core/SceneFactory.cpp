#include "SceneFactory.h"
std::shared_ptr<Scene> SceneFactory::CreateScene(const SceneData& data, const nlohmann::json& scene_json)
{
    std::cout << "Creating scene: " << data.display_name_ << std::endl;
    std::cout << "Scene ID: " << data.id_ << std::endl;
    std::cout << "Scene State: " << data.state_ << std::endl;

    switch (data.state_)
    {
    case MAIN_MENU:
        std::cout << "Would create MainMenuScene\n";
        break;
    case PLAYING:
        std::cout << "Would create GameplayScene\n";
        break;
    default:
        break;
    }

    return nullptr;
}