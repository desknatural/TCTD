// Header file for basic towers class definition
#ifndef TOWERS_H_INCLUDE
#define TOWERS_H_INCLUDE

#include"../gameObjects.hpp"
#include<string>
class tower : public gameObject {
public:
    virtual void _tick();
    virtual void _selected();
private:
    std::string towerName;
    int towerCost;
    int range;
    int towerDmg;
    int cdr;
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};
#endif // TOWERS_H_INCLUDE
