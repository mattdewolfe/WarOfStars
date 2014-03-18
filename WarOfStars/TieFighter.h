#ifndef TIE_FIGHTER_H
#define TIE_FIGHTER_H

#include "GameObject.h"
#include "openGL\glut.h"

class TieFighter :
	public GameObject
{
public:
	TieFighter(float x, float y, float z);
	virtual ~TieFighter(void);
	// return object type (as char)
	char* GetType() const { return "TieFighter"; }
	// visuals
	void Draw();
private:
	float positionX, positionY, positionZ;

};

#endif