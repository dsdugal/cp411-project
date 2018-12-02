#ifndef SRC_SCOREBOARD_HPP_
#define SRC_SCOREBOARD_HPP_

#include "Prism.hpp"

class Scoreboard: public Shape3D {
	private:
		Prism* P1_top;
		Prism* P1_topLeft;
		Prism* P1_topRight;
		Prism* P1_middle;
		Prism* P1_bottomLeft;
		Prism* P1_bottomRight;
		Prism* P1_bottom;
		Prism* P2_top;
		Prism* P2_topLeft;
		Prism* P2_topRight;
		Prism* P2_middle;
		Prism* P2_bottomLeft;
		Prism* P2_bottomRight;
		Prism* P2_bottom;
	public:
		Scoreboard();
		~Scoreboard();
		void drawScore(GLint scoreP1, GLint scoreP2);
};

#endif
