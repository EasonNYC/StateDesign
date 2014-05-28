#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "GameEngine.h"

//virtual class to inherit states from
class GameEngine; //fwd declare
class GameState
{
public:
	//all game states must define these 7 functions
	virtual void Init() = 0;
	virtual void Cleanup() = 0;
	virtual void Pause() = 0;
	virtual void Resume() = 0;
	virtual void HandleEvents(GameEngine* game) = 0;
	virtual void Update(GameEngine* game) = 0;
	virtual void Draw(GameEngine* game) = 0;

	//function to have state change to another state
	void ChangeState(GameEngine* game, GameState* state) {
		game->ChangeState(state);
	}


};

class MenuState : public GameState
{

private:
	static MenuState singleton;

	// Dont forget to declare these two. You want to make sure they
	// are unaccessable otherwise you may accidently get copies of
	// your singleton appearing.
	//S(S const&);              // Don't Implement
	//void operator=(S const&); // Don't implement

	char option;

public:
	void Init();
	void Cleanup();
	void Pause();
	void Resume();
	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);

	//returns a singleton object
	static MenuState& Instance(){
		static MenuState instance;
		return instance;
	}



	~MenuState();

protected:
	MenuState(){}



};

class PlayState : public GameState
{
private:
	char option;
public:

	void Init();
	void Cleanup();
	void Pause();
	void Resume();
	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);

	//returns a singleton object
	static PlayState& Instance(){
		static PlayState instance;
		return instance;
	}
	
	~PlayState();

protected:

	PlayState();
	static PlayState singleton;

};


class OptionState : public GameState
{

private:
	static OptionState singleton;
	char option;
	// Dont forget to declare these two. You want to make sure they
	// are unaccessable otherwise you may accidently get copies of
	// your singleton appearing.
	//S(S const&);              // Don't Implement
	//void operator=(S const&); // Don't implement

	
public:
	void Init();
	void Cleanup();
	void Pause();
	void Resume();
	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);

	//returns a singleton object
	static OptionState& Instance(){
		static OptionState instance;
		return instance;
	}



	~OptionState();

protected:
	OptionState();



};


#endif