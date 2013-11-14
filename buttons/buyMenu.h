#ifndef BUYMENU_H_INCLUDED
#define BUYMENU_H_INCLUDED

#include<SFML/Graphics.hpp>
#include"../GameObjects.hpp"

class buyMenu : public gameObject {
public:
    buyMenu(std::shared_ptr<sf::Texture> texture, gameScreen* screen);
private:
    virtual void draw(sf::RenderTarget& target , sf::RenderStates states) const;
    sf::Sprite highlightedSprite;
    bool relinquishControl;
    virtual bool _eventControl(sf::Event);
    virtual void _selected();
};
#endif
