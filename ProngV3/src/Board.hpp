#ifndef SRC_BOARD_HPP_
#define SRC_BOARD_HPP_

#include "Shape3D.hpp"
#include "Prism.hpp"

class Board: public Shape3D {
	// the game board
	// needs score board, etc
public:
	Prism* top_wall;
	Prism* bottom_wall;
	Prism* topLeft_wall;
	Prism* botLeft_wall;
	Prism* topRight_wall;
	Prism* botRight_wall;
	Board();
	void drawBoard();

};

#endif
