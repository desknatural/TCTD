// Implementation file for helpButton.hpp

#include"helpButton.hpp"
#include<iostream>

helpButton::helpButton(std::shared_ptr<sf::Texture> texture, gameScreen* screen) : gameObject(texture, screen) {

    highlightedSprite.setTexture(*texture);
    highlightedSprite.setColor(sf::Color(255,255,255,100));
    highlightedSprite.setPosition(sf::Vector2f(25*32,0));
    highlightedSprite.setTextureRect(sf::IntRect(10*32,2*32,3*32,1*32));
}


void helpButton::draw(sf::RenderTarget& target , sf::RenderStates states) const{
    if (isHighlighted && !isClicked) {target.draw(highlightedSprite);}
}
