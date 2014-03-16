#include "HUD.h"

HUD::HUD(void)
{
	hudFont = (long)GLUT_BITMAP_8_BY_13;
}

void HUD::Draw(int _stage)
{
	WriteData(_stage);
	DrawWeapons();
}

void HUD::DrawWeapons()
{
	std::cout << "hud draw\n";
	glColor3f(0.0, 0.8, 0.0);
	for (int i = 0; i < 2; i++)
	{
		glPushMatrix();
		glTranslatef(100, 50, -2);
		glBegin(GL_LINE_STRIP);
			glVertex3f(4, 6, 2);
			glVertex3f(0, 3, 0);
			glVertex3f(0, 2, 0);
			glVertex3f(4, 0, 2);
		glEnd();
		glPopMatrix();
	}	
}
// routine to draw a bitmap character string
void HUD::WriteBitmapString(void *font, char *string)
{  
   char *c;
   for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}
// routine to onvert floating point to char string
void HUD::FloatToString(char * destStr, int precision, int val) 
{
   sprintf(destStr,"%d",val);
   destStr[precision] = '\0';
}
// write standard text for ui elements
void HUD::WriteData(int _stage)
{
	glRasterPos3f(GLUT_SCREEN_WIDTH - 50, GLUT_SCREEN_HEIGHT - 6, -1);
	WriteBitmapString((void*)hudFont, "SCORE: ");
	/*	floatToString(hudStringBuffer, 8, playerScore->GetScore());
		glRasterPos3f(screenWidth - 50, screenHeight - 6, 0);
		writeBitmapString((void*)font, "SCORE: ");
		writeBitmapString((void*)font, theStringBuffer);*/
}
HUD::~HUD(void)
{
}
