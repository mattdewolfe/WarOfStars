#ifndef OBJECT FACTORY_H
#define OBJECT_FACTORY_H
#include <vector>
#include "openGL\glut.h"
#include "GameObject.h"
#include "VisualObject.h"
#include "Tower.h"

// #include "TieFighter.h"
class ObjectFactory
{
private:
	GameObject *objects[20];
	int objectSize;

public:
	ObjectFactory() 
	{
		objectSize = 0;
	}
	// add an object to the list
	void AddObject(GameObject *_newObject)
	{
		if (objectSize == -1)
			objectSize = 0;
		objects[objectSize] = _newObject;
		objectSize++;
	}
	// draw all objects
	void DrawAll()
	{
		for (int i = 0; i < objectSize; i++)
		{
			if (objects[i] != nullptr && objects[i]->GetScale() > 0)
				objects[i]->Draw();
		}
	}
	void Update()
	{
		for (int i = 0; i < objectSize; i++)
		{
			if (objects[i] != nullptr)
			{
				objects[i]->IncreaseScale();
				if (objects[i]->GetScale() > 30)
				{
					DestroyAndRepack(i);
				}
			}
		}
	}
	// destroy target object and repack array
	void DestroyAndRepack(int _index)
	{
		GameObject *backup[20];
		for (int i = _index; i < objectSize; i++)
		{
			backup[i] = objects[i];
		}
		for (int i = _index; i < objectSize; i++)
		{
			if (backup[i + 1] == nullptr)
				break;
			else
				objects[i] = backup[i + 1];
		}
		objects[objectSize] = nullptr;
		objectSize--;
	}
	// load objects for fighter stage
	void SetupFighterStage()
	{

	}
	// load objects for surface stage
	void SetupSurfaceStage()
	{
		AddObject(new Tower(0, 0, 1));
		AddObject(new Tower(40, 0, 2));
		AddObject(new Tower(60, 0, 3));
		AddObject(new Tower(80, 0, 6));
		AddObject(new Tower(110, 0, 3));
		AddObject(new Tower(130, 0, 5));
		AddObject(new Tower(150, 0, 1));
		AddObject(new Tower(170, 0, 5));
	}
	// load objects for trench stage
	void SetupTrenchStage()
	{
		
	}
	virtual ~ObjectFactory(void) {}

};

#endif
