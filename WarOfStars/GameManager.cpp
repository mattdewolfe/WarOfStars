#include "GameManager.h"

GameManager::GameManager()
{
	gameState = PLAY_GAME;
	stage = SURFACE_STAGE;
	playerX = 0;
	playerY = 0;
	zTime = -1.0f;
	moveUp = false;
	moveDown = false;
	moveLeft = false;
	moveRight = false;
	fireWeapon = false;
	stageBoundaries[FIGHTERS_STAGE][0] = 300;
	stageBoundaries[FIGHTERS_STAGE][1] = 150;
	stageBoundaries[SURFACE_STAGE][0] = 200;
	stageBoundaries[SURFACE_STAGE][1] = 150;
	stageBoundaries[TRENCH_STAGE][0] = 100;
	stageBoundaries[TRENCH_STAGE][1] = 150;
}
// main draw statement here - switch based on gamestate and draw elements as needed
void GameManager::DrawVisuals()
{
	CheckFlags();
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
		glPushMatrix();	
			glTranslatef(playerX, playerY, zTime);
			objectFactory.DrawAll();
		glPopMatrix();
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
// check movement flags and change values as needed
void GameManager::CheckFlags()
{
	if (moveLeft == true && playerX > 0)
	{
		playerX -= 1.0f;
	}
	if (moveRight == true && playerX < stageBoundaries[stage][0])
	{
		playerX += 1.0f;
	}
	if (moveDown == true && playerY > 0)
	{
		playerY -= 1.0f;
	}
	if (moveUp == true && playerY < stageBoundaries[stage][0])
	{
		playerY += 1.0f;
	}
}
// tell object factory to setup next stage
void GameManager::SetupStage(STAGE _nextStage)
{
	switch (_nextStage)
	{
	case FIGHTERS_STAGE:
		// objectFactory.SetupFighterStage();
		break;
	case SURFACE_STAGE:
		// objectFactory.SetupSurfaceStage();
		break;
	case TRENCH_STAGE:
		// objectFactory.SetupTrenchStage();
		break;
	}
}
GameManager::~GameManager()
{

}


