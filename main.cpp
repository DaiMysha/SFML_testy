
#include <SFML/Graphics.hpp>

int main(int argc, char** argv) {

    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML testy");
    sf::CircleShape shape(15.f);
    shape.setFillColor(sf::Color::Blue);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
