#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();
	// we can override this upon in heritence to define other gameobject types
	virtual char* GetType() const { return "GameObject"; }
	virtual void Draw() {};
	void IncreaseScale() 
	{ scaleZ *= 1.01; }
	float GetScale() { return scaleZ; }
	void SetScale(float _val) { scaleZ = _val; }

protected:
	float scaleZ;
};

#endif