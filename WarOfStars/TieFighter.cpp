#include "TieFighter.h"


TieFighter::TieFighter(float x, float y, float z)
{
	positionX = x;
	positionY = y;
	positionZ = z;
}

void TieFighter::Draw()
{
	glPushMatrix();
	glTranslatef(positionX, positionY, positionZ);
	glColor3f(0.0, 1.0, 0.0);
	glutWireCube(2.0);
	glPopMatrix();
}

TieFighter::~TieFighter(void)
{
}
