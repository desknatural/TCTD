#ifndef DESTROYBUTTON_H_INCLUDED
#define DESTROYBUTTON_H_INCLUDED

#include<SFML/Graphics.hpp>
#include"../GameObjects.hpp"

class destroyButton : public gameObject {
public:
    destroyButton(std::shared_ptr<sf::Texture> texture, gameScreen* screen);
private:
    virtual void draw(sf::RenderTarget& target , sf::RenderStates states) const;
    sf::Sprite highlightedSprite;
};
#endif
