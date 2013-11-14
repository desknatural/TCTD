#include "GameObjects.hpp"
#include <iostream>

void gameObject::highlighted(){isHighlighted = true; _highlighted(); return;}
void gameObject::clicked(){isClicked = true; _clicked(); return;}
void gameObject::selected(){isSelected = true; _selected(); return;}
void gameObject::deHighlighted(){isHighlighted = false; _deHighlighted(); return;}
void gameObject::deClicked(){isClicked = false; _deClicked(); return;}
void gameObject::deSelected(){isSelected = false; _deSelected(); return;}
void gameObject::tick(){_tick(); return;}
bool gameObject::eventControl(sf::Event event) {return _eventControl(event);}

void gameObject::_highlighted(){return;}
void gameObject::_clicked(){return;}
void gameObject::_selected(){return;}
void gameObject::_deHighlighted(){return;}
void gameObject::_deClicked(){return;}
void gameObject::_deSelected(){return;}
void gameObject::_tick(){return;}
bool gameObject::_eventControl(sf::Event event){return false;}

sf::IntRect gameObject::getSelctionRect(){return selectionRect;}
sf::IntRect gameObject::getSpriteRect(){return sf::IntRect(); }

void gameObject::draw(sf::RenderTarget&, sf::RenderStates) const {}

gameObject::gameObject(){}
gameObject::gameObject(std::shared_ptr<sf::Texture> texture, gameScreen* screen) : texture(texture) , screen(screen) , isHighlighted(false) , isClicked(false) , isSelected(false){std::cerr << "constructor called " << std::endl;}
gameObject::gameObject (std::shared_ptr<sf::Texture> texture): texture(texture){}
gameObject::~gameObject(){};
