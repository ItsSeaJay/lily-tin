#pragma once

namespace LilyTin
{
	class Transform
	{
	public:
		Transform();
		~Transform();
	
		float getX();
		float getY();
		float getWidth();
		float getHeight();
		float getAngle();
		void setAngle(const float& angle);

	private:
		float mX;
		float mY;
		float mWidth;
		float mHeight;
		float mAngle;

	};
}