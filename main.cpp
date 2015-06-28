#include <iostream>

#include <SFML/Graphics.hpp>

#include "Player.hpp"

int main(int argc, char** argv) {

    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML testy");
    sf::CircleShape shape(15.f);
    shape.setFillColor(sf::Color::Blue);

    Player p(640/2,480/2,5);

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
        shape.setPosition(p.get_x(),p.get_y());
        //draw
        window.clear();
        window.draw(shape);
        window.display();

        sf::sleep(sf::milliseconds(16));
    }

    return 0;
}
