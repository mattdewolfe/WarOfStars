#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "ObjectFactory.h"
#include "HUD.h"

class GameManager
{
public:
	GameManager(void);
	virtual ~GameManager(void);
	
	// game state enum
	enum GAMESTATE 
	{ 
		MAIN_MENU,		// main menu
		START_GAME,		// load resources, start a new game
		START_WAVE,		// reset values as needed, start a new wave
		PLAY_GAME,		// majority of gameplay here - input, collision, ai, etc
		PLAYER_KILLED,	// after the player is killed, move here, check lives, respawn if possible
		CHANGE_STAGE,	// after completing the current stage, trigger and move to next stage (if applicable)
		WAVE_OVER,		// show deathstar explosion, inform player next wave is starting
		GAME_OVER,		// display game over screen, return to main on key press
		STATE_MAX
	};

	enum STAGE
	{
		FIGHTERS_STAGE,	// approaching deathstar, dog fight with fighters
		SURFACE_STAGE,	// moving along surface, towers collidable and shoot at player
		TRENCH_STAGE,	// flying through trench towards exhaust port
		STAGE_MAX
	};
		
	
	// set state of state machine
	void SetState(GAMESTATE _newState) { gameState = _newState; }
	GAMESTATE GetState() { return gameState; }	// get current state of state machine
	STAGE GetStage() { return stage; }			// get the current stage player is in

	// draw visual objects as decided by gamestate
	void DrawVisuals();
	// will return true if the wave is over, else will increment to next stage and return false
	bool IsWaveOver();

private:
	// current state of game logic
	GAMESTATE gameState;
	// the current stage the player is on
	STAGE stage;
	// store all objects in the scene
	ObjectFactory objectFactory;
	// heads up display
	HUD hud;

};

#endif