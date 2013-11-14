//Header file for MainStage.cpp, this is where the code for where most of the action occurs
#ifndef MAINSTAGE_H
#define MAINSTAGE_H

#include"GameScreen.h"
#include"VertexUtilities.h"
#include<SFML/Graphics.hpp>
#include<vector>
#include<memory>
#include"GameObjects.hpp"


class mainScreen : public gameScreen {
public:
	virtual void eventParse(sf::Event);
	virtual gameScreen* nextScreen();
	virtual ~mainScreen();
	mainScreen();
	//std::vector<int> internalInts;
private:
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	void _mouseMoved(sf::Event);
	void _mouseClicked(sf::Event);
	void _mouseReleased(sf::Event);
	void _keyPressed(sf::Event);
	std::vector<std::string> internalIntsLabels;
	std::vector<std::shared_ptr<sf::Texture>> textures;
	std::vector<std::shared_ptr<gameObject>> gameObjects;
	std::vector<sf::IntRect> objectIntRects;
	std::vector<std::shared_ptr<sf::Sprite>> sprites;
	int currentObject;
	int currentlyClicked;
	int currentlySelected;

};

#endif
