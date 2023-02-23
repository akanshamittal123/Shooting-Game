#include"SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include<vector>
#include "Projectile.h"

using namespace sf;


Projectile::Projectile() {
    projectile.setRadius(8.f);
    projectile.setFillColor(Color::Red);
    projectiles.push_back(projectile);
}

void Projectile::update(Player& player) {
    if (shootTimer < 5)
        shootTimer++;

    if (Mouse::isButtonPressed(Mouse::Left) && shootTimer >= 5) //Shoot
    {
        projectile.setPosition(player.getPlayerCenter());
        projectiles.push_back(projectile);

        shootTimer = 0;
    }

    for (size_t i = 0; i < projectiles.size(); i++)
    {
        projectiles[i].move(0.f, -10.f);

        if (projectiles[i].getPosition().y <= 10) {
            projectiles.erase(projectiles.begin() + i);
        }
    }
}

void Projectile::draw(RenderWindow& window) {
    for (size_t i = 0; i < projectiles.size(); i++)
        window.draw(projectiles[i]);
}

vector<CircleShape> Projectile::getProjectiles() {
    return projectiles;
}

void Projectile::erase(int i) {
    projectiles.erase(projectiles.begin() + i);
}