#include "SFML/Graphics.hpp"
#include "Player.h"
#include "MyWindow.h"

using namespace sf;
using namespace std;


Player::Player(RenderWindow &window) {
    body.setRadius(50.f);
    body.setFillColor(Color::Blue);

    lives = 10;

    livesBar.setPosition(window.getSize().x - 15.f * 10.f, 10.f);
    livesBar.setSize(Vector2f(lives * 10.f, 10.f));
    livesBar.setFillColor(Color::Green);
}

void Player::update(RenderWindow& window) {
    playerCenter = Vector2f(body.getPosition().x + body.getRadius(), body.getPosition().y + body.getRadius());

    if (Mouse::getPosition(window).x > 0 && Mouse::getPosition(window).x + 2 * body.getRadius() < window.getSize().x)
        body.setPosition(Mouse::getPosition(window).x, window.getSize().y - 2 * body.getRadius() - 5.f);

    livesBar.setSize(Vector2f(lives * 10.f, 10.f));
}

void Player::draw(RenderWindow& window) {
    window.draw(body);
    window.draw(livesBar);
}

Vector2f Player::getPlayerCenter() {
    return playerCenter;
}

int Player::getLives() {
    return lives;
}

void Player::decreaseLive() {
    lives--;
}
