#include "StateMachineEngine.h"


StateMachineEngine::StateMachineEngine()
{
	this->actualDirection = ' ';
	this->currentMoveState = WAIT;
	this->currentDirectionState = EXIT;
}

StateMachineEngine::~StateMachineEngine()
{
}

//Booleans used in both functions
bool isAnystate = false;
bool valideInput = true;

void StateMachineEngine::DisplayCurrentState()
{
	//List of strings for direction display
	std::vector<string> directionArray;
	directionArray.push_back("forward");
	directionArray.push_back("backward");
	directionArray.push_back("to the left");
	directionArray.push_back("to the right");

	switch (currentMoveState) {
	case WAIT:
		std::cout << "You're waiting, but..." << endl;
		break;

	case WALK:

		switch (this->actualDirection) {
		case 'Z':
		case 'z':
			currentDirectionState = FORWARD;
			break;
		case 'S':
		case 's':
			currentDirectionState = BACKWARD;
			break;
		case 'Q':
		case 'q':
			currentDirectionState = LEFT;
			break;
		case 'D':
		case 'd':
			currentDirectionState = RIGHT;
			break;
		default:
			std::cout << "No valid input" << endl;
			valideInput = false;
			break;
		}

		if (valideInput) {
			std::cout << "You're walking ";
		}

		break;
	case RUN:

		switch (this->actualDirection) {
		case 'Z':
		case 'z':
			currentDirectionState = FORWARD;
			break;
		case 'S':
		case 's':
			currentDirectionState = BACKWARD;
			break;
		case 'Q':
		case 'q':
			currentDirectionState = LEFT;
			break;
		case 'D':
		case 'd':
			currentDirectionState = RIGHT;
			break;
		default:
			std::cout << "No valid input" << endl;
			valideInput = false;
			break;
		}

		if (valideInput) {
			std::cout << "You're running ";
		}

		break;
	case JUMP:
		std::cout << "You're jumping" << endl;
		break;
	case ANYSTATE:
		std::cout << "ANYSTATE" << endl;
		currentMoveState = JUMP;
		isAnystate = true;
		break;
	default:
		cout << "Error! Invalid State Detected." << endl;
		break;
	}

	if (!isAnystate && currentMoveState == WALK || currentMoveState == RUN) {
		while (currentDirectionState != EXIT) {

			//Sub state machine
			switch (currentDirectionState) {
			case FORWARD:
				std::cout << directionArray[0] << endl;
				break;
			case BACKWARD:
				std::cout << directionArray[1] << endl;
				break;
			case LEFT:
				std::cout << directionArray[2] << endl;
				break;
			case RIGHT:
				std::cout << directionArray[3] << endl;
				break;
			default:
				break;
			}
			currentDirectionState = EXIT;

		}
	}
}

void StateMachineEngine::ChangeState()
{
	//Stock the previous direction
	this->previousDirection = this->actualDirection;

	if (!isAnystate) {
		std::cout << "<<<<<--- Waiting for a action... --->>>>>" << endl;

		std::cin >> this->actualDirection;

		if (this->actualDirection == 'j' || this->actualDirection == 'J') {
			currentMoveState = ANYSTATE;
		}
		else {
			if (this->previousDirection == this->actualDirection) {
				currentMoveState = RUN;
			}
			else {
				currentMoveState = WALK;
			}
		}

	}

	valideInput = true;
	isAnystate = false;
}
