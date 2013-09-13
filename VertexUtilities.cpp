// Definitons for things in VertexUtilities.h

#include"VertexUtilities.h"
#include<vector>
#include<SFML/Graphics.hpp>

// Applies the IntRect corner coordinates to the VertexArray vertex positions starting at position
// Preconditions:	vertexArray must have a size greater than or equal to position +4
void applyRectToPos(sf::IntRect& IntRect, sf::VertexArray& vertexArray, int position ){
	for (int i= 0; i < 4; ++i){
			vertexArray[position].position		= sf::Vector2f(IntRect.left					, IntRect.top					);
			vertexArray[position+1].position	= sf::Vector2f(IntRect.left + IntRect.width	, IntRect.top					);
			vertexArray[position+2].position	= sf::Vector2f(IntRect.left + IntRect.width	, IntRect.top + IntRect.height	);
			vertexArray[position+3].position	= sf::Vector2f(IntRect.left					, IntRect.top + IntRect.height	);
		}
}

// Applies an array of IntRects in the range given by the first two arguments in sf::Vector2i& to the position coordinate of a VertexArray, 
// starting from "position" on the VertexArray.
// Preconditions:	vertexArray has size enough to hold all the IntRects, 4 for each one, starting at vertexArray[position]
//					range is a valid range for the IntRect, the first coordinate the lower bound and the second the higher bound, with
//						the higher bound equal to or greater than the lower bound
void applyRectToPos(std::vector<sf::IntRect>::iterator& begin, std::vector<sf::IntRect>::iterator& end, sf::VertexArray& vertexArray, int position){
	int i=0;
	for (std::vector<sf::IntRect>::iterator I = begin; I !=end ; ++I) {
		applyRectToPos(*I, vertexArray, 4*i+position);
		++i;
	}
}

// Applies the IntRect corner coordinates to the VertexArray vertex texCoords starting at position
// Preconditions:	vertexArray must have a size greater than or equal to position +4
void applyRectToTxtCrd(sf::IntRect& IntRect, sf::VertexArray& vertexArray, int position ){
	for (int i= 0; i < 4; ++i){
		vertexArray[position].texCoords		= sf::Vector2f(IntRect.left					, IntRect.top					);
		vertexArray[position+1].texCoords	= sf::Vector2f(IntRect.left + IntRect.width	, IntRect.top					);
		vertexArray[position+2].texCoords	= sf::Vector2f(IntRect.left + IntRect.width	, IntRect.top + IntRect.height	);
		vertexArray[position+3].texCoords	= sf::Vector2f(IntRect.left					, IntRect.top + IntRect.height	);
	}
}

// Applies an array of IntRects in the range given by the first two arguments in sf::Vector2i& to the texture coordinate of a VertexArray, 
// starting from "position" on the VertexArray.
// Preconditions:	vertexArray has size enough to hold all the IntRects, 4 for eac5h one, starting at vertexArray[position]
//					range is a valid range for the IntRect, the first coordinate the lower bound and the second the higher bound, with
//						the higher bound equal to or greater than the lower bound
void applyRectToTxtCrd(std::vector<sf::IntRect>::iterator& begin, std::vector<sf::IntRect>::iterator& end, sf::VertexArray& vertexArray, int position){
	int i=0;
	for (std::vector<sf::IntRect>::iterator I = begin; I !=end ; ++I) {
		applyRectToTxtCrd(*I, vertexArray, 4*i+position);
		++i;
	}
}