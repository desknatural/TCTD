#ifndef UPGRADEBUTTON_H_INCLUDED
#define UPGRADEBUTTON_H_INCLUDED

#include<SFML/Graphics.hpp>
#include"../GameObjects.hpp"

class upgradeButton : public gameObject {
public:
    upgradeButton(std::shared_ptr<sf::Texture> texture, gameScreen* screen);
private:
    virtual void draw(sf::RenderTarget& target , sf::RenderStates states) const;
    sf::Sprite highlightedSprite;
};
#endif
