#include "Bird.h"
#include "Windows.h"

Bird::Bird() :
        gravity(10),
        flap_speed(250),
        velocity_y(0),
        anim_counter(0),
        texture_switch(1),
        should_fly(false),
        invincible(false),
        lives(0)

{
  textures[0].loadFromFile("assets/birddown.png");
  textures[1].loadFromFile("assets/birdup.png");

  bird_sprite.setTexture(textures[0]);
  bird_sprite.setScale(SCALE_FACTOR, SCALE_FACTOR);
  resetBirdPosition();
}

void Bird::update(sf::Time & dt)
{
    if(bird_sprite.getGlobalBounds().top<545 && should_fly)
    {
        if(anim_counter == 5)
        {
            bird_sprite.setTexture(textures[texture_switch]);
            if(texture_switch) texture_switch =0;
            else  texture_switch =1;
            anim_counter =0;
        }
        anim_counter++;

        velocity_y += gravity * dt.asSeconds();
        bird_sprite.move(0,velocity_y);

        if(bird_sprite.getGlobalBounds().top < 0)
        
            bird_sprite.setPosition(100,0);

            // Handle invincibility duration
            if(invincible && invincibilityClock.getElapsedTime().asSeconds()>5) {
                invincible = false;
            }
        
    }
}

void Bird::flapBird(sf::Time& dt)
{
  velocity_y = -flap_speed * dt.asSeconds(); //Flap the bird up
}


void Bird::resetBirdPosition()
{
    bird_sprite.setPosition(100, 50);
    velocity_y =0;
    invincible = false;
    lives = 0;
}

float Bird::getRightBound()
{
    return bird_sprite.getGlobalBounds().left+bird_sprite.getGlobalBounds().width;
}

void Bird::setShouldFly(bool should_fly)
{
this->should_fly = should_fly;
}

bool Bird::isInvincible() const{
    return invincible;
}

void Bird::gainInvincibility(int lives)
{
    this->invincible = true;
    this->lives = lives;
    invincibilityClock.restart();
}

