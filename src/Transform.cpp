#include "Transform.h"

LilyTin::Transform::Transform()
{
}

LilyTin::Transform::~Transform()
{
}

float LilyTin::Transform::getX()
{
	return mX;
}

float LilyTin::Transform::getY()
{
	return mY;
}

float LilyTin::Transform::getWidth()
{
	return mWidth;
}

float LilyTin::Transform::getHeight()
{
	return mHeight;
}

float LilyTin::Transform::getAngle()
{
	return mAngle;
}

void LilyTin::Transform::setAngle(const float& angle)
{
	mAngle = angle;
}
