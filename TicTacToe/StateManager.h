#pragma once

#include <memory>
#include <stack>
#include "Definitions.h"
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
	bool _isRemoving = false;
	bool _isAdding = false;
	bool _isReplacing = false;
	std::stack<StateReference> _states;
	StateReference _newState;
};

