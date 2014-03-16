#ifndef OBJECT FACTORY_H
#define OBJECT_FACTORY_H
#include <vector>
#include "GameObject.h"

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
	virtual ~ObjectFactory(void) {}

};

#endif
