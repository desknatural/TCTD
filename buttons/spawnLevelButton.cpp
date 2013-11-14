// Implementation file for spawnLevelButton.hpp

#include"spawnLevelButton.hpp"
#include<iostream>

spawnLevelButton::spawnLevelButton(std::shared_ptr<sf::Texture> texture, gameScreen* screen) : gameObject(texture, screen) {

    highlightedSprite.setTexture(*texture);
    highlightedSprite.setColor(sf::Color(255,255,255,100));
    highlightedSprite.setPosition(sf::Vector2f(16*32+ 8, 17*32+ 16));
    highlightedSprite.setTextureRect(sf::IntRect(10*32,2*32,2*32 + 16,2*32 + 8));
}

void spawnLevelButton::draw(sf::RenderTarget& target , sf::RenderStates states) const{
    if (isHighlighted && !isClicked) {target.draw(highlightedSprite);}
}
