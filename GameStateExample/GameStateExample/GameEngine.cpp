#include "GameState.h"
#include "GameEngine.h"
//include in this order

void GameEngine::Init(){
	m_running = true; //turn on the game
}

void GameEngine::ChangeState(GameState* state){
	// cleanup the current state
	if (!states.empty()) {
		//states.back()->Cleanup();
		states.pop_back();
	}

	// store and init the new state
	states.push_back(state);
	//states.back()->Init();

}

void GameEngine::HandleEvents()
{
	// let the state handle events
	//states.back()->HandleEvents(this);
	if (!states.empty()) {
		states.back()->HandleEvents(this);
	}
	//GameState temp = states.back();
	//states.pop_back();
}

void GameEngine::Update()
{
	// let the state update the game
	//states.back()->Update(this);
}

void GameEngine::Draw()
{
	// let the state draw the screen
	states.back()->Draw(this);
}

