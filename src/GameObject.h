#pragma once

namespace LilyTin
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		virtual void update() = 0;
		virtual void render() = 0;

	private:
		bool mDestroyed = false;

	};
}