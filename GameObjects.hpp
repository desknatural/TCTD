// Header file for GameObjects.hpp

#ifndef GAMEOBJECTS_H_INCLUDE
#define GAMEOBJECTS_H_INCLUDE

#include"GameScreen.h"
#include"VertexUtilities.h"
#include<SFML/Graphics.hpp>
#include<vector>
#include<memory>


class gameObject : public sf::Drawable{
public:
    gameObject(std::shared_ptr<sf::Texture>);
    gameObject();
    gameObject(std::shared_ptr<sf::Texture>, gameScreen*);
    virtual ~gameObject();
    void highlighted();
    void clicked();
    void selected();
    void deHighlighted();
    void deClicked();
    void deSelected();
    void tick();
    bool eventControl(sf::Event);
    sf::IntRect getSelctionRect();
	sf::IntRect getSpriteRect();
private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;       // Typical draw function for sf::Drawable objects
protected:
    sf::IntRect selectionRect;                                          // The bounding rectangle of the object; this is the key that is used for searching
	std::vector<sf::IntRect> spriteRects;                               // The resources for the different sprites to be found within the texture file
	std::shared_ptr<sf::Texture> texture;                               // Shared pointer towards the texture resource.
	gameScreen *screen;                                                 // Pointer to the screen to which this object belongs
    bool isHighlighted;
	bool isClicked;
	bool isSelected;
	virtual void _highlighted();
    virtual void _clicked();
    virtual void _selected();
    virtual void _deHighlighted();
    virtual void _deClicked();
    virtual void _deSelected();
    virtual void _tick();
    virtual bool _eventControl(sf::Event);

};

#endif
