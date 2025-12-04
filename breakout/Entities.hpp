#include <string>
#include "raylib.h"
class Entity
{
public:
	int Id;
	std::string Name;
	Vector2 Pos;
	Vector2 Vel;
	Vector2 Size;
	bool BounceOnWalls = false;
	Entity(int id, std::string name = "");

	virtual void Update(float dt);
	virtual void Draw();

	Rectangle GetBounds() { return Rectangle{ Pos.x, Pos.y, Size.x, Size.y }; }
	bool CheckCollision(Entity other)
	{
		Rectangle a = GetBounds();
		Rectangle b = other.GetBounds();
		return CheckCollisionRecs(a, b);
	}
};

