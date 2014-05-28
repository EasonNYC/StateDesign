#include "GameState.h"
#include "GameEngine.h"
//#include "functions.cpp"
#include <iostream>
#include <string>
using std::cout;
//include in this order

/////MENU STATE

MenuState MenuState::singleton;

void MenuState::Init(){}
void MenuState::Cleanup(){}
void MenuState::Pause(){}
void MenuState::Resume(){}
void MenuState::HandleEvents(GameEngine* game){ 
	//main logic goes in here
	
	if (option == 'a'){
		game->ChangeState(&PlayState::Instance());
	}
	else if(option == 'b'){
		game->ChangeState(&OptionState::Instance());
	}
}
void MenuState::Update(GameEngine* game){}
void MenuState::Draw(GameEngine* game){
	
	cout << "this is the menu." << endl << endl;

	cout << "choose a state" << endl << endl;

	cout << "a) play  " << "b) option" << endl;

	cin >> option;



}

MenuState::~MenuState()
{
}
//// PLAY STATE

PlayState PlayState::singleton;


void PlayState::Init(){}
void PlayState::Cleanup(){}
void PlayState::Pause(){}
void PlayState::Resume(){}
void PlayState::HandleEvents(GameEngine* game){

	if (option == 'a'){
		game->ChangeState(&MenuState::Instance());
	}
	else if (option == 'b'){
		game->ChangeState(&OptionState::Instance());
	}

}
void PlayState::Update(GameEngine* game){}
void PlayState::Draw(GameEngine* game){
	//ClearScreen();

	cout << "this is the play state." << endl << endl;

	cout << "choose a state" << endl << endl;

	cout << "a) menu  " << "b) options" << endl;

	cin >> option;

}

PlayState::PlayState()
{
}
PlayState::~PlayState()
{
}

//option state
OptionState OptionState::singleton;


void OptionState::Init(){}
void OptionState::Cleanup(){}
void OptionState::Pause(){}
void OptionState::Resume(){}
void OptionState::HandleEvents(GameEngine* game){

	if (option == 'a'){
		game->ChangeState(&MenuState::Instance());
	}
	else if (option == 'b'){
		game->ChangeState(&PlayState::Instance());
	}

}
void OptionState::Update(GameEngine* game){}
void OptionState::Draw(GameEngine* game){

	cout << "this is the options screen." << endl << endl;

	cout << "choose a state" << endl << endl;

	cout << "a) menu  " << "b) play game" << endl;

	cin >> option;

}

OptionState::OptionState()
{
}


OptionState::~OptionState()
{
}






