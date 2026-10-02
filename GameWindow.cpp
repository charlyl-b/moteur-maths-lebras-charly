#include <GameWindow.h>

GameWindow::GameWindow()
{
}

void GameWindow::show(int width, int height, const std::string& title)
{
    _window.create(sf::VideoMode(width, height), title);
    _window.setFramerateLimit(50);
    while (_window.isOpen())
    {
        previousPlayerPosX = playerPosX;
        previousPlayerPosY = playerPosY;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) playerPosX -= 0.2;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) playerPosX += 0.2;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))playerPosY += 0.2;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) playerPosY -= 0.2;
        render();
        processEvents();
    }
}

void GameWindow::processEvents()
{
    sf::Event event;

    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            _window.close();
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


    double dt = 1.0 / 50.0;
    double vx = (playerPosX - previousPlayerPosX) / dt;
    double vy = (playerPosY - previousPlayerPosY) / dt;

    static sf::Font font;
    static bool fontLoaded = font.loadFromFile("C:/Windows/Fonts/arial.ttf");

    if (fontLoaded)
    {
        sf::Text speedText;
        speedText.setFont(font);
        speedText.setCharacterSize(16);
        speedText.setFillColor(sf::Color::Black);
        speedText.setString("vx = " + std::to_string(vx) + " vy = " + std::to_string(vy));
        speedText.setPosition(10, 10);
        _window.draw(speedText);
    }

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
