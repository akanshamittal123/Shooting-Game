#ifndef PROJECTILE_H
#define PROJECTILE_H

#include"SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include<vector>
#include "Player.h"

using namespace sf;

class Projectile {

    CircleShape projectile;
    vector<CircleShape> projectiles;
    int shootTimer = 0;

public:

    Projectile();

    void update(Player& player);

    void draw(RenderWindow& window);

    vector<CircleShape> getProjectiles();

    void erase(int i);
};

#endif