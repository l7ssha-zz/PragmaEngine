#pragma once

#include <PragmaEngine/SpriteBatch.h>
#include "Ball.h"

class BallRenderer {
public:
	void renderBall(PragmaEngine::SpriteBatch& spriteBatch, Ball& ball);
};
