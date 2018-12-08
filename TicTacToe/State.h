#pragma once

#include "Definitions.h"

class State
{
public:
	virtual void initializeState() = 0;
	virtual void inputHandler() = 0;
	virtual void update(double deltaFrames) = 0;
	virtual void draw(double deltaFrames) = 0;
	virtual void pauseGame() {}
	virtual void resumeGame() {}
};