// Implementation file for gold.hpp

#include<iostream>
#include<math.h>
#include"gold.hpp"
#include"../VertexUtilities.h"
#include"../gameObjects.hpp"

int powerOfTen(int power){
    int temp = 1;
    for (int i = 0; i < power; i++){
        temp = temp*10;
    }
    return temp;
}

void appendNumberVertices(int number, sf::VertexArray& vertexArray, int position){
    sf::IntRect temp = sf::IntRect((7+number)*32,0, 32,32);
    applyRectToTxtCrd(temp, vertexArray, position);
}

void goldBoard::_tick(){
    for (int i=0; i< 5 ; ++i){
        int temp = screen->internalInts.at(2);      // internalInts[2] contains the score for now)
        temp = temp/(powerOfTen(i));
        temp = temp%10;
        appendNumberVertices(temp, vertexArray, 4*4 - i*4);
    }
}

goldBoard::goldBoard(std::shared_ptr<sf::Texture> texture, gameScreen* screen): gameObject(texture,screen), vertexArray(sf::Quads,20){
    // Sets the positions of the numbers
    for (int i=0; i < 5; ++i){ sf::IntRect temp = sf::IntRect((20+i)*32,0,32,32); applyRectToPos(temp, vertexArray, 4*i);}

}

void goldBoard::draw(sf::RenderTarget& target , sf::RenderStates states) const{
    states.texture = &(*texture);
    target.draw(vertexArray, states);
}

