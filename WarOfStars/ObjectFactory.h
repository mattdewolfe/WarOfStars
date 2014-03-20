#ifndef OBJECT FACTORY_H
#define OBJECT_FACTORY_H
#include <vector>
#include "openGL\glut.h"
#include "GameObject.h"
#include "VisualObject.h"

// #include "TieFighter.h"
// #include "Tower.h"
class ObjectFactory
{
private:
	GameObject *objects[20];
	int toDestroy;
	int objectSize;

public:
	ObjectFactory() 
	{
		toDestroy = -1;
		objectSize = 0;
	}
	// add an object to the list
	void AddObject(GameObject *_newObject)
	{
		objects[objectSize] = _newObject;
		objectSize++;
	}
	// draw all objects
	void DrawAll()
	{
		for (int i = 0; i < objectSize; i++)
		{
			if (objects[i] != nullptr)
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
				if (objects[i]->GetScale() > 8)
				{
					DestroyAndRepack(i);
				}
			}
		}
	}
	// destroy target object and repacj array
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
	// remove an object
/*	void RemoveObject(GameObject _deleteObject)
	{
		int i;
		for (i = 0; i < objects.size(); i++)
		{
			if (_deleteObject.GetID() == objects[i].GetID())
				break;
		}
		objects.erase(objects.begin() + i);
		objectSize--;
	}*/
	// load objects for fighter stage
	void SetupFighterStage()
	{

	}
	// load objects for surface stage
	void SetupSurfaceStage()
	{

	}
	// load objects for trench stage
	void SetupTrenchStage()
	{

	}
	virtual ~ObjectFactory(void) {}

};

#endif
