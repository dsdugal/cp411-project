#ifndef SRC_BOARD_HPP_
#define SRC_BOARD_HPP_

#include "Shape3D.hpp"
#include "Prism.hpp"

class Board: public Shape3D {
	private:
		Prism* topLeft;
		Prism* topMiddle;
		Prism* topRight;
		Prism* leftTop;
		Prism* leftBottom;
		Prism* rightTop;
		Prism* rightBottom;
		Prism* bottom;
		Prism* surface;
	public:
		Board();
		~Board();
		void drawBoard();
};

#endif
