#ifndef COLLISION_H
#define COLLISION_H

#include"SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include<vector>
#include "Player.h"
#include "Projectile.h"
#include "Enemy.h"

using namespace sf;

//To make blocks disappear after they are shot by player
void collision(Projectile& projectile, Enemy& enemy);

#endif