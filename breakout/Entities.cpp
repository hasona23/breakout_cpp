#include "Entities.hpp"

Entity::Entity(int id, std::string name)
{
	Id = id;
	Name = name;
	Pos = { 0,0 };
	Vel = { 0,0 };
	Size = { 0,0 };
}
void Entity::Update(float dt)
{
	Pos.x += Vel.x * dt;
	Pos.y += Vel.y * dt;
	
	if (Pos.x < 0)
	{
		Pos.x = 0;
		if(BounceOnWalls)
			Vel.x *= -1;
	}
	else if (Pos.x + Size.x > 800) // Assuming screen width is 800
	{
		Pos.x = 800 - Size.x;
		if(BounceOnWalls)
			Vel.x *= -1;
	}
	if (Pos.y < 0)
	{
		Pos.y = 0;
		if(BounceOnWalls)
			Vel.y *= -1;
	}
	else if (Pos.y + Size.y > 600) // Assuming screen height is 600
	{
		Pos.y = 600 - Size.y;
		if(BounceOnWalls)
			Vel.y *= -1;
	}
}
void Entity::Draw()
{
	DrawRectangleV(Pos,Size,RED);
}
