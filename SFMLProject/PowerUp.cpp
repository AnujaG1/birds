#include "PowerUp.h"
#include<iostream>

PowerUp::PowerUp() : active(true)  {
     if (!texture.loadFromFile("assets/corn.png"))  {
        std::cerr <<"Error: Could not load powerup texture!" <<std::endl;
        active = false;
        }
        sprite.setTexture(texture);
        // sprite.setPosition(rand() % 800+200, rand() % 400+100);
        sprite.setScale(0.5f, 0.5f);
        sprite.setPosition(100,200);
      
}

void PowerUp::update(sf::Time dt) {
        sprite.move(-200 * dt.asSeconds(), 0);
        if (sprite.getPosition().x < -sprite.getGlobalBounds().width) {
            active = false;
        }
    }

    void PowerUp::render(sf::RenderWindow& window) {
        if(active) {
            window.draw(sprite);
        }
    }
    sf::FloatRect PowerUp::getBounds() const{
        return sprite.getGlobalBounds();
    }
    bool PowerUp::isActive() const{
        return active;
    }
    void PowerUp::deactivate() {
        active = false;
    }
void PowerUp::setPosition(float x, float y) 
{
    sprite.setPosition(x, y);
}
