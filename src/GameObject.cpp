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

const sf::FloatRect& LilyTin::GameObject::getBoundingBox() const
{
	return mBoundingBox;
}