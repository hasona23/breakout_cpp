#include "Zap.hpp"
#include "../Data.hpp"
#include <string>
#include <format>
class Player : public Zap::Entity
{
public:
	Player() : Zap::Entity(0, "Player")
	{
		Size = Vector2{ PLAYER_SIZE_X,PLAYER_SIZE_Y };
		Vel = Velocity(PLAYER_SPEED);
	}
	
	void Update(float dt) override
	{
		Vel.Dir = Vector2Zero();
		if (IsKeyDown(KEY_D))
		{
			Vel.Dir.x += 1;
		}
		if (IsKeyDown(KEY_A))
		{
			Vel.Dir.x -= 1;
		}
		if (IsKeyDown(KEY_W))
		{
			Vel.Dir.y -= 1;
		}
		if (IsKeyDown(KEY_S))
		{
			Vel.Dir.y += 1;
		}
		Pos += Vel.GetVelocityNormalized(dt);
		 
	}
	void Draw() override 
	{
		
		DrawRectangleV(Pos, Size, BLUE);
	}
	
};