#include "GameManager.h"

GameManager::GameManager()
{
	gameState = PLAY_GAME;
	stage = SURFACE_STAGE;
}


// main draw statement here - switch based on gamestate and draw elements as needed
void GameManager::DrawVisuals()
{
	switch(gameState)
	{
	case MAIN_MENU:
		break;
	case START_GAME:
		break;
	case START_WAVE:
		hud.Draw(stage);
		break;
	case PLAY_GAME:
		hud.Draw(stage);
		objectFactory.DrawAll();
		break;
	case PLAYER_KILLED:
		hud.Draw(stage);
		break;
	case CHANGE_STAGE:
		hud.Draw(stage);
		break;
	case WAVE_OVER:
		break;
	case GAME_OVER:
		break;
	}
}

// check if the wave is over, will move to next stage and return false if it is not
bool GameManager::IsWaveOver()
{
	// if player just completed trench stage, reset to fighters stage and return true as the wave is over
	if (stage == TRENCH_STAGE)
	{
		gameState = WAVE_OVER;
		stage = FIGHTERS_STAGE;
		return true;
	}
	// if the player just beat the fighters, move to surface stage and return false
	else if (stage == FIGHTERS_STAGE)
	{
		stage = SURFACE_STAGE;
		return false;
	}
	// if the player just beat the surface, move to trench and return false
	else if (stage == SURFACE_STAGE)
	{
		stage = TRENCH_STAGE;
		return false;
	}
	return false;
}
GameManager::~GameManager()
{

}


