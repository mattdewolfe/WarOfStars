#ifndef STATICOBJECT_H
#define STATICOBJECT_H
#include "GameObject.h"

class StaticObject : public GameObject
{
public:
	StaticObject(void);
	virtual void Draw() = 0;
	virtual ~StaticObject(void);
};

#endif
