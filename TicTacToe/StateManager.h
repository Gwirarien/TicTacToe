#pragma once

#include <memory>
#include <stack>
#include "State.h"

typedef std::unique_ptr<State> StateReference;

class StateMachine
{
public:
	StateMachine() {}
	~StateMachine() {}

	void addState(StateReference newState, bool isReplacing = true);
	void removeState();
	void processStateChanges();
	StateReference &getActiveState();

private:
	bool _isRemoving;
	bool _isAdding;
	bool _isReplacing;
	std::stack<StateReference> _states;
	StateReference _newState;
};

