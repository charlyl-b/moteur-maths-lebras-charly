#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <SFML/Graphics.hpp>
#include <string>

using ScreenPoint = std::pair<int, int>;
using WorldPoint = std::pair<double, double>;


class GameWindow
{
public:
    GameWindow();

    // Show window.
    // Input:
    //  * width: window width (pixels).
    //  * height: window height (pixels).
    //  * title: window title.
    // Output:
    //  * Nothing.
    void show(int width, int height, const std::string& title);

private:
    sf::RenderWindow _window;

    void processEvents();
    void render();

    ScreenPoint toScreen(const WorldPoint &point);

};

#endif

