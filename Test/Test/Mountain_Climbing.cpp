//#include<iostream>
//#include"SFML/Graphics.hpp"
//#include"SFML/Window.hpp"
//
//using namespace sf;
//
//void update(RenderWindow& window);
//void draw(RenderWindow& window);
//void collision(RectangleShape &rock);
//
//CircleShape player(20.f);
//RectangleShape rock1(Vector2f(20.f, 20.f));
//RectangleShape rock2(Vector2f(20.f, 20.f));
//RectangleShape rock3(Vector2f(20.f, 20.f));
////std::vector<sf::RectangleShape> rocks[10];
//
//int main()
//{
//    RenderWindow window(VideoMode(700, 700), "SFML works!");
//    window.setFramerateLimit(60);
//    
//    player.setFillColor(sf::Color::Green);
//    rock1.setFillColor(sf::Color::Red);
//    rock2.setFillColor(sf::Color::Black);
//    rock3.setFillColor(sf::Color::Blue);
//
//    //player.setPosition(Vector2f(window.getSize().x/2, window.getSize().y/ 2);
//
//    int pos[3][2];
//    for (int i = 0; i < 3; i++) {
//        pos[i][0] = std::rand() % window.getSize().x;
//        pos[i][1] = std::rand() % window.getSize().y;
//    }
//
//    player.setPosition(350.f, 350.f);
//    rock1.setPosition(pos[0][0], pos[0][1]);
//    rock2.setPosition(pos[1][0], pos[1][1]);
//    rock3.setPosition(pos[2][0], pos[2][1]);
//
//
//    while (window.isOpen())
//    {
//        Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == Event::Closed)
//                window.close();
//        }
//
//        update(window);
//
//        window.clear(Color(139, 69, 19, 200));
//
//        draw(window);
//        
//        window.display();
//    }
//
//    return 0;
//}
//
//void update(RenderWindow& window) {
//    if(Keyboard::isKeyPressed(Keyboard::A) && player.getPosition().x > 0) {
//        player.move((float)-5.f, (float)0.f);
//    }
//    if (Keyboard::isKeyPressed(Keyboard::D) && player.getPosition().x + (float)40.f < window.getSize().x) {
//        player.move((float)5.f, (float)0.f);
//    }
//    if (Keyboard::isKeyPressed(Keyboard::W) && player.getPosition().y > 0) {
//        player.move((float)0.f, (float)-5.f);
//    }
//    if (Keyboard::isKeyPressed(Keyboard::S) && player.getPosition().y + (float)40.f < window.getSize().y) {
//        player.move((float)0.f, (float)5.f);
//    }
//    if (Keyboard::isKeyPressed(Keyboard::R)) {
//        player.rotate((float)180.f);
//    }
//
//    FloatRect rectBounds1 = rock1.getGlobalBounds();
//    FloatRect rectBounds2 = rock2.getGlobalBounds();
//    FloatRect rectBounds3 = rock3.getGlobalBounds();
//
//    Vector2f playerPos = player.getPosition();
//    float radius = player.getRadius();
//
//    if (rectBounds1.intersects(sf::FloatRect(playerPos.x - radius, playerPos.y - radius, radius * 2, radius * 2)))
//    {
//        collision(rock1);
//    }
//
//    if (rectBounds2.intersects(sf::FloatRect(playerPos.x - radius, playerPos.y - radius, radius * 2, radius * 2)))
//    {
//        collision(rock2);
//    }
//
//    if (rectBounds3.intersects(sf::FloatRect(playerPos.x - radius, playerPos.y - radius, radius * 2, radius * 2)))
//    {
//        collision(rock3);
//    }
//
//}
//
//void collision(RectangleShape &rock){
//    Vector2f playerPos = player.getPosition();
//    float radius = player.getRadius();
//    float rectX = rock.getPosition().x;
//    float rectWidth = rock.getSize().x;
//    float circleX = playerPos.x;
//    float distX = std::abs(circleX - rectX - rectWidth / (float)2.f);
//    float overlapX = radius - distX;
//
//    if (circleX < rectX + rectWidth / (float)2.f)
//    {
//        player.move(-overlapX, (float)0.f);
//    }
//    else
//    {
//        player.move(overlapX, (float)0.f);
//    }
//}
//
//void draw(RenderWindow& window) {
//    //window.draw(rocks[0]);
//    window.draw(player);
//    window.draw(rock1);
//    window.draw(rock2);
//    window.draw(rock3);
//}
//
//
