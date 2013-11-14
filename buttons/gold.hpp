#ifndef GOLD_H_INCLUDED
#define GOLD_H_INCLUDED

#include<iostream>
#include<vector>
#include"../VertexUtilities.h"
#include"../gameObjects.hpp"

void appendNumberVertices(int number, sf::VertexArray vertexArray);

class goldBoard : public gameObject{
public:
    goldBoard(std::shared_ptr<sf::Texture>, gameScreen*);
private:
    virtual void draw(sf::RenderTarget& target , sf::RenderStates states) const;
    virtual void _tick();
    sf::VertexArray vertexArray;
};

#endif
