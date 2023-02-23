#include<iostream>
#include"SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include<vector>
#include<cstdlib>
#include "Player.h"
#include "Projectile.h"
#include "Enemy.h"
#include "Collision.h"

using namespace sf;
using namespace std;


int main()
{
    srand(time(NULL));

    MyWindow _window;

    Player player(_window.window);

    Projectile projectile;

    Enemy enemy;

    while (_window.window.isOpen())
    {
        sf::Event event;
        while (_window.window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                _window.window.close();
        }

        //UPDATE

        player.update(_window.window);
        projectile.update(player);
        enemy.update(player, _window.window);

        //COLLISION
        collision(projectile, enemy);


        //DRAW
        _window.window.clear();

        player.draw(_window.window);
        enemy.draw(_window.window);
        projectile.draw(_window.window);

        _window.window.display();
    }

    return 0;
}