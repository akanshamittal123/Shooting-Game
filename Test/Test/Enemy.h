#ifndef ENEMY_H
#define ENEMY_H

#include<iostream>
#include"SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include<vector>
#include<cstdlib>
#include "Player.h"

using namespace sf;


class Enemy {
    vector<RectangleShape> enemies;
    RectangleShape enemy;
    int enemySpawnTimer = 0;

public:

    Enemy();

    void update(Player& player, RenderWindow& window);

    void draw(RenderWindow& window);

    std::vector<RectangleShape> getEnemies();

    void erase(int i);
};

#endif
