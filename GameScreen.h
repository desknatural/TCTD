// Header file for Tower Defense.cpp
#ifndef GAMESCREEN_H
#define GAMESCREEN_H
#include<SFML/Graphics.hpp>

class gameScreen : public sf::Drawable{
public:
	virtual void eventParse(sf::Event) = 0;
	virtual gameScreen* nextScreen();
	virtual ~gameScreen();
	bool shouldClose;
    std::vector<int> internalInts;
private:
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const=0;
};

#endif
