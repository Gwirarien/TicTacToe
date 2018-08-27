#pragma once

class State 
{
public:
	virtual void initializeState() = 0;
	virtual void inputHandler() = 0;
	virtual void update() = 0;
	virtual void draw(double deltaFrames) = 0;
	virtual void pauseGame() {}
	virtual void resumeGame() {}
};