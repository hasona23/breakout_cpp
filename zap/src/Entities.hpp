#pragma once

#include <string>
#include "raylib.h"
#include "Components.hpp"
namespace Zap 
{

	class Entity
	{
	public:
		int Id;
		std::string Name;
		Vector2 Pos;
		Velocity Vel;
		Vector2 Size;

		bool BounceOnWalls = false;
		Entity(int id, std::string name = "");

		virtual void Update(float dt) = 0;
		virtual void Draw() = 0;

		Rectangle GetBounds() { return Rectangle{ Pos.x, Pos.y, Size.x, Size.y }; }
		bool CheckCollision(Entity& other)
		{
			Rectangle a = GetBounds();
			Rectangle b = other.GetBounds();
			return CheckCollisionRecs(a, b);
		}
	};

}