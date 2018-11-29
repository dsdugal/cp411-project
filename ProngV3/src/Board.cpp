#include "Board.hpp"

Board::Board() {
	top_wall = new Prism();
	top_wall->scaleDown(0.8);
	top_wall->translate(-7.5, 0, 0);
	top_wall->rotateMC(0, 1, 0, 90);
	top_wall->stretch(3.9);

	bottom_wall = new Prism();
	bottom_wall->scaleDown(0.8);
	bottom_wall->translate(5.5, 0, 0);
	bottom_wall->rotateMC(0, 1, 0, 90);
	bottom_wall->stretch(3.9);

	topLeft_wall = new Prism();
	topLeft_wall->scaleDown(0.8);
	topLeft_wall->translate(0, 0, 6);
	topLeft_wall->translate(-5, 0, 0);
	topLeft_wall->stretch(1.5);

	botLeft_wall = new Prism();
	botLeft_wall->scaleDown(0.8);
	botLeft_wall->translate(0, 0, 6);
	botLeft_wall->translate(3, 0, 0);
	botLeft_wall->stretch(1.5);

	topRight_wall = new Prism();
	topRight_wall->scaleDown(0.8);
	topRight_wall->translate(0, 0, -6);
	topRight_wall->translate(-5, 0, 0);
	topRight_wall->stretch(1.5);

	botRight_wall = new Prism();
	botRight_wall->scaleDown(0.8);
	botRight_wall->translate(0, 0, -6);
	botRight_wall->translate(3, 0, 0);
	botRight_wall->stretch(1.5);
}

void Board::drawBoard() {
	top_wall->draw();
	bottom_wall->draw();
	topLeft_wall->draw();
	botLeft_wall->draw();
	topRight_wall->draw();
	botRight_wall->draw();
}
