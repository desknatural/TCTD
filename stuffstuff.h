// Wierd little file where I stick things that I have yet to implement and am too lazy to put in their own header file


#include"GameScreen.h"
#include"VertexUtilities.h"
#include<SFML/Graphics.hpp>
#include<vector>
#include<memory>

class gameObject : sf::Drawable {
public:
	gameObject();
	gameObject(sf::IntRect selectionRect, sf::Sprite getSprite);
	regCallbacks(
	void Highlighted();			
	void Clicked();
	void Selected();
	void DeHighlighted();
	void DeClicked();
	void DeSelected();
	void tick();			// Miscellaneous object-specific code to be executed every frame
	sf::IntRect getSelctionRect();
	sf::Sprite getSprite();
private:
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	sf::IntRect selectionRect;
	sf::Sprite sprite;	
	std::vector
};