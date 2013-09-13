// Tower Defense.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<SFML/Graphics.hpp>
#include<vector>
#include<assert.h>
#include"GameScreen.h"
#include"VertexUtilities.h"

class menuScreen : public gameScreen{
public:	
	// Takes the mouseMove event coordinates and does stuff with them
	menuScreen(){
	
		if (!IntroScreenTx.loadFromFile("img/IntroScreen.png")){std::cout << "Intro Screen loading error" << std::endl;}
		IntroScreenSp.setTexture(IntroScreenTx);

		// Initialization of our two important arrays
		menuScreenItemAreas.reserve(8);	menuScreenItemTextureAreas.reserve(8);
		for (int i = 0; i < 8; ++i){
			menuScreenItemTextureAreas.push_back(sf::IntRect(0,60*i, 300, 60));
			menuScreenItemAreas.push_back(sf::IntRect(362,320+70*(i%4),300,60));
		}

		// Texture loading
		if (!IntroScreenMenuItemsTx.loadFromFile("img/IntroScreenMenuItems.png")){std::cout << "Menu Items loading error" << std::endl;}
		
		vertexArray.setPrimitiveType(sf::Quads);
		vertexArray.resize(16);
		for (int i =0; i < 4; ++i) applyRectToPos(menuScreenItemAreas.at(i), vertexArray, 4*i);
	}
	virtual gameScreen* nextScreen(){
		return this;}
	virtual void eventParse(sf::Event event){
		if (event.type == sf::Event::MouseMoved) {
			onMouseMove(event.mouseMove.x,event.mouseMove.y);
			}
	}
private:
	void onMouseMove(int x, int y){
		for(int i= 0; i < 4; ++i){
			// If 
			if ( !menuScreenItemAreas.at(i).contains(x,y) ) applyRectToTxtCrd(menuScreenItemTextureAreas.at(i),vertexArray,4*i);
	
			else applyRectToTxtCrd(menuScreenItemTextureAreas.at(i+4),vertexArray,4*i);

			}
		}
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
		target.draw((sf::Sprite)IntroScreenSp);
		states.texture = &IntroScreenMenuItemsTx;
		target.draw(vertexArray, states);
	}

	sf::Texture IntroScreenMenuItemsTx;
	std::vector<sf::IntRect> menuScreenItemAreas;					// Menu item screen areas
	std::vector<sf::IntRect> menuScreenItemTextureAreas;					// Menu item sprite texture areas
	sf::VertexArray vertexArray;					// This is a drawable.
	sf::Sprite IntroScreenSp;						// This is our background
	sf::Texture IntroScreenTx;						// Intro screen background splash art
};

int main(int argc, char* argv[]){
	// Creates our rendering window, at the resolution of the numbers in the parnetheses of the first argument
	sf::RenderWindow window(sf::VideoMode(1024,640), "TeaSea TeeDee");
	// Creates the menuScreen
	gameScreen *mainScreen = new menuScreen();
	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			mainScreen->eventParse(event);
			mainScreen = mainScreen->nextScreen();
			if (event.type == sf::Event::Closed) window.close();
			}
		window.clear();
		window.draw(*mainScreen);
		window.display();
	}
	return 0;
}

