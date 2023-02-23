#include"SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include<vector>
#include "Player.h"
#include "Projectile.h"
#include "Enemy.h"
#include "Collision.h"

using namespace sf;

//To make blocks disappear after they are shot by player
void collision(Projectile& projectile, Enemy& enemy) {

    for (size_t i = 0; i < projectile.getProjectiles().size(); i++)
    {
        for (size_t j = 0; j < enemy.getEnemies().size(); j++)
        {
            if (projectile.getProjectiles()[i].getGlobalBounds().intersects(enemy.getEnemies()[j].getGlobalBounds())) {

                projectile.erase(i);

                enemy.erase(j);

                break;
            }
        }
    }
}