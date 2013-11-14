// Implementation file for upgradeButton.hpp

#include"upgradeButton.hpp"
#include<iostream>

upgradeButton::upgradeButton(std::shared_ptr<sf::Texture> texture, gameScreen* screen) : gameObject(texture, screen) {

    highlightedSprite.setTexture(*texture);
    highlightedSprite.setColor(sf::Color(255,255,255,100));
    highlightedSprite.setPosition(sf::Vector2f(23*32,1*32));
    highlightedSprite.setTextureRect(sf::IntRect(10*32,2*32,4*32,1*32));
}


void upgradeButton::draw(sf::RenderTarget& target , sf::RenderStates states) const{
    if (isHighlighted && !isClicked) {target.draw(highlightedSprite);}
}
