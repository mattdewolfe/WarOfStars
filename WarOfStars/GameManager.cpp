#include "GameManager.h"

GameManager::GameManager()
{
	gameState = MAIN_MENU;
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
#pragma region MainMenuVisuals
	case MAIN_MENU:
		glPushMatrix();
			visText.SetColorFloatRGB(1.0, 0.0, 0.0);
			visText.ReSizeFont(19);
			visText.WriteBitmapString(6, 150, "War of Stars");
			visText.SetColorFloatRGB(1.0, 1.0, 1.0);
			visText.WriteBitmapString(6, 148, "War of Stars");
			visText.ReSizeFont(7);
			visText.SetColorFloatRGB(0.8, 0.8, 0.8);
			visText.WriteBitmapString(30, 75, "Assualt the death star!");
			visText.WriteBitmapString(35, 50, "I need information...");
			visText.WriteBitmapString(75, 25, "I quit");
			visText.SetColorFloatRGB(1.0, 0.0, 0.0);
			visText.WriteBitmapString(30, 74, "Assualt the death star!");
			visText.WriteBitmapString(35, 49, "I need information...");
			visText.WriteBitmapString(75, 24, "I quit");
			glColor3f(0.0, 0.8, 0.1);
			glLineWidth(2.0);
			glBegin(GL_LINE_STRIP);
			glVertex3f(25, 71, -4);
			glVertex3f(170, 71, -4);
			glVertex3f(170, 86, -4);
			glVertex3f(25, 86, -4);
			glVertex3f(25, 71, -4);
			glEnd();
			glBegin(GL_LINE_STRIP);
			glVertex3f(25, 46, -4);
			glVertex3f(170, 46, -4);
			glVertex3f(170, 61, -4);
			glVertex3f(25, 61, -4);
			glVertex3f(25, 46, -4);
			glEnd();
			glBegin(GL_LINE_STRIP);
			glVertex3f(70, 22, -4);
			glVertex3f(115, 22, -4);
			glVertex3f(115, 36, -4);
			glVertex3f(70, 36, -4);
			glVertex3f(70, 22, -4);
			glEnd();
			glLineWidth(1.0);
		glPopMatrix();
		break;
#pragma endregion MainMenuVisuals
	case START_GAME:
		break;
	case START_WAVE:
		hud.Draw();
		break;
	case PLAY_GAME:
		hud.Draw();
		glPushMatrix();	
			glTranslatef(playerX, playerY, zTime);
			objectFactory.DrawAll();
		glPopMatrix();
		break;
	case PLAYER_KILLED:
		hud.Draw();
		break;
	case CHANGE_STAGE:
		hud.Draw();
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
// increments game logic/state
void GameManager::Update()
{
	zTime += 0.01f;
}
GameManager::~GameManager()
{

}


