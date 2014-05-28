/*
Code written and maintained by Eason Smith (davideasonsmith@gmail.com) 
This code has been adapted from http://gamedevgeek.com/tutorials/managing-game-states-in-c/

BRIEF DESCRIPTION: This code serves as a working example of the State Design Pattern. It is intended to be used as a starting point 
which can be changed for use in future projects. 
*/

#include<iostream>
#include "GameState.h"
#include "GameEngine.h"


//#include <string>
using namespace std;


int main(){

	GameEngine game;
	
	// initialize the engine
	game.Init();

	// load the intro
	game.ChangeState( &MenuState::Instance() );
	
	// main loop
	while (game.Running())
	{
		game.HandleEvents();
		game.Update();
		game.Draw();
	}

	// cleanup the engine
	//game.Cleanup();

	
}