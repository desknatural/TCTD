
#ifndef QUITBUTTON_H_INCLUDED
#define QUITBUTTON_H_INCLUDED

#include<SFML/Graphics.hpp>
#include"../GameObjects.hpp"

class quitButton : public gameObject {
public:
    quitButton(std::shared_ptr<sf::Texture> texture, gameScreen* screen);
    virtual void _selected();
private:
    virtual void draw(sf::RenderTarget& target , sf::RenderStates states) const;
    sf::Sprite highlightedSprite;
    sf::Sprite clickedSprite;
};
#endif
