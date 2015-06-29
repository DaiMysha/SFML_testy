#include <iostream>

#include <SFML/Graphics.hpp>
#include <GL/gl.h>

#include "Player.hpp"

#define WIDTH   640
#define HEIGHT  480

int main(int argc, char** argv) {

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML testy");
    sf::CircleShape shape(12.f);
    shape.setFillColor(sf::Color::Blue);

    //bg
    sf::Texture bg;
    if(!bg.loadFromFile("data/map.png")) exit(-1);
    //bg.setRepeated(true);
    sf::Sprite bgSpr(bg);
    bgSpr.setTextureRect(sf::IntRect(0,0,WIDTH,HEIGHT));

    Player p(1670,2088,2);
    shape.setPosition(WIDTH/2-2,HEIGHT/2-2);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            else if(event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
                bool down = (event.type == sf::Event::KeyPressed);
                switch(event.key.code) {
                    case sf::Keyboard::Up: p.set_keyDown(Player::KEY_UP, down); break;
                    case sf::Keyboard::Down: p.set_keyDown(Player::KEY_DOWN, down); break;
                    case sf::Keyboard::Left: p.set_keyDown(Player::KEY_LEFT, down); break;
                    case sf::Keyboard::Right: p.set_keyDown(Player::KEY_RIGHT, down); break;
                    case sf::Keyboard::Escape: window.close(); break;
                    default: break;
                }
            }
        }

        p.move();
        //calculates where the sprite has to be blit
        int x = p.get_x() - WIDTH/2;
        int y = p.get_y() - HEIGHT/2;
        bgSpr.setTextureRect(sf::IntRect(x,y,x+WIDTH,y+WIDTH));
        //draw
        window.clear();
        window.draw(bgSpr);
        window.draw(shape);

        window.display();

        sf::sleep(sf::milliseconds(16));
    }

    return 0;
}
