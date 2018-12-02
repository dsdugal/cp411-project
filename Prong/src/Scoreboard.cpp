#include "Scoreboard.hpp"

Scoreboard::Scoreboard() {
	P1_top = new Prism();
	P1_top->resizeX(0.6);
	P1_top->scaleDown(0.975);
	P1_top->rotateMC(0, 1, 0, 90);
	P1_top->translate(-8.5, 1, 0 + 1 - 0.075);
	P1_topLeft = new Prism();
	P1_topLeft->resizeZ(0.6);
	P1_topLeft->scaleDown(0.975);
	P1_topLeft->translate(-8.6, 0.55, 0.15 + 1 - 0.05);
	P1_topRight = new Prism();
	P1_topRight->resizeZ(0.6);
	P1_topRight->scaleDown(0.975);
	P1_topRight->translate(-8.6, 0.55, -0.15 + 1 - 0.05);
	P1_middle = new Prism();
	P1_middle->resizeX(0.6);
	P1_middle->scaleDown(0.975);
	P1_middle->rotateMC(0, 1, 0, 90);
	P1_middle->translate(-8.7, 0, 0 + 1);
	P1_bottomLeft = new Prism();
	P1_bottomLeft->resizeZ(0.6);
	P1_bottomLeft->scaleDown(0.975);
	P1_bottomLeft->translate(-8.8, -0.55, 0.15 + 1);
	P1_bottomRight = new Prism();
	P1_bottomRight->resizeZ(0.6);
	P1_bottomRight->scaleDown(0.975);
	P1_bottomRight->translate(-8.8, -0.55, -0.15 + 1);
	P1_bottom = new Prism();
	P1_bottom->resizeX(0.6);
	P1_bottom->scaleDown(0.975);
	P1_bottom->rotateMC(0, 1, 0, 90);
	P1_bottom->translate(-8.9, -1, 0 + 1);
	P2_top = new Prism();
	P2_top->resizeX(0.6);
	P2_top->scaleDown(0.975);
	P2_top->rotateMC(0, 1, 0, 90);
	P2_top->translate(-8.5, 1, 0 - 1 + 0.075);
	P2_topLeft = new Prism();
	P2_topLeft->resizeZ(0.6);
	P2_topLeft->scaleDown(0.975);
	P2_topLeft->translate(-8.6, 0.55, 0.15 - 1 + 0.05);
	P2_topRight = new Prism();
	P2_topRight->resizeZ(0.6);
	P2_topRight->scaleDown(0.975);
	P2_topRight->translate(-8.6, 0.55, -0.15 - 1 + 0.05);
	P2_middle = new Prism();
	P2_middle->resizeX(0.6);
	P2_middle->scaleDown(0.975);
	P2_middle->rotateMC(0, 1, 0, 90);
	P2_middle->translate(-8.7, 0, 0 - 1);
	P2_bottomLeft = new Prism();
	P2_bottomLeft->resizeZ(0.6);
	P2_bottomLeft->scaleDown(0.975);
	P2_bottomLeft->translate(-8.8, -0.55, 0.15 - 1);
	P2_bottomRight = new Prism();
	P2_bottomRight->resizeZ(0.6);
	P2_bottomRight->scaleDown(0.975);
	P2_bottomRight->translate(-8.8, -0.55, -0.15 - 1);
	P2_bottom = new Prism();
	P2_bottom->resizeX(0.6);
	P2_bottom->scaleDown(0.975);
	P2_bottom->rotateMC(0, 1, 0, 90);
	P2_bottom->translate(-8.9, -1, 0 - 1);
}

Scoreboard::~Scoreboard() {
	delete P1_top;
	delete P1_topLeft;
	delete P1_topRight;
	delete P1_middle;
	delete P1_bottomLeft;
	delete P1_bottomRight;
	delete P1_bottom;
	delete P2_top;
	delete P2_topLeft;
	delete P2_topRight;
	delete P2_middle;
	delete P2_bottomLeft;
	delete P2_bottomRight;
	delete P2_bottom;
}

void Scoreboard::drawScore(GLint scoreP1, GLint scoreP2) {

	// glColor3f(0.0, 1.0, 0.0);

	// draw score for player 1
	if (scoreP1 == 0 || (scoreP1 >= 2 && scoreP1 != 4)) {
		P1_top->draw();
	}
	if (scoreP1 == 0 || (scoreP1 >= 4 && scoreP1 != 7)) {
		P1_topLeft->draw();
	}
	if (scoreP1 != 5 && scoreP1 != 6) {
		P1_topRight->draw();
	}
	if (scoreP1 >= 2 && scoreP1 != 7) {
		P1_middle->draw();
	}
	if (scoreP1 == 0 || scoreP1 == 2 || scoreP1 == 6 || scoreP1 == 8) {
		P1_bottomLeft->draw();
	}
	if (scoreP1 != 2) {
		P1_bottomRight->draw();
	}
	if (scoreP1 != 1 && scoreP1 != 4 && scoreP1 != 7) {
		P1_bottom->draw();
	}

	// draw score for player 2
	if (scoreP2 == 0 || (scoreP2 >= 2 && scoreP2 != 4)) {
		P2_top->draw();
	}
	if (scoreP2 == 0 || (scoreP2 >= 4 && scoreP2 != 7)) {
		P2_topLeft->draw();
	}
	if (scoreP2 != 5 && scoreP2 != 6) {
		P2_topRight->draw();
	}
	if (scoreP2 >= 2 && scoreP2 != 7) {
		P2_middle->draw();
	}
	if (scoreP2 == 0 || scoreP2 == 2 || scoreP2 == 6 || scoreP2 == 8) {
		P2_bottomLeft->draw();
	}
	if (scoreP2 != 2) {
		P2_bottomRight->draw();
	}
	if (scoreP2 != 1 && scoreP2 != 4 && scoreP2 != 7) {
		P2_bottom->draw();
	}
}
