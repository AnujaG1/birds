#ifndef POWERUP_H
#define POWERUP_H

#include<SFML/Graphics.hpp>


class PowerUp {

    public:
    PowerUp() ;

    void update(sf::Time dt);
    void render(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
    bool isActive() const;
    void deactivate();
    void setPosition(float x, float y);

  
    private:
    sf::Texture texture;
    sf::Sprite sprite; 
    bool active ;
};
#endif