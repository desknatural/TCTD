#ifndef HELPBUTTON_H_INCLUDED
#define HELPBUTTON_H_INCLUDED

#include<SFML/Graphics.hpp>
#include"../GameObjects.hpp"

class helpButton : public gameObject {
public:
    helpButton(std::shared_ptr<sf::Texture> texture, gameScreen* screen);
private:
    virtual void draw(sf::RenderTarget& target , sf::RenderStates states) const;
    sf::Sprite highlightedSprite;
};
#endif
