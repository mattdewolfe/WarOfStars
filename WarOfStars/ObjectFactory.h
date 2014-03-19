#ifndef OBJECT FACTORY_H
#define OBJECT_FACTORY_H
#include <vector>
#include "openGL\glut.h"
#include "GameObject.h"

// #include "TieFighter.h"
// #include "Tower.h"
class ObjectFactory
{
private:
	std::vector<GameObject> objects;

public:
	ObjectFactory(void) {}
	// add an object to the list
	void AddObject(GameObject _newObject)
	{
		objects.push_back(_newObject);
	}
	// draw all objects
	void DrawAll()
	{
		for (std::vector<GameObject>::iterator it = objects.begin(); it != objects.end(); it++)
		{
			it->Draw();
		}
		glColor3f(0.8, 0.0, 0.0);
		glBegin(GL_TRIANGLE_STRIP);
			glVertex3f(5.0, 5.0, -4);
			glVertex3f(10.0, 5.0, -4);
			glVertex3f(5.0, 10.0, -4);
		glEnd();
	}
	// remove an object
	void RemoveObject(GameObject _deleteObject)
	{
		int i;
		for (i = 0; i < objects.size(); i++)
		{
			if (_deleteObject.GetID() == objects[i].GetID())
				break;
		}
		objects.erase(objects.begin() + i);
	}
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
