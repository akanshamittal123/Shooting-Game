//#include<iostream>  
//
//
//
//#include"SFML/Window.hpp"  
//
//
//
//#include "SFML/Graphics.hpp"  
//
//
//
//#include<vector>  
//
//
//
//#include<cstdlib>  
//
//
//
//
//
//
//
//using namespace sf;
//
//
//
//using namespace std;
//
//
//
//
//
//
//
////CircleShape createCircle(float radius, Color color, float x, float y); 
//
//
//
//
//
//
//
//RenderWindow window(VideoMode(800, 800), "Shooting game");
//
//
//
//
//
//
//
//class Player {
//
//
//
//public:
//
//
//
//
//
//
//
//    CircleShape body;
//
//
//
//    Vector2f playerCenter;
//
//
//
//    int shootTimer = 0;
//
//
//
//
//
//
//
//    Player() {
//
//
//
//        body.setFillColor(Color::Blue);
//
//
//
//        body.setRadius(50.f);
//
//
//
//    }
//
//
//
//
//
//
//
//    void update() {
//
//
//
//        playerCenter = Vector2f(body.getPosition().x + body.getRadius(), body.getPosition().y + body.getRadius());
//
//
//
//        body.setPosition(Mouse::getPosition(window).x, window.getSize().y - 2 * body.getRadius() - 5.f);
//
//
//
//    }
//
//
//
//};
//
//
//
//
//
//
//
//class Projectile {
//
//
//
//
//
//
//
//    CircleShape projectile;
//
//
//
//    vector<CircleShape> projectiles;
//
//
//
//public:
//
//
//
//    Projectile(Player player) {
//
//
//
//        projectile.setRadius(2.f);
//
//        projectile.setFillColor(Color::Red);
//
//
//
//        projectiles.push_back(projectile);
//
//
//
//    }
//
//
//
//
//
//
//
//    void update(Player player) {
//
//
//
//        if (player.shootTimer < 5)
//
//
//
//            player.shootTimer++;
//
//
//
//
//
//
//
//        if (Mouse::isButtonPressed(Mouse::Left) && player.shootTimer >= 5) //Shoot  
//
//
//
//        {
//
//
//
//            projectile.setPosition(player.playerCenter);
//
//
//
//            projectiles.push_back(projectile);
//
//
//
//
//
//
//
//            player.shootTimer = 0;
//
//
//
//        }
//
//
//
//
//
//
//
//        for (size_t i = 0; i < projectiles.size(); i++)
//
//
//
//        {
//
//
//
//            projectiles[i].move(0.f, -10.f);
//
//
//
//
//
//
//
//            if (projectiles[i].getPosition().y <= 10)
//
//
//
//                projectiles.erase(projectiles.begin() + i);
//
//
//
//        }
//
//
//
//    }
//
//
//
//};
//
//
//
//
//
//
//
////   
//
//
//
////class Enemy {  
//
//
//
////  
//
//
//
////};  
//
//
//
////  
//
//
//
//
//
//
//
//
//
//
//
//int main()
//
//
//
//{
//
//
//
//    srand(time(NULL));
//
//
//
//
//
//
//
//    window.setFramerateLimit(60);
//
//
//
//
//
//
//
//    Player player;
//
//
//
//    //BulletPlayer a;  
//
//
//
//
//
//
//
//    /*CircleShape player = createCircle(50.f, Color::Green, float(window.getSize().x) / 2 - 50.f, window.getSize().y - 50.f * 2 - 20.f);
//
//
//
//    Vector2f playerCenter;
//
//
//
//    int shootTimer = 0;*/
//
//
//
//
//
//
//
//    //Projectile _projectile(player);  
//
//
//
//
//
//
//
//    std::vector<CircleShape> projectiles;
//
//
//
//    CircleShape projectile;
//
//    projectile.setRadius(5.f);
//
//
//
//    //CircleShape projectile(5.f);  
//
//
//
//    //projectile.setRadius(5.f);  
//
//
//
//    projectiles.push_back(projectile);
//
//
//
//
//
//
//
//    std::vector<RectangleShape> enemies;
//
//
//
//    RectangleShape enemy(Vector2f(50.f, 50.f));
//
//
//
//    enemy.setFillColor(Color::Yellow);
//
//
//
//    enemies.push_back(enemy);
//
//
//
//    int enemySpawnTimer = 0;
//
//
//
//
//
//
//
//    while (window.isOpen())
//
//
//
//    {
//
//
//
//        sf::Event event;
//
//
//
//        while (window.pollEvent(event))
//
//
//
//        {
//
//
//
//            if (event.type == Event::Closed)
//
//
//
//                window.close();
//
//
//
//        }
//
//
//
//
//
//
//
//        //UPDATE  
//
//
//
//
//
//
//
//        //PLAYER  
//
//
//
//        //player.playerCenter = Vector2f(player.body.getPosition().x + player.body.getRadius(), player.body.getPosition().y + player.body.getRadius());  
//
//
//
//
//
//
//
//        //player.body.setPosition(Mouse::getPosition(window).x, player.body.getPosition().y);  
//
//
//
//        player.update();
//
//
//
//
//
//
//
//        //PROJECTILES  
//
//
//
//        //if (player.shootTimer < 5)  
//
//
//
//        //    player.shootTimer++;  
//
//
//
//
//
//
//
//        //if (Mouse::isButtonPressed(Mouse::Left) && player.shootTimer >= 5) //Shoot  
//
//
//
//        //{  
//
//
//
//        //    projectile.projectile.setPosition(player.playerCenter);  
//
//
//
//        //    projectile.projectiles.push_back(projectile.projectile);  
//
//
//
//
//
//
//
//        //    player.shootTimer = 0;  
//
//
//
//        //}  
//
//
//
//
//
//
//
//        //for (size_t i = 0; i < projectile.projectiles.size(); i++)  
//
//
//
//        //{  
//
//
//
//        //    projectile.projectiles[i].move(0.f, -10.f);  
//
//
//
//
//
//
//
//        //    if (projectile.projectiles[i].getPosition().y <= 10)  
//
//
//
//        //        projectile.projectiles.erase(projectile.projectiles.begin() + i);  
//
//
//
//        //}  
//
//
//
//
//
//
//
//        if (player.shootTimer < 5)
//
//
//
//            player.shootTimer++;
//
//
//
//
//
//
//
//        if (Mouse::isButtonPressed(Mouse::Left) && player.shootTimer >= 5) //Shoot  
//
//
//
//        {
//
//
//
//            projectile.setPosition(player.playerCenter);
//
//
//
//            projectiles.push_back(projectile);
//
//
//
//
//
//
//
//            player.shootTimer = 0;
//
//
//
//        }
//
//
//
//
//
//
//
//        for (size_t i = 0; i < projectiles.size(); i++)
//
//
//
//        {
//
//
//
//            projectiles[i].move(0.f, -10.f);
//
//
//
//
//
//
//
//            if (projectiles[i].getPosition().y <= 10)
//
//
//
//                projectiles.erase(projectiles.begin() + i);
//
//
//
//        }
//
//
//
//        //_projectile.update(player);  
//
//
//
//
//
//
//
//        //ENEMIES  
//
//
//
//        if (enemySpawnTimer < 20)
//
//
//
//            enemySpawnTimer++;
//
//
//
//
//
//
//
//        if (enemySpawnTimer >= 20)
//
//
//
//        {
//
//
//
//            enemy.setPosition(std::rand() % int(window.getSize().x - enemy.getSize().x), 0.f);
//
//
//
//            enemies.push_back(enemy);
//
//
//
//
//
//
//
//            enemySpawnTimer = 0;
//
//
//
//        }
//
//
//
//
//
//
//
//        for (size_t i = 0; i < enemies.size(); i++)
//
//
//
//        {
//
//
//
//            enemies[i].move(0.f, 5.f);
//
//
//
//            if (enemies[i].getPosition().y > window.getSize().y - 20) {
//
//
//
//                enemies.erase(enemies.begin() + i);
//
//
//
//            }
//
//
//
//        }
//
//
//
//
//
//
//
//        //COLLISION  
//
//
//
//        for (size_t i = 0; i < projectiles.size(); i++)
//
//
//
//        {
//
//
//
//            for (size_t j = 0; j < enemies.size(); j++)
//
//
//
//            {
//
//
//
//                if (projectiles[i].getGlobalBounds().intersects(enemies[j].getGlobalBounds())) {
//
//
//
//                    projectiles.erase(projectiles.begin() + i);
//
//
//
//                    enemies.erase(enemies.begin() + j);
//
//
//
//                    break;
//
//
//
//                }
//
//
//
//            }
//
//
//
//        }
//
//
//
//
//
//
//
//
//
//
//
//        //DRAW  
//
//
//
//        window.clear();
//
//
//
//
//
//
//
//        window.draw(player.body);
//
//
//
//
//
//
//
//        for (size_t i = 0; i < enemies.size(); i++)
//
//
//
//            window.draw(enemies[i]);
//
//
//
//
//
//
//
//        for (size_t i = 0; i < projectiles.size(); i++)
//
//
//
//            window.draw(projectiles[i]);
//
//
//
//
//
//
//
//
//
//
//
//        window.display();
//
//
//
//    }
//
//
//
//
//
//
//
//    return 0;
//
//
//
//}
//
//
//
//
//
//
//
////CircleShape createCircle(float radius = 10.f, Color color = Color::Black, float x = 0.f, float y = 0.f) { 
//
//// 
//
////    CircleShape circle(radius); 
//
//// 
//
////    circle.setFillColor(color); 
//
//// 
//
////    circle.setPosition(Vector2f(x, y)); 
//
//// 
//
////    return circle; 
//
//// 
//
////} 