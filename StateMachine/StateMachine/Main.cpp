#include "StateMachineEngine.h"

int main() {

	StateMachineEngine *engine = new StateMachineEngine();
	while (true) {

		engine->DisplayCurrentState();
		engine->ChangeState();

	}
	
	delete engine;
	return 0;
}