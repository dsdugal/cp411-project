#include "Board.hpp"

Board::Board() {
	topRight = new Prism();
	topRight->scaleDown(0.25);
	topRight->rotateMC(0, 1, 0, 90);
	topRight->translate(-7.5, 0, -4.2);
	topRight->resizeX(0.3);
	topLeft = new Prism();
	topLeft->scaleDown(0.25);
	topLeft->rotateMC(0, 1, 0, 90);
	topLeft->translate(-7.5, 0, 4.2);
	topLeft->resizeX(0.3);
	topMiddle = new Prism();
	topMiddle->scaleDown(0.25);
	topMiddle->rotateMC(0, 1, 0, 90);
	topMiddle->translate(-7.5, 0, 0);
	topMiddle->resizeX(0.4);
	leftBottom = new Prism();
	leftBottom->scaleDown(0.25);
	leftBottom->translate(3.2, 0.8, 5.35);
	leftBottom->resizeX(0.3);
	leftBottom->resizeZ(0.5);
	leftTop = new Prism();
	leftTop->scaleDown(0.25);
	leftTop->translate(-4.16, 0.8, 5.35);
	leftTop->resizeX(0.3);
	leftTop->resizeZ(0.5);
	rightBottom = new Prism();
	rightBottom->scaleDown(0.25);
	rightBottom->translate(3.2, 0.8, -5.35);
	rightBottom->resizeX(0.3);
	rightBottom->resizeZ(0.5);
	rightTop = new Prism();
	rightTop->scaleDown(0.25);
	rightTop->translate(-4.16, 0.8, -5.35);
	rightTop->resizeX(0.3);
	rightTop->resizeZ(0.5);
	bottom = new Prism();
	bottom->scaleDown(0.25);
	bottom->rotateMC(0, 1, 0, 90);
	bottom->translate(5.5, 0, 0);
	surface = new Prism();
	surface->translate(-1.12, -2, 0);
	surface->resizeX(0.915);
	surface->resizeZ(6.07);
}

Board::~Board() {
	delete topLeft;
	delete topMiddle;
	delete topRight;
	delete leftTop;
	delete leftBottom;
	delete rightTop;
	delete rightBottom;
	delete bottom;
	delete surface;
}

void Board::drawBoard() {
	topLeft->draw();
	topMiddle->draw();
	topRight->draw();
	leftTop->draw();
	leftBottom->draw();
	rightTop->draw();
	rightBottom->draw();
	bottom->draw();
	surface->draw();
}
