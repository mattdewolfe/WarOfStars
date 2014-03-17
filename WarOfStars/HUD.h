#ifndef HUD_H
#define HUD_H
#include <stdlib.h>
#include <iostream>
#include "openGL\glut.h"

class HUD
{
public:
	HUD(void);
	// draw the hud based on the current stage
	void Draw(int _stage);
	virtual ~HUD(void);
private:
	long hudFont; // font selection
	char hudStringBuffer[10]; // string buffer
	void DrawWeapons();
	void HUD::WriteBitmapString(void *font, char *string);
	void HUD::FloatToString(char * destStr, int precision, int val);
	void HUD::WriteData(int _stage);
};

#endif

