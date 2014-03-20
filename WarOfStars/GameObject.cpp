#include "GameObject.h"

unsigned int GameObject::ID_INDEX = 0;

GameObject::GameObject()
{
	m_ID = ID_INDEX;
	ID_INDEX++;
}


GameObject::~GameObject()
{
}
