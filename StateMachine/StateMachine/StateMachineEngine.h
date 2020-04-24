#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum MoveStateMachine {
	WAIT, WALK, RUN, JUMP, ANYSTATE
};

enum DirectionStateMachine {
	FORWARD, BACKWARD, LEFT, RIGHT, EXIT
};

class StateMachineEngine {
public:

	//Params
	char actualDirection;
	char previousDirection;
	MoveStateMachine currentMoveState;
	DirectionStateMachine currentDirectionState;

	//Functions
	StateMachineEngine();
	void DisplayCurrentState();
	void ChangeState();
};