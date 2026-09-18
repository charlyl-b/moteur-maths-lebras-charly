#include <GameWindow.h>

GameWindow::GameWindow()
{
}

void GameWindow::show(int width, int height, const std::string& title)
{
    _window.create(sf::VideoMode(width, height), title);

    while (_window.isOpen())
    {
        processEvents();
        render();
    }
}

void GameWindow::processEvents()
{
    sf::Event event;

    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            _window.close();

        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Left)
            {
                playerPosX -= 1;
            }
            else if (event.key.code == sf::Keyboard::Right)
            {
                playerPosX += 1;
            }
            else if (event.key.code == sf::Keyboard::Up)
            {
                playerPosY += 1;
            }
            else if (event.key.code == sf::Keyboard::Down)
            {
                playerPosY -= 1;
            }
        }
    }
}

void GameWindow::render()
{
    // Clear background with White color.
    _window.clear(sf::Color::White);

    // Draw player as a yellow circle.
    int radius = 10;

    sf::CircleShape circle(radius);
    circle.setFillColor(sf::Color::Yellow);
    //ScreenPoint pos = toScreen(WorldPoint(0, 0));
    //ScreenPoint pos = toScreen(WorldPoint(5, 0));
    //ScreenPoint pos = toScreen(WorldPoint(0, -5));
    ScreenPoint pos = toScreen(WorldPoint(playerPosX, playerPosY));
    circle.setPosition(pos.first - radius, pos.second - radius);

    _window.draw(circle);

#ifdef _DEBUG
    ScreenPoint center = toScreen(WorldPoint(0, 0));
    sf::RectangleShape x(sf::Vector2f(_window.getSize().x, 1));
    x.setPosition(0, center.second);
    x.setFillColor(sf::Color::Red);
    _window.draw(x);

    sf::RectangleShape y(sf::Vector2f( 1,_window.getSize().y));
    y.setPosition(center.first, 0);
    y.setFillColor(sf::Color::Green);
    _window.draw(y);
#endif

    _window.display();
}

ScreenPoint GameWindow::toScreen(const WorldPoint& point) {
    const unsigned int screenX = _window.getSize().x;
    const unsigned int screenY = _window.getSize().y;

    int X = screenX / 2 + (point.first * 30);
    int Y = screenY / 2 - (point.second * 30);

    return ScreenPoint(X, Y);
}

WorldPoint GameWindow::toPhysical(const ScreenPoint& point) {
    const unsigned int screenX = _window.getSize().x;
    const unsigned int screenY = _window.getSize().y;

    double x = (point.first -(screenX / 2)) / 30;
    double y = ((screenY / 2) - point.second) / 30;

    return WorldPoint(x, y);

}
