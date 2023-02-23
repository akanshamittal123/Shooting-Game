//#include<iostream>
//#include"SFML/Window.hpp"
//#include "SFML/Graphics.hpp"
//#include<vector>
//#include<cstdlib>
//
//using namespace sf;
//using namespace std;
//
//RenderWindow window(VideoMode(800, 800), "Shooting game");
//
//CircleShape createCircle(float radius, Color color, float x, float y);
//
//class Player {
//public:
//
//    CircleShape body;
//    Vector2f playerCenter;
//    int shootTimer = 0, lives = 0;
//    RectangleShape livesBar;
//
//    Player() {
//        body = createCircle(50.f, Color::Blue, Mouse::getPosition(window).x, window.getSize().y - 2 * body.getRadius() - 5.f);
//        /*body.setRadius(50.f);
//        body.setFillColor(Color::Blue);*/
//
//        lives = 10;
//
//        livesBar.setPosition(window.getSize().x - 15.f * 10.f, 10.f);
//        livesBar.setSize(Vector2f(lives * 10.f, 10.f));
//        livesBar.setFillColor(Color::Green);
//    }
//
//    void update() {
//        playerCenter = Vector2f(body.getPosition().x + body.getRadius(), body.getPosition().y + body.getRadius());
//
//        if (Mouse::getPosition(window).x > 0 && Mouse::getPosition(window).x + 2 * body.getRadius() < window.getSize().x)
//            body.setPosition(Mouse::getPosition(window).x, window.getSize().y - 2 * body.getRadius() - 5.f);
//
//        livesBar.setSize(Vector2f(lives * 10.f, 10.f));
//    }
//};
//
//class Projectile {
//public:
//
//    CircleShape projectile;
//    vector<CircleShape> projectiles;
//
//    Projectile() {
//        projectile.setRadius(8.f);
//        projectile.setFillColor(Color::Red);
//        projectiles.push_back(projectile);
//    }
//
//    void update(Player& player) {
//        if (player.shootTimer < 5)
//            player.shootTimer++;
//
//        if (Mouse::isButtonPressed(Mouse::Left) && player.shootTimer >= 5) //Shoot
//        {
//            projectile.setPosition(player.playerCenter);
//            projectiles.push_back(projectile);
//
//            player.shootTimer = 0;
//        }
//
//        for (size_t i = 0; i < projectiles.size(); i++)
//        {
//            projectiles[i].move(0.f, -10.f);
//
//            if (projectiles[i].getPosition().y <= 10) {
//                projectiles.erase(projectiles.begin() + i);
//            }
//        }
//    }
//};
//
//
//class Enemy {
//public:
//    vector<RectangleShape> enemies;
//    RectangleShape enemy;
//    int enemySpawnTimer = 0;
//
//    Enemy() {
//        enemy.setSize(Vector2f(50.f, 50.f));
//        enemy.setFillColor(Color::Yellow);
//        enemies.push_back(enemy);
//    }
//
//    void update(Player& player) {
//        if (enemySpawnTimer < 20)
//            enemySpawnTimer++;
//
//        if (enemySpawnTimer >= 20)
//        {
//            enemy.setPosition(std::rand() % int(window.getSize().x - enemy.getSize().x), 0.f);
//            enemies.push_back(enemy);
//
//            enemySpawnTimer = 0;
//        }
//
//        for (size_t i = 0; i < enemies.size(); i++)
//        {
//            enemies[i].move(0.f, 5.f);
//            
//            if (enemies[i].getPosition().y > window.getSize().y - 20) {
//                
//                enemies.erase(enemies.begin() + i);
//
//                player.lives--;
//                cout << "lives = " << player.lives << endl;
//                
//                if (player.lives <= 0)
//                    window.close();
//            }
//        }
//    }
//};
//
////To make blocks disappear after they are shot by player
//void collision(Projectile& projectile, Enemy& enemy) {
//
//    for (size_t i = 0; i < projectile.projectiles.size(); i++)
//    {
//        for (size_t j = 0; j < enemy.enemies.size(); j++)
//        {
//            if (projectile.projectiles[i].getGlobalBounds().intersects(enemy.enemies[j].getGlobalBounds())) {
//
//                projectile.projectiles.erase(projectile.projectiles.begin() + i);
//
//                enemy.enemies.erase(enemy.enemies.begin() + j);
//
//                break;
//            }
//        }
//    }
//}
//
//
//int main()
//{
//    srand(time(NULL));
//
//    window.setFramerateLimit(60);
//
//    Player player;
//
//    Projectile projectile;
//
//    Enemy enemy;
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == Event::Closed)
//                window.close();
//        }
//
//        //UPDATE
//
//        player.update();
//        projectile.update(player);
//        enemy.update(player);
//
//        //COLLISION
//        collision(projectile, enemy);
//
//
//        //DRAW
//        window.clear();
//
//        window.draw(player.body);
//
//        for (size_t i = 0; i < enemy.enemies.size(); i++)
//            window.draw(enemy.enemies[i]);
//
//        for (size_t i = 0; i < projectile.projectiles.size(); i++)
//            window.draw(projectile.projectiles[i]);
//
//        window.draw(player.livesBar);
//
//        window.display();
//    }
//
//    return 0;
//}
//
//CircleShape createCircle(float radius = 10.f, Color color = Color::Black, float x = 0.f, float y = 0.f) {
//    CircleShape circle(radius); 
//    circle.setFillColor(color); 
//    circle.setPosition(Vector2f(x, y)); 
//    return circle;   
//} 