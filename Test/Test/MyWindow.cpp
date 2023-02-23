#include"SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "MyWindow.h"

using namespace sf;

MyWindow::MyWindow()
{
    window.create(VideoMode(800, 800), "Shooting game");
    window.setFramerateLimit(60);
}