// TowerDefense.cpp : Defines the entry point for the console application.
// File name used to have spaces, but spaces were deleted.  That blog was right, they are a huge pain in the backside

#include<iostream>
#include<SFML/Graphics.hpp>
#include<vector>
#include<assert.h>
#include"GameScreen.h"
#include"VertexUtilities.h"
#include"MainStage.h"


// Simple class containing code for the creation of and the running of the introductory screen
class menuScreen : public gameScreen{
public:
	menuScreen() : currentItem(-1), whatsClicked(-1){
	    newScreen = this;
	    shouldClose = false;

		if (!IntroScreenTx.loadFromFile("img/IntroScreen.png")){std::cerr << "Intro Screen loading error" << std::endl;}
		IntroScreenSp.setTexture(IntroScreenTx);

		// Initialization of our two important arrays
		menuScreenItemAreas.reserve(8);	menuScreenItemTextureAreas.reserve(8);
		for (int i = 0; i < 8; ++i){
			// Setting the areas in the texture files that map to required textures
			menuScreenItemTextureAreas.push_back(sf::IntRect(0,60*i, 300, 60));
			// Setting the areas on the screen that the sprites will be drawn to
			menuScreenItemAreas.push_back(sf::IntRect(362,320+70*(i%4),300,60));
		}

		// Loading the menu item textures
		if (!IntroScreenMenuItemsTx.loadFromFile("img/IntroScreenMenuItems.png")){std::cerr << "Menu Items loading error" << std::endl;}

		// Sets the primitive types of this vertex Array to Quads, which are squares [and not triangles]
		vertexArray.setPrimitiveType(sf::Quads);
		vertexArray.resize(16);
		for (int i =0; i < 4; ++i) applyRectToPos(menuScreenItemAreas.at(i), vertexArray, 4*i);
	}

	// Code that determines how/when I enter the next screen.  For now I'm not leaving the menu, so it just returns 'this',
	// which is the current screen, to be active once more [continue being active]
	virtual gameScreen* nextScreen(){
	    return newScreen;}

    // Inherited method that simply takes the mouse inputs from the main program loop and hands them over
	virtual void eventParse(sf::Event event){
	    switch (event.type){
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove.x,event.mouseMove.y);
            break;
        case sf::Event::MouseButtonPressed :
            whatsClicked = currentItem;
            break;
        case sf::Event::MouseButtonReleased :
            if (whatsClicked == currentItem){
                switch (whatsClicked) {
                case 0:
                    newScreen = new mainScreen();
                    break;
                case 1:
                    // Enter Load screen
                    break;
                case 2:
                    // Enter Options screen
                    break;
                case 3:
                    // Quit Game
                    shouldClose = true;
                    break;
                default:
                    break;
                }
            }
            break;
        default:
            break;
		}
	}
private:
	void onMouseMove(int x, int y){
	    int tempCurrentItem = -1;                           // Workaround to avoid undesirable race conditions
		for(int i= 0; i < 4; ++i){
			if ( !menuScreenItemAreas.at(i).contains(x,y) ) {
                applyRectToTxtCrd(menuScreenItemTextureAreas.at(i),vertexArray,4*i);
                }
			else {
                applyRectToTxtCrd(menuScreenItemTextureAreas.at(i+4),vertexArray,4*i);
               tempCurrentItem = i;
			}
		}
		currentItem = tempCurrentItem;
	}
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
		target.draw((sf::Sprite)IntroScreenSp);
		states.texture = &IntroScreenMenuItemsTx;
		target.draw(vertexArray, states);
	}

	sf::Texture IntroScreenMenuItemsTx;
	std::vector<sf::IntRect> menuScreenItemAreas;	        // Menu item screen areas
	std::vector<sf::IntRect> menuScreenItemTextureAreas;    // Menu item sprite texture areas
	sf::VertexArray vertexArray;			            	// This is a drawable.
	sf::Sprite IntroScreenSp;					            // This is our background
	sf::Texture IntroScreenTx;		            			// Intro screen background splash art
	int currentItem;                                        // Item mouse is currently hovering over.  -1 means currently none.
	int whatsClicked;                                       // when equal to -1 means nothing is selected, when equal to 0,1,2,3 imply one of the four menu items is.
	gameScreen *newScreen;                                  // Temporary storage for next game screen object to avoid trouble
};

int main(int argc, char* argv[]){
	// Creates our rendering window, at the resolution of the numbers in the parentheses of the first argument
	sf::RenderWindow window(sf::VideoMode(1024,640), "TeaSea TeeDee");
	window.setFramerateLimit(30);
	// Creates the menuScreen
	gameScreen *mainScreen = new menuScreen();

	while (window.isOpen()){
		sf::Event event;

		while (window.pollEvent(event)){

			mainScreen->eventParse(event);
			mainScreen = mainScreen->nextScreen();
            if (event.type == sf::Event::Closed) window.close(); ;
			}
		window.clear();
		window.draw(*mainScreen);
		window.display();
		if (mainScreen->shouldClose) {window.close();}
	}
	return 0;
}
