#ifndef SPAWNLEVELBUTTON_H_INCLUDED
#define SPAWNLEVELBUTTON_H_INCLUDED

#include<SFML/Graphics.hpp>
#include"../GameObjects.hpp"

class spawnLevelButton : public gameObject {
public:
    spawnLevelButton(std::shared_ptr<sf::Texture> texture, gameScreen* screen);
private:
    virtual void draw(sf::RenderTarget& target , sf::RenderStates states) const;
    sf::Sprite highlightedSprite;
};
#endif
