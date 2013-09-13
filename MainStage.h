// Header file for MainStage.cpp, this is where the code for where most of the action occurs
#ifndef MAINSTAGE_H
#define MAINSTAGE_H

#include"GameScreen.h"
#include"VertexUtilities.h"
#include<SFML/Graphics.hpp>
#include<vector>
#include<memory>

class mainScreen : public gameScreen {
public:
	virtual void eventParse(sf::Event);
	virtual gameScreen* nextScreen();
	virtual ~mainScreen();
	mainScreen();
private:
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	void _mouseMoved(sf::Event);
	void _mouseClicked(sf::Event);
	void _mouseReleased(sf::Event);
	std::vector<int> internalInts;
	std::vector<std::string> internalIntsLabels;
	std::vector<std::shared_ptr<sf::Sprite>> sprites;
	std::vector<std::shared_ptr<sf::Texture>> textures;
	bool mouseDepressed;

};

#endif