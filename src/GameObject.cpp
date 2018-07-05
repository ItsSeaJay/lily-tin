#include "GameObject.h"

LilyTin::GameObject::GameObject()
{
}

LilyTin::GameObject::~GameObject()
{
}

sf::Transformable& LilyTin::GameObject::getTransform()
{
	return mTransform;
}