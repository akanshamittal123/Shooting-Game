#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include "MyWindow.h"

using namespace sf;
using namespace std;

class Player {

    CircleShape body;
    Vector2f playerCenter;
    int lives = 0;
    RectangleShape livesBar;

public:

    Player(RenderWindow& window);

    void update(RenderWindow& window);

    void draw(RenderWindow& window);

    Vector2f getPlayerCenter();

    int getLives();

    void decreaseLive();
};

#endif