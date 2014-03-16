#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	unsigned int GetID() const { return m_ID; }
	// We can override this upon in heritence to define other gameobject types
	virtual char* GetType() const { return "GameObject"; }
	virtual void Draw() {};

private:
	// Best means of generating unique ID's is using gettime
	// along with some bit shifting
	unsigned int m_ID;
	// This variable is our hack way of generating ID's
	static unsigned int ID_INDEX;
};

#endif