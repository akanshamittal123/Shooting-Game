#include<iostream>
#include"SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include<vector>
#include<cstdlib>
#include "Player.h"
#include "Enemy.h"

using namespace sf;


Enemy::Enemy() {
    enemy.setSize(Vector2f(50.f, 50.f));
    enemy.setFillColor(Color::Yellow);
    enemies.push_back(enemy);
}

void Enemy::update(Player& player, RenderWindow& window) {
    if (enemySpawnTimer < 20)
        enemySpawnTimer++;

    if (enemySpawnTimer >= 20)
    {
        enemy.setPosition(std::rand() % int(window.getSize().x - enemy.getSize().x), 0.f);
        enemies.push_back(enemy);

        enemySpawnTimer = 0;
    }

    for (size_t i = 0; i < enemies.size(); i++)
    {
        enemies[i].move(0.f, 5.f);

        if (enemies[i].getPosition().y > window.getSize().y - 20) {

            enemies.erase(enemies.begin() + i);

            player.decreaseLive();
            std::cout << "lives = " << player.getLives() << endl;

            if (player.getLives() <= 0)
                window.close();
        }
    }
}

void Enemy::draw(RenderWindow& window) {
    for (size_t i = 0; i < enemies.size(); i++)
        window.draw(enemies[i]);
}

std::vector<RectangleShape> Enemy::getEnemies() {
    return enemies;
}

void Enemy::erase(int i) {
    enemies.erase(enemies.begin() + i);
}
