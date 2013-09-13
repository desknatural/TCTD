// Definition of MainStage.cpp, this is the main screen for our TD

#include"GameScreen.h"
#include"MainStage.h"
#include"VertexUtilities.h"
#include"stuffstuff.h"
#include<SFML/Graphics.hpp> 
#include<iostream>



void mainScreen::eventParse(sf::Event event){
	if (event.type == sf::Event::MouseMoved) _mouseMoved(event);
	else if (event.type == sf::Event::MouseButtonPressed) _mouseClicked(event);
	else if (event.type == sf::Event::MouseButtonReleased) _mouseReleased(event);
}

gameScreen* mainScreen::nextScreen(){return this;}

void mainScreen::_mouseMoved(sf::Event){
// Check if there are any objecst that it's moved over, do appropriate action

}

void mainScreen::_mouseClicked(sf::Event){
bool mouseDepressed = true;
}

void mainScreen::_mouseReleased(sf::Event){
// This only happens after a mouse clicked.
}

mainScreen::mainScreen(){
	// First we are creating and loading our background texture, then setting the first drawable to be a sprite with this texture
	textures.push_back(std::shared_ptr<sf::Texture> (new sf::Texture));
	if(!textures.at(0)->loadFromFile("img/GridScren.png")){std::cout << "GridScreen loading error" << std::endl;}
	sprites.push_back( std::shared_ptr<sf::Sprite> ( new sf::Sprite(*textures.at(0)) ) );

	// Initialization of our list of integers and what be it
	internalIntsLabels.resize(10);
	internalIntsLabels.push_back("Score");
	internalIntsLabels.push_back("Level");
	internalIntsLabels.push_back("Gold");
	internalIntsLabels.push_back("EnemiesOnScreen");

	internalInts.resize(10);

	// Button Sprites, for the bigger version of each button

	sprites.push_back(std::shared_ptr<sf::Sprite> (new sf::Sprite) );
	sprites.push_back(std::shared_ptr<sf::Sprite> (new sf::Sprite) );
	sprites.push_back(std::shared_ptr<sf::Sprite> (new sf::Sprite) );
	sprites.push_back(std::shared_ptr<sf::Sprite> (new sf::Sprite) );
	sprites.push_back(std::shared_ptr<sf::Sprite> (new sf::Sprite) );
	sprites.push_back(std::shared_ptr<sf::Sprite> (new sf::Sprite) );

}