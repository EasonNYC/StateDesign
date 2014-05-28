//#pragma once

#ifndef GAMEENGINE_H
#define GAMEENGINE_H



#include <vector>
#include <string>
#include "GameState.h"
using namespace std;

//make singleton
class GameState; //it doesnt know what this is, but needs to call a member function of it in handle events. needs to be fixed. using include
class GameEngine
{
public:
	void Init();
	void Cleanup();

	void ChangeState(GameState* state);
	void PushState(GameState* state);
	void PopState();

	void HandleEvents();
	void Update();
	void Draw();

	bool Running() { return m_running; }
	void Quit() { m_running = false; }

	//constructor
	GameEngine()
		
	{
	}

private:
	// the stack of states
	vector<GameState*> states;

	bool m_running;

	//friend void GameState::ChangeState(GameEngine* game, GameState* state);

};

#endif
