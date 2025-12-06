#include "raylib.h"
#include "raymath.h"
struct Velocity
{
public:
	Vector2 Dir;
	float Speed;
	Velocity() 
	{
		Dir = Vector2Zero();
		Speed = 0.0f;
	};
	Velocity(float speed) 
	{
		Dir = Vector2Zero();
		Speed = speed;
	};
	Velocity(Vector2 dir, float speed)
	{
		Dir = dir;
		Speed = speed;
	}

	Vector2 GetVelocity(float multiplier = 1) const
	{
		return Vector2Scale(Dir, Speed * multiplier);
	};
	Vector2 GetVelocityNormalized(float multiplier = 1) const
	{
		return Vector2Scale(Vector2Normalize(Dir), Speed * multiplier);
	};
};


struct Sprite
{
	
};