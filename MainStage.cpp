// Definition of MainStage.cpp, this is the main screen for our TD

#include"GameScreen.h"
#include"MainStage.h"
#include"VertexUtilities.h"
#include<SFML/Graphics.hpp>
#include<iostream>
#include"buttons\buttons.hpp"

bool isEventEsc(sf::Event event){
if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) return true;
else return false;}


void mainScreen::eventParse(sf::Event event){

    if (!gameObjects.at(currentObject)->eventControl(event) && !isEventEsc(event) ){    // In other words, if the current game object does not want control.
        gameObjects.at(currentObject)->deSelected();                    // In case escape was used, let the object -know- it is no longer selected/active
        switch (event.type){
        case sf::Event::MouseMoved:
            _mouseMoved(event);
            break;
        case sf::Event::MouseButtonPressed :
            _mouseClicked(event);
            break;
        case sf::Event::MouseButtonReleased :
            _mouseReleased(event);
            break;
        case sf::Event::KeyPressed:
            _keyPressed(event);
            break;
        default:
            break;
        }
    }
}

// Until we have other screens that we would like to access from this one, we just want it to return
// the screen we're on, so I'll keep it as is for now!
gameScreen* mainScreen::nextScreen(){return this;}

void mainScreen::_mouseMoved(sf::Event event){
    // Check if there are any objects that it's moved over, if so do appropriate action
    int vecSize = objectIntRects.size();
    int tempObject = 0;
    for (int i = 0; i < vecSize; ++i){
        if(objectIntRects.at(i).contains(event.mouseMove.x,event.mouseMove.y)) {
            tempObject = i;
            break;
        }
    }
    if (tempObject != currentObject) {
        gameObjects.at(tempObject)->highlighted();
        std::cerr << tempObject << " has been highlighted" << std::endl;
        gameObjects.at(currentObject)->deHighlighted();
        std::cerr << currentObject << " has been deHighlighted" << std::endl;
        currentObject = tempObject;
        }
    return;
}

void mainScreen::_mouseClicked(sf::Event){
    currentlyClicked = currentObject;
    (*gameObjects.at(currentlyClicked)).clicked();
    std::cerr << currentlyClicked << " has been clicked" << std::endl;
    return;
}

void mainScreen::_mouseReleased(sf::Event){
/* check if mouseReleased is released on mouseClicked, if so then set currentlySelected to currentlyClicked
 if not, then run deClicked on currentlyClicked and set currentlyClicked to the new object [or the null object]*/
    gameObjects.at(currentObject)->deClicked();
    if (currentlyClicked == currentObject) {
        if (currentlySelected != currentlyClicked){
            gameObjects.at(currentlySelected)->deSelected();
            std::cerr << currentlySelected << " has been deSelected" << std::endl;
            currentlySelected = currentlyClicked;
            gameObjects.at(currentlyClicked)->selected();
            std::cerr << currentlyClicked << " has been selected" << std::endl;
        }
    }
    else gameObjects.at(currentlyClicked)->deClicked();
    std::cerr << currentlyClicked << " has been deClicked" << std::endl;
    currentlyClicked = 0;
    return;
}

void mainScreen::_keyPressed(sf::Event) {return;}

mainScreen::mainScreen() {
    std::cerr << " We have reached the mainScreen" << std::endl;
    shouldClose = false;
    currentObject = 0;
    currentlyClicked = 0;
    currentlySelected = 0;

	// First we are creating and loading our background texture, then setting the first drawable to be a sprite with this texture
	textures.push_back(std::shared_ptr<sf::Texture> (new sf::Texture));
	if(!textures.at(0)->loadFromFile("img/MainScreenBackground.png")){std::cerr << "GridScreen loading error" << std::endl;}

	sprites.push_back( std::shared_ptr<sf::Sprite> ( new sf::Sprite(*textures.at(0)) ) );
    sprites.at(0)->setTexture(*textures.at(0));

    // Secondly, we are loading our main textures file
    textures.push_back(std::shared_ptr<sf::Texture> (new sf::Texture));
    if(!textures.at(1)->loadFromFile("img/Textures.png")){std::cerr << "Textures.png loading error" << std::endl;}


    // Initialization of our list of integers and what be it
	internalIntsLabels.resize(10);
	internalIntsLabels.push_back("Score");
	internalIntsLabels.push_back("Level");
	internalIntsLabels.push_back("Gold");
	internalIntsLabels.push_back("EnemiesOnScreen");

	internalInts.resize(10);
    internalInts[2] = 23;    // Simple initial testing value for the gold

    // Because of how our code is, we have to create an initial empty gameObject!  They relinquish control of events by default, so there is no trouble.
    gameObjects.push_back(std::shared_ptr<gameObject> (new gameObject()));
    objectIntRects.push_back(sf::IntRect(0,0,0,0));

    // Button initiations
    gameObjects.push_back(std::shared_ptr<gameObject> (new quitButton(textures.at(1), this)));
    objectIntRects.push_back(sf::IntRect(28*32,0, 3*32, 1*32));
    gameObjects.push_back(std::shared_ptr<gameObject> (new helpButton(textures.at(1), this)));
    objectIntRects.push_back(sf::IntRect(25*32,0, 3*32, 1*32));
    gameObjects.push_back(std::shared_ptr<gameObject> (new destroyButton(textures.at(1), this)));
    objectIntRects.push_back(sf::IntRect(19*32,1*32, 4*32, 1*32));
    gameObjects.push_back(std::shared_ptr<gameObject> (new upgradeButton(textures.at(1), this)));
    objectIntRects.push_back(sf::IntRect(23*32,1*32, 4*32, 1*32));
    gameObjects.push_back(std::shared_ptr<gameObject> (new buyMenu(textures.at(1), this)));
    objectIntRects.push_back(sf::IntRect(27*32,1*32, 4*32, 1*32));
    gameObjects.push_back(std::shared_ptr<gameObject> (new spawnLevelButton(textures.at(1), this)));
    objectIntRects.push_back(sf::IntRect(16*32 + 8,17*32 + 16, 2*32 + 16, 2*32 + 8));
    // Gold counter initialization
    gameObjects.push_back(std::shared_ptr<gameObject> (new goldBoard(textures.at(1),this)));
    objectIntRects.push_back(sf::IntRect(19*32,0,6*32,1*32));


    // Diagnostic message
    std::cerr << " gameObjects size is " << gameObjects.size() << " and objectIntRects size is " << objectIntRects.size() << std::endl;


}

void mainScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // First thing to be drawn, of course, is our background texture
    target.draw((sf::Sprite)*sprites.at(0));
    // for loop through all of our gameObject(s)
    for ( std::shared_ptr<gameObject> object : gameObjects ) {target.draw(*object); object->tick();}
    }

mainScreen::~mainScreen(){}
