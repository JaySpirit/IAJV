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

std::vector<string> directionArray;

struct Params {
	MoveStateMachine actualAction;
	MoveStateMachine previousAction;
	char actualDirection;
	char previousDirection;
};

int main() {

	MoveStateMachine currentMoveState = WAIT;
	DirectionStateMachine currentDirectionState = EXIT;

	Params params;
	params.actualDirection = ' ';

	bool isAnystate = false;
	bool valideInput = true;

	//For display feature
	directionArray.push_back("forward");
	directionArray.push_back("backward");
	directionArray.push_back("to the left");
	directionArray.push_back("to the right");


	while (true) {

		//Main state machine
		switch (currentMoveState) {
		case WAIT:
			std::cout << "You're waiting, but..." << endl;
			break;

		case WALK:
			
			switch (params.actualDirection) {
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
			
			switch (params.actualDirection) {
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

		params.previousDirection = params.actualDirection;
		
		if (!isAnystate) {
			std::cout << "<<<<<--- Waiting for a action... --->>>>>" << endl;

			std::cin >> params.actualDirection;

			if (params.actualDirection == 'j' || params.actualDirection == 'J') {
				currentMoveState = ANYSTATE;
			}
			else {
				if (params.previousDirection == params.actualDirection) {
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
	return 0;
}