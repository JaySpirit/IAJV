#include "StateMachineEngine.h"

int main() {

	StateMachineEngine engine;
	while (true) {

		engine.DisplayCurrentState();
		engine.ChangeState();

	}
	return 0;
}