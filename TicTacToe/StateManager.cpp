#include "stdafx.h"
#include "StateMachine.h"

/**
* StateMachine::addState
* Adds a new state onto the stack, also replaces the old one
* @param StateReference newState
* @param bool isReplacing
* #return void
*/
void StateMachine::addState(StateReference newState, bool isReplacing)
{
	this->_isAdding = true;
	this->_isReplacing = true;
	this->_newState = std::move(newState);
}

/**
* StateMachine::removeState
* Manually remove the state
* @param none
* #return void
*/
void StateMachine::removeState()
{
	this->_isRemoving = true;
}

/**
* StateMachine::processStateChanges
* Handles the changes of the state
* @param none
* #return void
*/
void StateMachine::processStateChanges()
{
	//If there are states and removing is set to true
	if (this->_isRemoving && !this->_states.empty())
	{
		//Remove the state
		this->_states.pop();

		//If there are any states left
		if(!this->_states.empty())
		{
			//Bring the state to the top of the stack
			this->_states.top()->resumeGame();
		}

		this->_isRemoving = false;
	}

	//If a state is wanted to be added
	if (this->_isAdding)
	{
		//Check if the state is empty
		if (!this->_states.empty())
		{
			//If it's replacing, pop the current state
			if (this->_isReplacing)
			{
				this->_states.pop();
			} 
			else
			{
				this->_states.top()->pauseGame();
			}
		}

		//Initialize and run state
		this->_states.push(std::move(this->_newState));
		this->_states.top()->initializeState();
		this->_isAdding = false;
	}
}

/**
* StateMachine::processStateChanges
* Handle the get active state method
* @param none
* #return void
*/
StateReference &StateMachine::getActiveState()
{
	//Only the top state matter because is the active state
	return this->_states.top();
}