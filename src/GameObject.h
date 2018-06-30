#pragma once

namespace LilyTin
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

	private:
		bool mDestroyed = false;
	};
}