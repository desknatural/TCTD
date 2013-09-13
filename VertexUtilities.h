#ifndef VERTEXUTILITIES_H
#define VERTEXUTILITIES_H


// Vertex utilities

#include<SFML/Graphics.hpp>
#include<vector>

// Applies the IntRect corner coordinates to the VertexArray vertex positions starting at position
// Preconditions:	vertexArray must have a size greater than or equal to position +4
void applyRectToPos(sf::IntRect&, sf::VertexArray&, int = 0);

// Applies an array of IntRects in the range given by the first two arguments in sf::Vector2i& to the position coordinate of a VertexArray, 
// starting from "position" on the VertexArray.
// Preconditions:	vertexArray has size enough to hold all the IntRects, 4 for each one, starting at vertexArray[position]
//					range is a valid range for the IntRect, the first coordinate the lower bound and the second the higher bound, with
//						the higher bound equal to or greater than the lower bound
void applyRectToPos(std::vector<sf::IntRect>::iterator&, std::vector<sf::IntRect>::iterator&, sf::VertexArray&, int = 0);

// Applies the IntRect corner coordinates to the VertexArray vertex texCoords starting at position
// Preconditions:	vertexArray must have a size greater than or equal to position +4
void applyRectToTxtCrd(sf::IntRect&, sf::VertexArray&, int = 0);

// Applies an array of IntRects in the range given by the first two arguments in sf::Vector2i& to the texture coordinate of a VertexArray, 
// starting from "position" on the VertexArray.
// Preconditions:	vertexArray has size enough to hold all the IntRects, 4 for each one, starting at vertexArray[position]
//					range is a valid range for the IntRect, the first coordinate the lower bound and the second the higher bound, with
//						the higher bound equal to or greater than the lower bound
void applyRectToTxtCrd(std::vector<sf::IntRect>&, sf::VertexArray&, sf::Vector2i&, int = 0);

#endif