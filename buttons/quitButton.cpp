// Implementation file for quitButton.hpp

#include"quitButton.hpp"
#include<iostream>

void quitButton::_selected(){ screen->shouldClose = true; }

quitButton::quitButton(std::shared_ptr<sf::Texture> texture, gameScreen* screen) : gameObject(texture, screen) {

    highlightedSprite.setTexture(*texture);
    //clickedSprite.setTexture(*texture);

    highlightedSprite.setColor(sf::Color(255,255,255,100));

    highlightedSprite.setPosition(sf::Vector2f(28*32,0));
    //clickedSprite.setPosition(sf::Vector2f(28*32,0));

    //clickedSprite.setTextureRect(sf::IntRect(0,0,32*3,32*1));
    highlightedSprite.setTextureRect(sf::IntRect(10*32,2*32,3*32,1*32));
}


void quitButton::draw(sf::RenderTarget& target , sf::RenderStates states) const{
    // if (isClicked) {target.draw(clickedSprite);}
    if (isHighlighted && !isClicked) {target.draw(highlightedSprite);}
}
