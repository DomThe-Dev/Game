/*  GAME
* - If including a library in a file, use <>, rather than "". "" only for own headers
*/

#include "managers/GameManager.h"
#include "utils/Common.h"

/// <summary>
/// Entry point of program. Keep it as simple as physically possible. Good in case I need to run tests, lets me isolate
/// this stuff.
/// </summary>
/// <returns>0 for success, 1 for error</returns>
int main() 
{
    try
    {
        GameManager game;
        game.Start();
    }
    catch (const std::exception& e) {
        std::cerr << "[ERROR] " << e.what() << std::endl;
        return 1;
    }
    return 0;
    /*auto file_logger = spdlog::basic_logger_mt("main_logger", "logs/game.log");

    sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "Game");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);
    file_logger->info("Game started!");
    file_logger->warn("Watch out for enemies!");
    file_logger->error("Something went wrong!");
    spdlog::info("Welcome to spdlog!");

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Clock deltaClock;
    while (window.isOpen()) {
        while (const auto event = window.pollEvent()) {
            ImGui::SFML::ProcessEvent(window, *event);

            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Hello, world!");
        ImGui::Button("Look at this pretty button");
        ImGui::End();

        window.clear();
        window.draw(shape);
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();*/
}