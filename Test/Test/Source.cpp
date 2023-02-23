//#include<iostream> 
//
//#include"SFML/Graphics.hpp" 
//
//#include"SFML/Window.hpp" 
//
//#include"SFML/System.hpp" 
//
//using namespace sf; 
//
//using namespace std; 
//
// 
//
//class Player { 
//
//public: 
//
//    CircleShape player; 
//
//    Player(RenderWindow& window) { //initializing the outlook of the player 
//
//        player.setFillColor(Color::White); 
//
//        player.setRadius(50.f); 
//
//        player.setPointCount(3); 
//
//        player.setPosition(window.getSize().x / 2 - player.getRadius(), window.getSize().y - player.getRadius() * 2 - 5.f); 
//
//    } 
//
//    void movement(RenderWindow& window) { //how the player will move 
//
//        if (Keyboard::isKeyPressed(Keyboard::A)) { 
//
//            if (player.getPosition().x > 0) { 
//
//                player.move(-5.f, 0); 
//
//            } 
//
//        } 
//
//        if (Keyboard::isKeyPressed(Keyboard::D)) { 
//
//            if (player.getPosition().x + player.getRadius() * 2 < window.getSize().x) { 
//
//                player.move(5.f, 0); 
//
//            } 
//
//        } 
//
//    } 
//
//    void draw(RenderWindow& window) { 
//
//        window.draw(player); 
//
//    } 
//
// 
//
//}; 
//
// 
//
//class Enemy { 
//
//public: 
//
//    CircleShape enemy; 
//
//    Vector2f moveDir; 
//
//    Enemy(RenderWindow& window) { //initializing the outlook of the player 
//
//        enemy.setFillColor(Color::White); 
//
//        enemy.setRadius(50.f); 
//
//        enemy.setPosition(window.getSize().x / 2 - enemy.getRadius(), 5.f); 
//
//        moveDir = { 3.f, 0.f }; 
//
//    } 
//
//    void movement(RenderWindow& window) { //how the player will move 
//
//        enemy.move(moveDir); 
//
//        if (enemy.getPosition().x < 0 || enemy.getPosition().x > window.getSize().x - 2*enemy.getRadius()-4.f) { 
//
//            moveDir.x = -moveDir.x; 
//
//        } 
//
//    } 
//
//    void draw(RenderWindow& window) { 
//
//        window.draw(enemy); 
//
//    } 
//
// 
//
//}; 
//
// 
//
//class BulletPlayer { 
//
//    CircleShape singleBullet; 
//
//    vector<CircleShape> bullets; 
//
//    int fire_Timer; 
//
//public: 
//
//    BulletPlayer() {//initializing the outlook of the bullet 
//
//        singleBullet.setRadius(5.f); 
//
//        singleBullet.setFillColor(Color::Red); 
//
//        fire_Timer = 0; 
//
//    } 
//
//    void accumulatebullets(Player& play) {//making a container of the bullets 
//
//        if (fire_Timer < 10) { 
//
//            fire_Timer++; 
//
//        } 
//
//        if (Mouse::isButtonPressed(Mouse::Left) && fire_Timer >= 10) { 
//
//            fire_Timer = 0; 
//
//            Vector2f player_top = { play.player.getPosition().x + play.player.getRadius(), play.player.getPosition().y }; 
//
//            singleBullet.setPosition(player_top); 
//
//            bullets.push_back(CircleShape(singleBullet)); 
//
//        } 
//
//    } 
//
//    void update() {//firing/movement of the bullets 
//
//        for (size_t i = 0; i < bullets.size(); i++) { 
//
//            bullets[i].move(0.f, -10.f); 
//
// 
//
//            if (bullets[i].getPosition().y <= 10) { 
//
//                bullets.erase(bullets.begin() + i); 
//
//            } 
//
//        } 
//
//    } 
//
//    vector<CircleShape> fetchBullets(BulletPlayer& currBullet) { 
//
//        return currBullet.bullets; 
//
//    } 
//
//    void draw(RenderWindow& window) { 
//
//        for (size_t i = 0; i < bullets.size(); i++) { 
//
//            window.draw(bullets[i]); 
//
//        } 
//
//    } 
//
//    void updatebullets(vector<CircleShape>& dummybullets) {//updating the bullets array after used 
//
//        bullets = dummybullets; 
//
//    } 
//
//}; 
//
// 
//
//class BulletEnemy { 
//
//    CircleShape singleBullet; 
//
//    vector<CircleShape> bullets; 
//
//    int fire_Timer; 
//
//public: 
//
//    BulletEnemy() {//initializing the outlook of the bullet 
//
//        singleBullet.setRadius(5.f); 
//
//        singleBullet.setFillColor(Color::Red); 
//
//        fire_Timer = 0; 
//
//    } 
//
//    void accumulatebullets(Enemy& play) {//making a container of the bullets 
//
//        if (fire_Timer < 30) { 
//
//            fire_Timer++; 
//
//        } 
//
//        if (fire_Timer >= 30) { 
//
//            fire_Timer = 0; 
//
//            Vector2f player_bottom = { play.enemy.getPosition().x + play.enemy.getRadius(), play.enemy.getPosition().y + play.enemy.getRadius()}; 
//
//            singleBullet.setPosition(player_bottom); 
//
//            bullets.push_back(CircleShape(singleBullet)); 
//
//        } 
//
//    } 
//
//    void update(RenderWindow &window) {//firing/movement of the bullets 
//
//        for (size_t i = 0; i < bullets.size(); i++) { 
//
//            bullets[i].move(0.f, 10.f); 
//
// 
//
//            if (bullets[i].getPosition().y > window.getSize().y - 5.f) { 
//
//                bullets.erase(bullets.begin() + i); 
//
//            } 
//
//        } 
//
//    } 
//
//    vector<CircleShape> fetchBullets(BulletEnemy& currBullet) { 
//
//        return currBullet.bullets; 
//
//    } 
//
//    void draw(RenderWindow& window) { 
//
//        for (size_t i = 0; i < bullets.size(); i++) { 
//
//            window.draw(bullets[i]); 
//
//        } 
//
//    } 
//
//    void updatebullets(vector<CircleShape>& dummybullets) {//updating the bullets array after used 
//
//        bullets = dummybullets; 
//
//    } 
//
//}; 
//
////Remeber the drawing starts from top left corner considering it as an origin 
//
//void collision(vector<CircleShape>& bPlayer, vector<CircleShape>& bEnemy, Player &player, Enemy &enemy, int &pLive, int &eLive) { 
//
//    for (size_t i = 0; i < bPlayer.size(); i++) { 
//
//        if (enemy.enemy.getGlobalBounds().intersects(bPlayer[i].getGlobalBounds())) { 
//
//            eLive--; 
//
//            bPlayer.erase(bPlayer.begin() + i); 
//
//        } 
//
//    } 
//
//    for (size_t i = 0; i < bEnemy.size(); i++) { 
//
//        if (player.player.getGlobalBounds().intersects(bEnemy[i].getGlobalBounds())) { 
//
//            pLive--; 
//
//            bEnemy.erase(bEnemy.begin() + i); 
//
//        } 
//
//    } 
//
// 
//
// 
//
//} 
//
// 
//
//void setAttributes(RectangleShape& currElement) { 
//
//    currElement.setFillColor(Color::Red); 
//
//    currElement.setSize(Vector2f(10.f * 20.f, 20.f)); 
//
//} 
//
//int main() 
//
//{ 
//
//    //in renderWindow we can even select the style, size.. 
//
//    RenderWindow window(VideoMode(800, 600), "SFML works!", Style::Default); 
//
// 
//
// 
//
//    //to avoid the frame rate to shoot up extremely we can set the frame rate to an extend 
//
//    window.setFramerateLimit(60); 
//
// 
//
//    //Player 
//
//    Player player(window); 
//
// 
//
//    //Enemy 
//
//    Enemy enemy(window); 
//
// 
//
//    //Player Bullets 
//
//    BulletPlayer bulletPlayer; 
//
// 
//
//    //Enemy bullet 
//
//    BulletEnemy bulletEnemy; 
//
// 
//
// 
//
//    //lives 
//
//    int playerLive = 10; 
//
//    int enemyLive = 10; 
//
//    RectangleShape hpBarPlayer; 
//
//    RectangleShape hpBarEnemy; 
//
//    setAttributes(hpBarPlayer); 
//
//    setAttributes(hpBarEnemy); 
//
//    hpBarEnemy.setPosition(window.getSize().x - hpBarEnemy.getSize().x - 2.f, window.getSize().y / 2);  
//
//    hpBarPlayer.setPosition(window.getSize().x - hpBarPlayer.getSize().x - 2.f,window.getSize().y / 2 + hpBarPlayer.getSize().y+0.5f); 
//
// 
//
// 
//
//    while (window.isOpen() && playerLive >0 && enemyLive > 0) 
//
//    { 
//
//        Event event; 
//
//        while (window.pollEvent(event)) 
//
//        { 
//
//            if (event.type == Event::Closed) 
//
//                window.close(); 
//
//        } 
//
// 
//
//        //Update 
//
//        player.movement(window); 
//
//        enemy.movement(window); 
//
// 
//
//        bulletPlayer.accumulatebullets(player); 
//
//        bulletPlayer.update(); 
//
// 
//
//        bulletEnemy.accumulatebullets(enemy); 
//
//        bulletEnemy.update(window); 
//
// 
//
//        //Collision 
//
//        vector<CircleShape>bPlayer = bulletPlayer.fetchBullets(bulletPlayer); 
//
//        vector<CircleShape>bEnemy = bulletEnemy.fetchBullets(bulletEnemy); 
//
// 
//
//        collision(bPlayer, bEnemy, player, enemy, playerLive, enemyLive); 
//
//        bulletPlayer.updatebullets(bPlayer); 
//
//        bulletEnemy.updatebullets(bEnemy); 
//
// 
//
//        hpBarPlayer.setSize(Vector2f{ 20.f * (float)playerLive, 20.f }); 
//
//        hpBarEnemy.setSize(Vector2f{ 20.f * (float)enemyLive, 20.f }); 
//
// 
//
//        window.clear(); 
//
// 
//
//        // to draw 
//
//        player.draw(window); 
//
//        bulletPlayer.draw(window); 
//
//        bulletEnemy.draw(window); 
//
//        enemy.draw(window); 
//
//        window.draw(hpBarEnemy); 
//
//        window.draw(hpBarPlayer); 
//
// 
//
//        window.display(); 
//
//    } 
//
// 
//
//    return 0; 
//
//} 